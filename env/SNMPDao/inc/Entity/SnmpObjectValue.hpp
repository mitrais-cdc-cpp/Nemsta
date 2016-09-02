#ifndef NEMSTA_INC_ENTITY_SNMPVALUES_HPP_
#define NEMSTA_INC_ENTITY_SNMPVALUES_HPP_

#include <boost/shared_ptr.hpp>
#include <cstddef>
#include <odb/core.hxx>
#include <string>
#include "MonitorHistory.hpp"
#include "SnmpObject.hpp"
#include "SnmpObjectType.hpp"

#pragma db object

namespace Mitrais {
namespace SNMPDao {
namespace Entity {
class SnmpObjectValue {
 public:
  SnmpObjectValue(const std::string value,
                  boost::shared_ptr<SnmpObject> snmpObject,
                  boost::shared_ptr<MonitorHistory> monitorHistory,
                  boost::shared_ptr<SnmpObjectType> snmpObjectType)
      : value_(value),
        snmpObject_(snmpObject),
        snmpObjectType_(snmpObjectType),
        monitorHistory_(monitorHistory) {}

  const std::string& Value() const { return value_; }

  boost::shared_ptr<SnmpObject> getSnmpObject() const { return snmpObject_; }
  boost::shared_ptr<SnmpObjectType> getSnmpObjectType() const {
    return snmpObjectType_;
  }
  boost::shared_ptr<MonitorHistory> getMonitorHistory() const {
    return monitorHistory_;
  }

 private:
  friend class odb::access;
  SnmpObjectValue() {}
#pragma db id auto
  unsigned long snmpObjectValueId_;

#pragma db type("VARCHAR(45)")
  std::string value_;

#pragma db not_null
  boost::shared_ptr<SnmpObject> snmpObject_;

#pragma db not_null
  boost::shared_ptr<SnmpObjectType> snmpObjectType_;

#pragma db not_null
  boost::shared_ptr<MonitorHistory> monitorHistory_;
};

#pragma db view object(SnmpObjectValue)
struct SnmpObjectValue_stat {
#pragma db column("count(" + SnmpObjectValue::snmpObjectValueId_ + ")")
  std::size_t count;
};
}
}
}

#endif /* NEMSTA_INC_ENTITY_SNMPVALUES_HPP_ */
