#include <fstream>
#include <iostream>
#include <memory>

#include "env/SNMPDao/inc/DBFactory.hpp"
#include "env/SNMPDao/inc/DataAccess.hpp"

#include "env/SNMPLib/inc/PDU.hpp"
#include "env/SNMPLib/inc/ReturnStatus.hpp"
#include "inc/util/DatabaseUtil.hpp"
#include "inc/util/NemstaUtil.hpp"

using namespace Mitrais::SNMP;
using namespace Mitrais::Nemsta;

int main(int argc, char *argv[]) {
  NemstaUtil nemsta;
  PDU pdu;
  ReturnStatus status = nemsta.capture(argc, argv, pdu);

  DatabaseUtil databaseUtil;
  std::shared_ptr<DB::DBFactory> db = databaseUtil.create(RDBMSType::MYSQL);

  if (db) {
    db->insertSNMPValue(1, "1.3.6.1.2.1.1.1.0", "TestInsert", "string");
  }

  return 0;
}
