#ifndef NEMSTA_INC_NEMSTAUTIL_H_
#define NEMSTA_INC_NEMSTAUTIL_H_

#include <iostream>
#include <memory>

#include "SnmpUtil.hpp"

#include "../../env/SNMPDao/inc/DBFactory.hpp"
#include "../../env/SNMPDao/inc/DataAccess.hpp"
#include "../../env/SNMPDao/inc/Entity/NetworkElement.hpp"
#include "../../env/SNMPLib/inc/PDU.hpp"
#include "../../env/SNMPLib/inc/ReturnStatus.hpp"
#include "../../env/SNMPLib/inc/SnmpMode.hpp"
#include "DatabaseUtil.hpp"

namespace Mitrais {
namespace Nemsta {
class NemstaUtil {
 public:
  /**
   * Constructor of Nemsta Util class
   */
  NemstaUtil();

  /**
   * Default desctructor
   */
  ~NemstaUtil();

  /**
   * Capture the SNMP Value
   *
   * @param argc
   * @param argv
   * @param pdu
   * @return
   */
  Mitrais::SNMP::ReturnStatus capture(int argc, char* argv[],
                                      Mitrais::SNMP::PDU& pdu);

  /**
   * Get IP Address
   *
   *@return IP Address
   */
  std::string getIpAddress();

  /**
   * Get MAC Address
   *
   *@return MAC Address
   */
  std::string getMacAddress();

 private:
  std::string ipAddress_;
  std::string macAddress_;
  Mitrais::SNMP::PDU pdu_;

  /**
   * VariableBinding vector
   */
  std::vector<Mitrais::SNMP::VariableBinding> vbs_;

  /**
   * To lower case
   *
   * @param str
   */
  void toLower(std::string& str);

  /**
   * Store SNMP Value to database
   */
  void storeToDatabase();
};
}
}

#endif /* NEMSTA_INC_NEMSTAUTIL_H_ */
