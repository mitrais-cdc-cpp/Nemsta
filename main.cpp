#include <fstream>
#include <iostream>
#include <memory>

#include "env/SNMPDao/inc/DBFactory.hpp"
#include "env/SNMPDao/inc/DataAccess.hpp"
#include "env/SNMPDao/inc/Entity/NetworkElement.hpp"

#include "env/SNMPLib/inc/PDU.hpp"
#include "env/SNMPLib/inc/ReturnStatus.hpp"
#include "inc/util/DatabaseUtil.hpp"
#include "inc/util/NemstaUtil.hpp"

using namespace Mitrais::SNMP;
using namespace Mitrais::Nemsta;

int main(int argc, char *argv[]) {
  // TODO: Move and refactor and move the process to get and save SNMP to
  // database, so main.cpp will clean.
  NemstaUtil nemsta;
  PDU pdu;
  ReturnStatus status = nemsta.capture(argc, argv, pdu);

  std::vector<Mitrais::SNMP::VariableBinding> vbs = pdu.getBindingList();

  DatabaseUtil databaseUtil;
  std::shared_ptr<DB::DBFactory> db = databaseUtil.create(RDBMSType::MYSQL);

  if (db) {
    // Get network element
    std::shared_ptr<NetworkElement> element(
        db->getNetWorkElementByMacAddress(nemsta.getMacAddress()));

    long networkElementId;

    if (element) {
      networkElementId = element->NetWorkElementId();
    } else {
      networkElementId = db->insertNetworkElement(
          "Test Element", nemsta.getMacAddress(), nemsta.getIpAddress());
    }

    for (auto var : vbs) {
      std::string value;
      var.getValue(value);
      std::cout << "Result : " << var.getOID().oid << " : " << value
                << std::endl;

      // Get the given OID, insert it if not exist
      std::string OIDResult =
          db->insertSnmpObject("", var.getOID().oid, "Test Object");

      // Insert the SNPM value by the given network element id and oid
      db->insertSNMPValue(networkElementId, OIDResult, value, "string");
    }

  } else {
    std::cout << "Error connecting to database" << std::endl;
  }

  return 0;
}
