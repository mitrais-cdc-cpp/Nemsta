/*
 * DatabaseUtil.hpp
 *
 *  Created on: Sep 1, 2016
 *      Author: developer
 */

#ifndef INC_UTIL_DATABASEUTIL_HPP_
#define INC_UTIL_DATABASEUTIL_HPP_
#include <odb/database.hxx>
#include <odb/mysql/database.hxx>
#include <odb/transaction.hxx>

#include <odb_gen/MonitorHistory_odb.h>
#include <odb_gen/NetworkElement_odb.h>
#include <odb_gen/SnmpObjectType_odb.h>
#include <odb_gen/SnmpObjectValue_odb.h>
#include <odb_gen/SnmpObject_odb.h>

#include <DBFactory.hpp>
#include <MySQLFactory.hpp>

#include <Entity/MonitorHistory.hpp>
#include <Entity/NetworkElement.hpp>
#include <Entity/SnmpObject.hpp>
#include <Entity/SnmpObjectType.hpp>
#include <Entity/SnmpObjectValue.hpp>

#include <iostream>
#include <memory>
#include <string>

typedef odb::query<SnmpObjectType> query_snmpmobject_type;
typedef odb::result<SnmpObjectType> result_snmpmobject_type;
typedef odb::query<SnmpObject> query_snmpmobject;
typedef odb::result<SnmpObject> result_snmpmobject;

class DatabaseUtil {
 public:
  /**
   * Default constructor
   * @param dbConn: Database connection
   */
  // DatabaseUtil(std::auto_ptr<odb::core::database> &_dbConn);
  DatabaseUtil(std::string username, std::string password, std::string dbname,
               std::string host);

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
  std::auto_ptr<NetworkElement> getNetWorkElementById(
      unsigned long networkElementId);

 private:
  /**
   * Database connection
   */
  std::auto_ptr<odb::database> _dbConn;

  std::auto_ptr<SnmpObjectType> getSnmpObjectTypeByTypeName(
      const std::string &value);

  std::auto_ptr<SnmpObject> getSnmpObjectByOid(const std::string &value);

  std::auto_ptr<MonitorHistory> insertMonitorHistory(
      const unsigned long long &lastUpdate, const std::string &note);

  long insertSnmpObjectValue(const std::string &value,
                             std::auto_ptr<SnmpObject> snmpObject,
                             std::auto_ptr<MonitorHistory> monitorHistory,
                             std::auto_ptr<SnmpObjectType> snmpObjectType);
};

#endif /* INC_UTIL_DATABASEUTIL_HPP_ */
