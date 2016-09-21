#ifndef NEMSTA_INC_SNMPUTIL_H_
#define NEMSTA_INC_SNMPUTIL_H_

#include <iostream>
#include <string>
#include <vector>

#include "../../env/SNMPLib/inc/MibDefinitions.hpp"
#include "../../env/SNMPLib/inc/OID.hpp"
#include "../../env/SNMPLib/inc/PDU.hpp"
#include "../../env/SNMPLib/inc/ReturnStatus.hpp"
#include "../../env/SNMPLib/inc/SNMP.hpp"
#include "../../env/SNMPLib/inc/SnmpMode.hpp"
#include "../../env/SNMPLib/inc/Target.hpp"
#include "../../env/SNMPLib/inc/VariableBinding.hpp"

#include <cstdio>
#include <cstdlib>
#include <cstring>

namespace Mitrais {
namespace Nemsta {
class SnmpUtil {
 public:
  /**
   * Default constructor
   */
  SnmpUtil();

  /*
   * Default desctructor
   */
  ~SnmpUtil();

  /**
   * Set the SNMP
   *
   * @param pdu
   * @param ipAddress
   * @param mode
   * @return
   */
  Mitrais::SNMP::ReturnStatus set(Mitrais::SNMP::PDU& pdu,
                                  std::string ipAddress,
                                  Mitrais::SNMP::SnmpMode mode);

  /**
   * Function to get local Mac Address
   * @return Mac Address
   */
  std::string getLocalMacAddress();

 private:
  /**
   * Set Variable Binding
   *
   * @param oid
   * @return
   */
  Mitrais::SNMP::VariableBinding setVariableBinding(std::string oid);
};
}
}

#endif /* NEMSTA_INC_NEMSTAUTIL_H_ */
