//============================================================================
// Name        : main.cpp
// Author      : Ari Suarkadipa
// Version     :
// Copyright   :
// Description :
//============================================================================

#include <boost/shared_ptr.hpp>
#include <fstream>
#include <iostream>
#include <memory>
#include <odb/database.hxx>
#include "env/SNMPDao/inc/DBFactory.hpp"
#include "env/SNMPDao/inc/Entity/NetworkElement.hpp"
#include "env/SNMPDao/inc/MySQLFactory.hpp"
#include "inc/util/DatabaseUtil.hpp"

using namespace odb::core;
using namespace Mitrais::Nemsta;
int main() {
  // Database information
  const char *_username = "NemsTA";
  const char *_password = "N3m5TA4adm1n";
  const char *_host = "172.19.12.251";
  const char *_dbName = "nemstadb";

  // Create database connection
  std::unique_ptr<DB::DBFactory> dbFactory(
      new DB::MySQLFactory(_username, _password, _dbName, _host));
  std::unique_ptr<database> dbConn(dbFactory->createDatabase());

  // Create database util and inject the database connection
  DatabaseUtil databaseUtil(dbConn);
  /*long networkElementId = databaseUtil.insertNetworkElement(
      "element1", "DA:DB:32:35:88:97:9B", "172.19.12.251");*/

  // long networkElementId2 = databaseUtil.insertNetworkElement(
  //      "element2", "DA:DB:32:35:89:OC:8B", "172.19.12.251");

  /*boost::shared_ptr<NetworkElement> element1 =
      databaseUtil.getNetWorkElementById(networkElementId);
  std::cout << "Network Element IP Address" << element1->IPAddress()
            << std::endl;*/
  // std::cout << "Network Element Mac" << element1->MACAddress()
  // << std::endl;

  long test = databaseUtil.insertSNMPValue(1, "1.3.6.1.2.1.1.1.0", "TestInsert",
                                           "string");
  return 0;
}
