/*
 * DatabaseUtil.hpp
 *
 *  Created on: Sep 1, 2016
 *      Author: developer
 */

#ifndef INC_UTIL_DATABASEUTIL_HPP_
#define INC_UTIL_DATABASEUTIL_HPP_
#include <boost/shared_ptr.hpp>
#include <iostream>
//#include <memory>
#include <odb/database.hxx>
#include <odb/transaction.hxx>
#include <string>
#include "../../env/SNMPDao/inc/DBFactory.hpp"
#include "../../env/SNMPDao/inc/Entity/NetworkElement.hpp"
#include "../../env/SNMPDao/inc/MySQLFactory.hpp"
#include "../../env/SNMPDao/inc/odb_gen/NetworkElement_odb.h"

using namespace odb::core;
using namespace Mitrais::SNMPDao::Entity;

typedef odb::query<NetworkElement> query;
typedef odb::result<NetworkElement> result;
namespace Mitrais {
namespace Nemsta {
class DatabaseUtil {
 public:
  /**
   * Default constructor
   * @param dbConn: Database connection
   */
  DatabaseUtil(std::auto_ptr<database> &_dbConn);

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

  /**
   * Function to get NetworkElement by id
   * @param id: NetworkElement id
   * @return pointer to NetworkElement
   */
  boost::shared_ptr<NetworkElement> getNetWorkElementById(
      unsigned long networkElementId);

 private:
  /**
   * Database connection
   */
  std::auto_ptr<database> _dbConn;
};
}
}

#endif /* INC_UTIL_DATABASEUTIL_HPP_ */
