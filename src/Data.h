/**
 * Autogenerated by Thrift Compiler (0.9.1)
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */
#ifndef Data_H
#define Data_H

#include <thrift/TDispatchProcessor.h>
#include "data_types.h"

namespace Thread_Lock_Mutex {

class DataIf {
 public:
  virtual ~DataIf() {}
  virtual int32_t put(const int32_t user) = 0;
  virtual int32_t get(const int32_t uid) = 0;
  virtual int32_t update(const int32_t index, const int32_t value) = 0;
};

class DataIfFactory {
 public:
  typedef DataIf Handler;

  virtual ~DataIfFactory() {}

  virtual DataIf* getHandler(const ::apache::thrift::TConnectionInfo& connInfo) = 0;
  virtual void releaseHandler(DataIf* /* handler */) = 0;
};

class DataIfSingletonFactory : virtual public DataIfFactory {
 public:
  DataIfSingletonFactory(const boost::shared_ptr<DataIf>& iface) : iface_(iface) {}
  virtual ~DataIfSingletonFactory() {}

  virtual DataIf* getHandler(const ::apache::thrift::TConnectionInfo&) {
    return iface_.get();
  }
  virtual void releaseHandler(DataIf* /* handler */) {}

 protected:
  boost::shared_ptr<DataIf> iface_;
};

class DataNull : virtual public DataIf {
 public:
  virtual ~DataNull() {}
  int32_t put(const int32_t /* user */) {
    int32_t _return = 0;
    return _return;
  }
  int32_t get(const int32_t /* uid */) {
    int32_t _return = 0;
    return _return;
  }
  int32_t update(const int32_t /* index */, const int32_t /* value */) {
    int32_t _return = 0;
    return _return;
  }
};

typedef struct _Data_put_args__isset {
  _Data_put_args__isset() : user(false) {}
  bool user;
} _Data_put_args__isset;

class Data_put_args {
 public:

  Data_put_args() : user(0) {
  }

  virtual ~Data_put_args() throw() {}

  int32_t user;

  _Data_put_args__isset __isset;

  void __set_user(const int32_t val) {
    user = val;
  }

