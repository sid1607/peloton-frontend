//===----------------------------------------------------------------------===//
//
//                         Peloton
//
// wire.h
//
// Identification: src/wire/wire.h
//
// Copyright (c) 2015-16, Carnegie Mellon University Database Group
//
//===----------------------------------------------------------------------===//

#ifndef WIRE_H
#define WIRE_H

#include "socket_base.h"
#include "sqlite.h"
#include <vector>
#include <string>
#include <iostream>
#include <unordered_map>
#include <boost/assign/list_of.hpp>
#include "assert.h"
#include "cache.h"
#include "cache_entry.h"

/* TXN state definitions */
#define BUFFER_INIT_SIZE 100
#define TXN_IDLE 'I'
#define TXN_BLOCK 'T'
#define TXN_FAIL 'E'

namespace peloton {
namespace wire {

typedef std::vector<uchar> PktBuf;

struct Packet;

typedef std::vector<std::unique_ptr<Packet>> ResponseBuffer;

struct Client {
  SocketManager<PktBuf>* sock; // handle to socket manager

  // Authentication details
  std::string dbname;
  std::string user;
  std::unordered_map<std::string, std::string> cmdline_options;

  inline Client(SocketManager<PktBuf>* sock) : sock(sock) {}
};


struct Packet {
  PktBuf buf; //stores packet contents
  size_t len; // size of packet
  size_t ptr; // PktBuf cursor
  uchar msg_type; // header

  // reserve buf's size as maximum packet size
  inline Packet() { reset(); }

  inline void reset() {
    buf.resize(BUFFER_INIT_SIZE);
    buf.shrink_to_fit();
    buf.clear();
    len = ptr = msg_type = 0;
  }
};

class PacketManager {
  Client client;

  // Manage standalone queries
  std::shared_ptr<CacheEntry> unnamed_entry;

  // gloabl txn state
  uchar txn_state;

  // state to mang skipped queries
  bool skipped_stmt_;
  std::string skipped_query_;
  std::string skipped_query_type_;

  wiredb::Sqlite db; // dbhandler to use sqlite

  static const std::unordered_map<std::string, std::string> parameter_status_map;

  /* Note: The responses argument in every subsequent function
   * is used to batch all the generated packets ofr that unit */

  // Generic error protocol packet
  void send_error_response(
      std::vector<std::pair<uchar, std::string>> error_status,
      ResponseBuffer& responses);

  // Sends ready for query packet to the frontend
  void send_ready_for_query(uchar txn_status, ResponseBuffer& responses);

  // Sends the attribute headers required by SELECT queries
  void put_row_desc(std::vector<wiredb::FieldInfoType>& rowdesc, ResponseBuffer& responses);

  // Send each row, one packet at a time, used by SELECT queries
  void send_data_rows(std::vector<wiredb::ResType>& results, int colcount, int &rows_affected,  ResponseBuffer& responses);

  // Used to send a packet that indicates the completion of a query. Also has txn state mgmt
  void complete_command(const std::string& query_type,
                        int rows, ResponseBuffer& responses);

  // Specific response for empty or NULL queries
  void send_empty_query_response(ResponseBuffer& responses);

  /* Helper function used to make hardcoded ParameterStatus('S')
   * packets during startup
   */
  void make_hardcoded_parameter_status(ResponseBuffer& responses, const std::pair<std::string, std::string>& kv);

  /* SQLite doesn't support "SET" and "SHOW" SQL commands.
   * Also, duplicate BEGINs and COMMITs shouldn't be executed.
   * This function helps filtering out the execution for such cases
   */
  bool hardcoded_execute_filter(std::string query_type);

  /* Execute a Simple query protocol message */
  void exec_query_message(Packet *pkt, ResponseBuffer &responses);

  /* Process the PARSE message of the extended query protocol */
  void exec_parse_message(Packet *pkt, ResponseBuffer &responses);

  /* Process the BIND message of the extended query protocol */
  void exec_bind_message(Packet *pkt, ResponseBuffer &responses);

  /* Process the DESCRIBE message of the extended query protocol */
  void exec_describe_message(Packet *pkt, ResponseBuffer &responses);

  /* Process the EXECUTE message of the extended query protocol */
  void exec_execute_message(Packet *pkt, ResponseBuffer &response, ThreadGlobals& globals);

  /* closes the socket connection with the client */
  void close_client();

 public:

  inline PacketManager(SocketManager<PktBuf>* sock) :
      client(sock), txn_state(TXN_IDLE) {}

  /* Startup packet processing logic */
  bool process_startup_packet(Packet* pkt, ResponseBuffer& responses);

  /* Main switch case wrapper to process every packet apart from the startup packet */
  bool process_packet(Packet* pkt, ThreadGlobals &globals, ResponseBuffer& responses);

  /* Protocol manager */
  void manage_packets(ThreadGlobals& globals);
};
}
}

#endif  // WIRE_H
