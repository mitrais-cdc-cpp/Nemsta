#ifndef NEMSTA_INC_ENTITY_SNMPVALUES_HPP_
#define NEMSTA_INC_ENTITY_SNMPVALUES_HPP_

//#include <boost/shared_ptr.hpp>
#include <cstddef>
#include <memory>
#include <odb/core.hxx>
#include <string>
#include "MonitorHistory.hpp"
#include "SnmpObject.hpp"
#include "SnmpObjectType.hpp"

class SnmpObject;
class SnmpObjectType;
class MonitorHistory;

#pragma db object pointer(std::shared_ptr) session
class SnmpObjectValue {
 public:
  typedef ::SnmpObject snmpObjectTypeDef;
  typedef ::SnmpObjectType snmpObjectTypeTypeDef;
  typedef ::MonitorHistory monitorHistoryTypeDef;
  SnmpObjectValue(const std::string value,
                  std::shared_ptr<snmpObjectTypeDef> snmpObject,
                  std::shared_ptr<snmpObjectTypeTypeDef> snmpObjectType,
                  std::shared_ptr<monitorHistoryTypeDef> monitorHistory)
      : value_(value),
        snmpObjectFk_(snmpObject),
        snmpObjectTypeFk_(snmpObjectType),
        monitorHistoryFk_(monitorHistory) {}

  const std::string& value() const { return value_; }

  void snmpObject(std::shared_ptr<snmpObjectTypeDef> snmpObject) {
    snmpObjectFk_ = snmpObject;
  }

  void snmpObjectType(std::shared_ptr<snmpObjectTypeTypeDef> snmpObjectType) {
    snmpObjectTypeFk_ = snmpObjectType;
  }

  void monitorHistory(std::shared_ptr<monitorHistoryTypeDef> monitorHistory) {
    monitorHistoryFk_ = monitorHistory;
  }

  std::shared_ptr<snmpObjectTypeDef> snmpObject() const {
    return snmpObjectFk_;
  }
  std::shared_ptr<snmpObjectTypeTypeDef> snmpObjectType() const {
    return snmpObjectTypeFk_;
  }
  std::shared_ptr<monitorHistoryTypeDef> monitorHistory() const {
    return monitorHistoryFk_;
  }

 private:
  friend class odb::access;
  SnmpObjectValue() {}
#pragma db id auto
  unsigned long snmpObjectValueId_;

#pragma db type("VARCHAR(45)")
  std::string value_;

#pragma db not_null
  std::shared_ptr<snmpObjectTypeDef> snmpObjectFk_;

#pragma db not_null
  std::shared_ptr<snmpObjectTypeTypeDef> snmpObjectTypeFk_;

#pragma db not_null
  std::shared_ptr<monitorHistoryTypeDef> monitorHistoryFk_;
};

#endif /* NEMSTA_INC_ENTITY_SNMPVALUES_HPP_ */
