/* 
 * File:   main.cpp
 * Author: ntduc
 *
 * Created on July 17, 2018, 11:46 AM
 */

#include "Data.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace  ::Thread_Lock_Mutex;

class DataHandler : virtual public DataIf {
 public:
  DataHandler() {
    // Your initialization goes here
  }

  int32_t put(const int32_t user) {
    // Your implementation goes here
    printf("put\n");
  }

  int32_t get(const int32_t uid) {
    // Your implementation goes here
    printf("get\n");
  }

  int32_t update(const int32_t index, const int32_t value) {
    // Your implementation goes here
    printf("update\n");
  }

};

int main(int argc, char **argv) {
  int port = 9090;
  shared_ptr<DataHandler> handler(new DataHandler());
  shared_ptr<TProcessor> processor(new DataProcessor(handler));
  shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
  shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
  shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

  TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
  server.serve();
  return 0;
}

