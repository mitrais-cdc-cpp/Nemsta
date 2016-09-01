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
DatabaseUtil::DatabaseUtil(std::auto_ptr<database>& dbConn)
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

/**
   * Function to get NetworkElement by id
   * @param id: NetworkElement id
   * @return pointer to NetworkElement
   */
boost::shared_ptr<NetworkElement> DatabaseUtil::getNetWorkElementById(
    unsigned long networkElementId) {
  transaction t(_dbConn->begin());
  boost::shared_ptr<NetworkElement> element1;
  try {
    // std::auto_ptr<NetworkElement> element(
    //   _dbConn->load<NetworkElement>(networkElementId));
    boost::shared_ptr<NetworkElement> element(
        _dbConn->load<NetworkElement>(networkElementId));
    t.commit();
    return element;
  } catch (const odb::exception& e) {
    t.rollback();
    std::cerr << e.what() << std::endl;
    return element1;
  }
}
}
}
