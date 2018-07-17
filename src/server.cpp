/* 
 * File:   main.cpp
 * Author: ntduc
 *
 * Created on July 17, 2018, 11:46 AM
 */

#include <bits/stdc++.h>

#include "Data.h"
#include <thrift/protocol/TBinaryProtocol.h>
#include <thrift/server/TSimpleServer.h>
#include <thrift/transport/TServerSocket.h>
#include <thrift/transport/TBufferTransports.h>

#include <Poco/Thread.h>
#include <Poco/Mutex.h>
#include <Poco/ThreadPool.h>
#include <Poco/Runnable.h>
#include <smart_ptr/make_shared_array.hpp>
#include <smart_ptr/make_shared_object.hpp>

using namespace ::apache::thrift;
using namespace ::apache::thrift::protocol;
using namespace ::apache::thrift::transport;
using namespace ::apache::thrift::server;

using boost::shared_ptr;

using namespace ::Thread_Lock_Mutex;

int count = 0;

class ObjectData {
private:
    std::string _name;
    Poco::Mutex _mutex;
public: 
    ObjectData(const std::string &name) : _name( name) {
    }

    ObjectData() {
    }
    
    void conflict() {
        this->_mutex.lock();
        count++;
        std::cout << this->_name << " - " << count << std::endl;
        this->_mutex.unlock();
    }

    virtual ~ObjectData() {
        std::cout << "release object Data" << std::endl;
    }
};

std::vector<ObjectData> vData;

class Z_Worker : public Poco::Runnable {
public:

    Z_Worker(const std::string & key, const std::string name) : _key(key), _name(name) {
    }

    Z_Worker(const Z_Worker& other) : _key(other._key), _name(other._name) {
    }

    Z_Worker(std::string name) {
        this->_name = name;
        this->_data = boost::make_shared<ObjectData>(name);
    }

    virtual ~Z_Worker() {
        std::cout << "remove worker" << std::endl;
    }
    
    void run() {
        std::cout << this->_name << " do something...." << std::endl;
        Poco::Thread::sleep(1000);
        this->_data->conflict();
        Poco::Thread::sleep(500);
        std::cout << this->_name << " Done" << std::endl;
    }

private:
    std::string                     _key;
    std::string                     _name;
    boost::shared_ptr<ObjectData>   _data;
};

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

void startServer() {
    int port = 9090;
    shared_ptr<DataHandler> handler(new DataHandler());
    shared_ptr<TProcessor> processor(new DataProcessor(handler));
    shared_ptr<TServerTransport> serverTransport(new TServerSocket(port));
    shared_ptr<TTransportFactory> transportFactory(new TBufferedTransportFactory());
    shared_ptr<TProtocolFactory> protocolFactory(new TBinaryProtocolFactory());

    TSimpleServer server(processor, serverTransport, transportFactory, protocolFactory);
    server.serve();
}

int main(int argc, char **argv) {
//    ObjectData *obj = new ObjectData("asdfasdf");
    
    Z_Worker worker("worker");
    Z_Worker worker1("worker1");
    Z_Worker worker2("worker2");
    
    std::cout << sizeof (worker) << std::endl;
    
    Poco::Thread thread;
    Poco::Thread thread1;
    Poco::Thread thread2;
    
    thread.start(worker);
    thread1.start(worker1);
    thread2.start(worker2);
    
    thread.join();
    thread1.join();
    thread2.join();
    return 0;
}

