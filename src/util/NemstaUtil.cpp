/*
 * NemstaUtil.cpp
 *
 *  Created on: Aug 16, 2016
 *      Author: Ari Suarkadipa
 */

#include "../../inc/util/NemstaUtil.hpp"

using namespace Mitrais::Nemsta;

/**
 * Constructor of Nemsta Util class
 */
NemstaUtil::NemstaUtil() {
  // Call the snmp util to get local workstation MAC address
  Mitrais::Nemsta::SnmpUtil snmp;
  localMacAddress_ = snmp.getLocalMacAddress();
}

/**
 * Destructor of Nemsta Util class
 */
NemstaUtil::~NemstaUtil() {}

/**
 * Capture the SNMP Value
 *
 * @param argc
 * @param argv
 * @param pdu
 * @return
 */
Mitrais::SNMP::ReturnStatus NemstaUtil::capture(int argc, char* argv[],
                                                Mitrais::SNMP::PDU& pdu) {
  std::string ipAddress;
  Mitrais::SNMP::SnmpMode mode;
  mode = Mitrais::SNMP::REQUEST;

  // there is no argments or parameter stored
  if (argc == 1) {
    // set the IP address as default
    ipAddress_ = "172.19.12.29";
    // ipAddress_ = "172.19.14.26";

  } else {
    // get the IP address from the parameter/argument
    std::string ipAddressArg(argv[1]);
    ipAddress_ = ipAddressArg;

    // check the number of parameter
    if (argc > 2) {
      std::string modeString(argv[2]);

      toLower(modeString);

      // check the mode
      if (modeString.compare("trap") == 0) {
        mode = Mitrais::SNMP::TRAP;
      }
    }
  }

  Mitrais::Nemsta::SnmpUtil snmp;
  Mitrais::SNMP::ReturnStatus status = snmp.set(pdu, ipAddress_, mode);
  pdu_ = pdu;
  vbs_ = pdu.getBindingList();

  // store to database if VariableBinding vector is not empty
  if (!vbs_.empty()) {
    storeToDatabase();
  }

  return status;
}

/**
 * To lower case
 *
 * @param str
 */
void NemstaUtil::toLower(std::string& str) {
  for (int i = 0; i < str.length(); i++) {
    str[i] = tolower(str[i]);
  }
}

/**
 * Get IP Address
 *
 *@return IP Address
 */
std::string NemstaUtil::getIpAddress() { return ipAddress_; }

/**
 * Get MAC Address
 *
 *@return MAC Address
 */
std::string NemstaUtil::getMacAddress() {
  std::vector<Mitrais::SNMP::VariableBinding> vbs = pdu_.getBindingList();

  std::string macAddressOid = RFC1213_MIB_IF_PHYS_ADDRESS;

  for (std::vector<Mitrais::SNMP::VariableBinding>::iterator it = vbs.begin();
       it != vbs.end(); ++it) {
    Mitrais::SNMP::VariableBinding vb = *it;
    if (vb.getOID().oid.compare(macAddressOid) == 0) {
      vb.getValue(macAddress_);
      break;
    }
  }

  return macAddress_.substr(2, 18);
}

/**
 * Get the name of network element
 * @return Network element's name
 */
std::string NemstaUtil::getElementName() {
  std::string systemNameOid = SYSTEM_NAME;
  for (auto var : vbs_) {
    if (var.getOID().oid.compare(SYSTEM_NAME) == 0) {
      var.getValue(elementName_);
      break;
    }
  }
  return elementName_;
}

/**
 * Store SNMP Value to database
 */
void NemstaUtil::storeToDatabase() {
  DatabaseUtil databaseUtil;

  // Create database factory
  std::shared_ptr<DB::DBFactory> db = databaseUtil.create(RDBMSType::MYSQL);
  long networkElementId;

  // Check if database connection OK
  if (db) {
    // Get network element by Mac Address
    std::shared_ptr<NetworkElement> element(
        db->getNetWorkElementByMacAddress(this->getMacAddress()));

    // Assign the networkElementId
    if (element) {
      networkElementId = element->NetWorkElementId();
    } else {
      networkElementId = db->insertNetworkElement(
          this->getElementName(), this->getMacAddress(), this->getIpAddress());
    }

    for (auto var : vbs_) {
      std::string value;
      var.getValue(value);
      // Get the given OID, insert it if not exist
      std::string OIDResult = db->insertSnmpObject(
          "", var.getOID().oid, getSNMPNameByOID(var.getOID().oid));

      // Insert the SNPM value by the given network element id and oid
      db->insertSNMPValue(networkElementId, OIDResult, value, "string",
                          this->localMacAddress_);
    }
  } else {
    std::cout << "Error connecting to database" << std::endl;
  }
}
