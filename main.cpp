#define __DEBUG

#include <fstream>
#include <iostream>
#include <memory>

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

  // Database information
  std::string username = "NemsTA";
  std::string password = "N3m5TA4adm1n";
  std::string host = "172.19.12.251";
  std::string dbname = "nemstadb";

  // std::cout << std::endl;
  // std::cout << "IP Address  : " << nemsta.getIpAddress() << std::endl;
  // std::cout << "MAC Address : " << nemsta.getMacAddress() << std::endl;

  // Create database connection
  // std::auto_ptr<DB::DBFactory> dbFactory(
  //    new DB::MySQLFactory(_username, _password, _dbName, _host));
  // std::auto_ptr<odb::database> dbConn(dbFactory->createDatabase());

  DatabaseUtil databaseUtil(username, password, dbname, host);
  long test = databaseUtil.insertSNMPValue(1, "1.3.6.1.2.1.1.1.0", "TestInsert",
                                           "string");

  return 0;
}