  bool operator == (const Data_put_args & rhs) const
  {
    if (!(user == rhs.user))
      return false;
    return true;
  }
  bool operator != (const Data_put_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Data_put_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Data_put_pargs {
 public:


  virtual ~Data_put_pargs() throw() {}

  const int32_t* user;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Data_put_result__isset {
  _Data_put_result__isset() : success(false) {}
  bool success;
} _Data_put_result__isset;

class Data_put_result {
 public:

  Data_put_result() : success(0) {
  }

  virtual ~Data_put_result() throw() {}

  int32_t success;

  _Data_put_result__isset __isset;

  void __set_success(const int32_t val) {
    success = val;
  }

  bool operator == (const Data_put_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Data_put_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Data_put_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Data_put_presult__isset {
  _Data_put_presult__isset() : success(false) {}
  bool success;
} _Data_put_presult__isset;

class Data_put_presult {
 public:


  virtual ~Data_put_presult() throw() {}

  int32_t* success;

  _Data_put_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Data_get_args__isset {
  _Data_get_args__isset() : uid(false) {}
  bool uid;
} _Data_get_args__isset;

class Data_get_args {
 public:

  Data_get_args() : uid(0) {
  }

  virtual ~Data_get_args() throw() {}

  int32_t uid;

  _Data_get_args__isset __isset;

  void __set_uid(const int32_t val) {
    uid = val;
  }

  bool operator == (const Data_get_args & rhs) const
  {
    if (!(uid == rhs.uid))
      return false;
    return true;
  }
  bool operator != (const Data_get_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Data_get_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Data_get_pargs {
 public:


  virtual ~Data_get_pargs() throw() {}

  const int32_t* uid;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Data_get_result__isset {
  _Data_get_result__isset() : success(false) {}
  bool success;
} _Data_get_result__isset;

class Data_get_result {
 public:

  Data_get_result() : success(0) {
  }

  virtual ~Data_get_result() throw() {}

  int32_t success;

  _Data_get_result__isset __isset;

  void __set_success(const int32_t val) {
    success = val;
  }

  bool operator == (const Data_get_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Data_get_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Data_get_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Data_get_presult__isset {
  _Data_get_presult__isset() : success(false) {}
  bool success;
} _Data_get_presult__isset;

class Data_get_presult {
 public:


  virtual ~Data_get_presult() throw() {}

  int32_t* success;

  _Data_get_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

typedef struct _Data_update_args__isset {
  _Data_update_args__isset() : index(false), value(false) {}
  bool index;
  bool value;
} _Data_update_args__isset;

class Data_update_args {
 public:

  Data_update_args() : index(0), value(0) {
  }

  virtual ~Data_update_args() throw() {}

  int32_t index;
  int32_t value;

  _Data_update_args__isset __isset;

  void __set_index(const int32_t val) {
    index = val;
  }

  void __set_value(const int32_t val) {
    value = val;
  }

  bool operator == (const Data_update_args & rhs) const
  {
    if (!(index == rhs.index))
      return false;
    if (!(value == rhs.value))
      return false;
    return true;
  }
  bool operator != (const Data_update_args &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Data_update_args & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};


class Data_update_pargs {
 public:


  virtual ~Data_update_pargs() throw() {}

  const int32_t* index;
  const int32_t* value;

  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Data_update_result__isset {
  _Data_update_result__isset() : success(false) {}
  bool success;
} _Data_update_result__isset;

class Data_update_result {
 public:

  Data_update_result() : success(0) {
  }

  virtual ~Data_update_result() throw() {}

  int32_t success;

  _Data_update_result__isset __isset;

  void __set_success(const int32_t val) {
    success = val;
  }

  bool operator == (const Data_update_result & rhs) const
  {
    if (!(success == rhs.success))
      return false;
    return true;
  }
  bool operator != (const Data_update_result &rhs) const {
    return !(*this == rhs);
  }

  bool operator < (const Data_update_result & ) const;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);
  uint32_t write(::apache::thrift::protocol::TProtocol* oprot) const;

};

typedef struct _Data_update_presult__isset {
  _Data_update_presult__isset() : success(false) {}
  bool success;
} _Data_update_presult__isset;

class Data_update_presult {
 public:


  virtual ~Data_update_presult() throw() {}

  int32_t* success;

  _Data_update_presult__isset __isset;

  uint32_t read(::apache::thrift::protocol::TProtocol* iprot);

};

class DataClient : virtual public DataIf {
 public:
  DataClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> prot) :
    piprot_(prot),
    poprot_(prot) {
    iprot_ = prot.get();
    oprot_ = prot.get();
  }
  DataClient(boost::shared_ptr< ::apache::thrift::protocol::TProtocol> iprot, boost::shared_ptr< ::apache::thrift::protocol::TProtocol> oprot) :
    piprot_(iprot),
    poprot_(oprot) {
    iprot_ = iprot.get();
    oprot_ = oprot.get();
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getInputProtocol() {
    return piprot_;
  }
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> getOutputProtocol() {
    return poprot_;
  }
  int32_t put(const int32_t user);
  void send_put(const int32_t user);
  int32_t recv_put();
  int32_t get(const int32_t uid);
  void send_get(const int32_t uid);
  int32_t recv_get();
  int32_t update(const int32_t index, const int32_t value);
  void send_update(const int32_t index, const int32_t value);
  int32_t recv_update();
 protected:
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> piprot_;
  boost::shared_ptr< ::apache::thrift::protocol::TProtocol> poprot_;
  ::apache::thrift::protocol::TProtocol* iprot_;
  ::apache::thrift::protocol::TProtocol* oprot_;
};

class DataProcessor : public ::apache::thrift::TDispatchProcessor {
 protected:
  boost::shared_ptr<DataIf> iface_;
  virtual bool dispatchCall(::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, const std::string& fname, int32_t seqid, void* callContext);
 private:
  typedef  void (DataProcessor::*ProcessFunction)(int32_t, ::apache::thrift::protocol::TProtocol*, ::apache::thrift::protocol::TProtocol*, void*);
  typedef std::map<std::string, ProcessFunction> ProcessMap;
  ProcessMap processMap_;
  void process_put(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_get(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
  void process_update(int32_t seqid, ::apache::thrift::protocol::TProtocol* iprot, ::apache::thrift::protocol::TProtocol* oprot, void* callContext);
 public:
  DataProcessor(boost::shared_ptr<DataIf> iface) :
    iface_(iface) {
    processMap_["put"] = &DataProcessor::process_put;
    processMap_["get"] = &DataProcessor::process_get;
    processMap_["update"] = &DataProcessor::process_update;
  }

  virtual ~DataProcessor() {}
};

class DataProcessorFactory : public ::apache::thrift::TProcessorFactory {
 public:
  DataProcessorFactory(const ::boost::shared_ptr< DataIfFactory >& handlerFactory) :
      handlerFactory_(handlerFactory) {}

  ::boost::shared_ptr< ::apache::thrift::TProcessor > getProcessor(const ::apache::thrift::TConnectionInfo& connInfo);

 protected:
  ::boost::shared_ptr< DataIfFactory > handlerFactory_;
};

class DataMultiface : virtual public DataIf {
 public:
  DataMultiface(std::vector<boost::shared_ptr<DataIf> >& ifaces) : ifaces_(ifaces) {
  }
  virtual ~DataMultiface() {}
 protected:
  std::vector<boost::shared_ptr<DataIf> > ifaces_;
  DataMultiface() {}
  void add(boost::shared_ptr<DataIf> iface) {
    ifaces_.push_back(iface);
  }
 public:
  int32_t put(const int32_t user) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->put(user);
    }
    return ifaces_[i]->put(user);
  }

  int32_t get(const int32_t uid) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->get(uid);
    }
    return ifaces_[i]->get(uid);
  }

  int32_t update(const int32_t index, const int32_t value) {
    size_t sz = ifaces_.size();
    size_t i = 0;
    for (; i < (sz - 1); ++i) {
      ifaces_[i]->update(index, value);
    }
    return ifaces_[i]->update(index, value);
  }

};

} // namespace

#endif
