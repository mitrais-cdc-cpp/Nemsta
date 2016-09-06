/*
 * DatabaseUtil.cpp
 *
 *  Created on: Sep 1, 2016
 *      Author: developer
 */

#include "../../inc/util/DatabaseUtil.hpp"
namespace Mitrais {
namespace Nemsta {

/**
 * Default contructor
 * @param dbConn
 */
DatabaseUtil::DatabaseUtil(std::unique_ptr<database>& dbConn)
    : _dbConn(std::move(dbConn)) {}

/**
 * Default destructor
 */
DatabaseUtil::~DatabaseUtil() {}

/**
* Function to insert NetworkElement
* @param elementName : Element name
* @param macAddress : MacAdress
* @param ipAddress : IP Adress
*/
long DatabaseUtil::insertNetworkElement(const std::string& elementName,
                                        const std::string& macAddress,
                                        const std::string& ipAddress) {
  transaction t(_dbConn->begin());
  try {
    NetworkElement element(elementName, macAddress, ipAddress);
    long id = _dbConn->persist(element);
    t.commit();

    return id;
  } catch (const odb::exception& e) {
    t.rollback();
    std::cerr << e.what() << std::endl;
    return 0;
  }
}

long DatabaseUtil::insertSNMPValue(const int& networkElementId,
                                   const std::string& OID,
                                   const std::string& value,
                                   const std::string& typeName) {
  transaction t(_dbConn->begin());
  try {
    result_snmpmobject_type r(_dbConn->query<SnmpObjectType>());

    std::shared_ptr<SnmpObjectType> snmpObjectType(
        getSnmpObjectTypeByTypeName(typeName));

    std::shared_ptr<SnmpObject> snmpObject(getSnmpObjectByOid(OID));

    long monitorHistoryId = insertMonitorHistory(12345, "Test");

    std::shared_ptr<MonitorHistory> monitorHistory(
        _dbConn->load<MonitorHistory>(monitorHistoryId));

    // std::shared_ptr<MonitorHistory> monitorHistory(
    //    new MonitorHistory(12345, "Test 123"));

    long snmpValueId = insertSnmpObjectValue(value, snmpObject, monitorHistory,
                                             snmpObjectType);

    std::cout << "Mib SnmpObject : " << snmpObject->Mib() << std::endl;
    std::cout << "Typename : " << snmpObjectType->TypeName() << std::endl;
    // std::cout << "Monitor Hiistory : " << monitorHistoryId << std::endl;
    std::cout << "SnmpValue Id : " << snmpValueId << std::endl;
    t.commit();
  } catch (const odb::exception& e) {
    t.rollback();
  }

  return 1;
}
/**
   * Function to get NetworkElement by id
   * @param id: NetworkElement id
   * @return pointer to NetworkElement
   */
std::shared_ptr<NetworkElement> DatabaseUtil::getNetWorkElementById(
    unsigned long networkElementId) {
  transaction t(_dbConn->begin());
  std::shared_ptr<NetworkElement> element1;
  try {
    std::shared_ptr<NetworkElement> element(
        _dbConn->load<NetworkElement>(networkElementId));
    t.commit();
    return element;
  } catch (const odb::exception& e) {
    t.rollback();
    std::cerr << e.what() << std::endl;
    return element1;
  }
}

// TODO: give back collection of SnmpObjectType
std::shared_ptr<SnmpObjectType> DatabaseUtil::getSnmpObjectTypeByTypeName(
    const std::string& value) {
  std::shared_ptr<SnmpObjectType> object1;

  result_snmpmobject_type r(_dbConn->query<SnmpObjectType>(
      query_snmpmobject_type::typeName == value));

  if (r.size() > 0) {
    result_snmpmobject_type::iterator i(r.begin());

    object1 = std::shared_ptr<SnmpObjectType>(i.load());
    return object1;
  } else {
    return object1;
  }
}

std::shared_ptr<SnmpObject> DatabaseUtil::getSnmpObjectByOid(
    const std::string& value) {
  std::shared_ptr<SnmpObject> object;

  result_snmpmobject r(
      _dbConn->query<SnmpObject>(query_snmpmobject::oid == value));

  if (r.size() > 0) {
    result_snmpmobject::iterator i(r.begin());

    object = std::shared_ptr<SnmpObject>(i.load());
    return object;
  } else {
    return object;
  }
}

//
long DatabaseUtil::insertMonitorHistory(const unsigned long long& lastUpdate,
                                        const std::string& note) {
  MonitorHistory entity(lastUpdate, note);
  long id = _dbConn->persist(entity);

  return id;
}

//
long DatabaseUtil::insertSnmpObjectValue(
    const std::string& value, std::shared_ptr<SnmpObject> snmpObject,
    std::shared_ptr<MonitorHistory> monitorHistory,
    std::shared_ptr<SnmpObjectType> snmpObjectType) {
  std::shared_ptr<SnmpObjectValue> entity(
      new SnmpObjectValue(value, snmpObject, snmpObjectType, monitorHistory));
  long id = _dbConn->persist(*entity);
  return id;
}
}
}
