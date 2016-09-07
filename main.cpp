#include <fstream>
#include <iostream>
#include <memory>
#include <odb/database.hxx>
#include "env/SNMPDao/inc/DBFactory.hpp"
#include "env/SNMPDao/inc/Entity/NetworkElement.hpp"
#include "env/SNMPDao/inc/MySQLFactory.hpp"
#include "env/SNMPLib/inc/PDU.hpp"
#include "env/SNMPLib/inc/ReturnStatus.hpp"
#include "inc/util/DatabaseUtil.hpp"
#include "inc/util/NemstaUtil.hpp"

using namespace Mitrais::SNMP;
using namespace Mitrais::Nemsta;
using namespace odb::core;

int main(int argc, char *argv[]) {
  NemstaUtil nemsta;
  PDU pdu;
  ReturnStatus status = nemsta.capture(argc, argv, pdu);

  std::cout << std::endl;
  std::cout << "IP Address  : " << nemsta.getIpAddress() << std::endl;
  std::cout << "MAC Address : " << nemsta.getMacAddress() << std::endl;

  // This from SNMPDao
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

  long test = databaseUtil.insertSNMPValue(1, "1.3.6.1.2.1.1.1.0", "TestInsert",
                                           "string");

  return 0;
}
