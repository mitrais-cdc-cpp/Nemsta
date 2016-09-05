/*
 * DatabaseUtil.hpp
 *
 *  Created on: Sep 1, 2016
 *      Author: developer
 */

#ifndef INC_UTIL_DATABASEUTIL_HPP_
#define INC_UTIL_DATABASEUTIL_HPP_
//#include <std/date_time/gregorian/gregorian.hpp>
//#include <std/date_time/posix_time/ptime.hpp>
//#include <std/shared_ptr.hpp>
#include <iostream>
#include <memory>
#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include <string>
#include "../../env/SNMPDao/inc/DBFactory.hpp"
#include "../../env/SNMPDao/inc/Entity/MonitorHistory.hpp"
#include "../../env/SNMPDao/inc/Entity/NetworkElement.hpp"
#include "../../env/SNMPDao/inc/Entity/SnmpObject.hpp"
#include "../../env/SNMPDao/inc/Entity/SnmpObjectType.hpp"
#include "../../env/SNMPDao/inc/Entity/SnmpObjectValue.hpp"
#include "../../env/SNMPDao/inc/MySQLFactory.hpp"
#include "../../env/SNMPDao/inc/odb_gen/MonitorHistory_odb.h"
#include "../../env/SNMPDao/inc/odb_gen/NetworkElement_odb.h"
#include "../../env/SNMPDao/inc/odb_gen/SnmpObjectType_odb.h"
#include "../../env/SNMPDao/inc/odb_gen/SnmpObjectValue_odb.h"
#include "../../env/SNMPDao/inc/odb_gen/SnmpObject_odb.h"

using namespace odb::core;
using namespace Mitrais::SNMPDao::Entity;

typedef odb::query<SnmpObjectType> query_snmpmobject_type;
typedef odb::result<SnmpObjectType> result_snmpmobject_type;
typedef odb::query<SnmpObject> query_snmpmobject;
typedef odb::result<SnmpObject> result_snmpmobject;
namespace Mitrais {
namespace Nemsta {
class DatabaseUtil {
 public:
  /**
   * Default constructor
   * @param dbConn: Database connection
   */
  DatabaseUtil(std::unique_ptr<database> &_dbConn);

  /**
   * Default destructor
   */
  ~DatabaseUtil();

  /**
   * Function to insert NetworkElement
   * @param elementName : Element name
   * @param macAddress : MacAdress
   * @param ipAddress : IP Adress
   */
  long insertNetworkElement(const std::string &elementName,
                            const std::string &macAddress,
                            const std::string &ipAddress);

  // Method
  long insertSNMPValue(const int &networkElementId, const std::string &OID,
                       const std::string &value, const std::string &typeName);

  /**
   * Function to get NetworkElement by id
   * @param id: NetworkElement id
   * @return pointer to NetworkElement
   */
  std::shared_ptr<NetworkElement> getNetWorkElementById(
      unsigned long networkElementId);

 private:
  /**
   * Database connection
   */
  std::shared_ptr<database> _dbConn;

  std::shared_ptr<SnmpObjectType> getSnmpObjectTypeByTypeName(
      const std::string &value);

  std::shared_ptr<SnmpObject> getSnmpObjectByOid(const std::string &value);

  long insertMonitorHistory(const unsigned long long &lastUpdate,
                            const std::string &note);

  long insertSnmpObjectValue(const std::string &value,
                             std::shared_ptr<SnmpObject> snmpObject,
                             std::shared_ptr<MonitorHistory> monitorHistory,
                             std::shared_ptr<SnmpObjectType> snmpObjectType);
};
}
}

#endif /* INC_UTIL_DATABASEUTIL_HPP_ */
