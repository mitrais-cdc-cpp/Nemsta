/*
 * DatabaseUtil.cpp
 *
 *  Created on: Sep 1, 2016
 *      Author: developer
 */

#include "../../inc/util/DatabaseUtil.hpp"

/**
 * Default contructor
 * @param dbConn
 */
DatabaseUtil::DatabaseUtil(std::string username, std::string password,
                           std::string dbname, std::string host)
    : _dbConn(new odb::mysql::database(username, password, dbname, host)) {}

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
  odb::core::transaction t(_dbConn->begin());
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
  long snmpValueId = -1;
  odb::core::transaction t(_dbConn->begin());
  try {
    std::auto_ptr<SnmpObjectType> snmpObjectType(
        getSnmpObjectTypeByTypeName(typeName));
    std::auto_ptr<SnmpObject> snmpObject(getSnmpObjectByOid(OID));
    std::auto_ptr<MonitorHistory> monitorHistory(
        insertMonitorHistory(12345, "Test"));

    snmpValueId = insertSnmpObjectValue(value, snmpObject, monitorHistory,
                                        snmpObjectType);
#ifdef __DEBUG
    std::cout << "Mib SnmpObject : " << snmpObject->Mib() << std::endl;
    std::cout << "Typename : " << snmpObjectType->TypeName() << std::endl;
    std::cout << "SnmpValue Id : " << snmpValueId << std::endl;
#endif

    t.commit();
  } catch (const odb::exception& e) {
    t.rollback();
  }

  return snmpValueId;
}
/**
   * Function to get NetworkElement by id
   * @param id: NetworkElement id
   * @return pointer to NetworkElement
   */
std::auto_ptr<NetworkElement> DatabaseUtil::getNetWorkElementById(
    unsigned long networkElementId) {
  odb::core::transaction t(_dbConn->begin());
  std::auto_ptr<NetworkElement> element1;
  try {
    std::auto_ptr<NetworkElement> element(
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
std::auto_ptr<SnmpObjectType> DatabaseUtil::getSnmpObjectTypeByTypeName(
    const std::string& value) {
  std::auto_ptr<SnmpObjectType> object1;

  result_snmpmobject_type r(_dbConn->query<SnmpObjectType>(
      query_snmpmobject_type::typeName == value));

  if (r.size() > 0) {
    result_snmpmobject_type::iterator i(r.begin());
    object1 = std::auto_ptr<SnmpObjectType>(i.load());
    return object1;
  } else {
    return object1;
  }
}

std::auto_ptr<SnmpObject> DatabaseUtil::getSnmpObjectByOid(
    const std::string& value) {
  std::auto_ptr<SnmpObject> object;

  result_snmpmobject r(
      _dbConn->query<SnmpObject>(query_snmpmobject::oid == value));

  if (r.size() > 0) {
    result_snmpmobject::iterator i(r.begin());

    object = std::auto_ptr<SnmpObject>(i.load());
    return object;
  } else {
    return object;
  }
}

//
std::auto_ptr<MonitorHistory> DatabaseUtil::insertMonitorHistory(
    const unsigned long long& lastUpdate, const std::string& note) {
  std::auto_ptr<MonitorHistory> entity(new MonitorHistory(lastUpdate, note));
  _dbConn->persist(*entity);

  return entity;
}

//
long DatabaseUtil::insertSnmpObjectValue(
    const std::string& value, std::auto_ptr<SnmpObject> snmpObject,
    std::auto_ptr<MonitorHistory> monitorHistory,
    std::auto_ptr<SnmpObjectType> snmpObjectType) {
  std::auto_ptr<SnmpObjectValue> entity(
      new SnmpObjectValue(value, snmpObject, snmpObjectType, monitorHistory));
  long id = _dbConn->persist(*entity);
  return id;
}
