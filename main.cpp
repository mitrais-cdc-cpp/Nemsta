#include <iostream>

#include "inc/util/NemstaUtil.hpp"
#include "env/SNMPLib/inc/PDU.hpp"
#include "env/SNMPLib/inc/ReturnStatus.hpp"

using namespace Mitrais::SNMP;
using namespace Mitrais::Nemsta;

int main(int argc, char* argv[])
{
	NemstaUtil nemsta;
	PDU pdu;
	ReturnStatus status = nemsta.capture(argc, argv, pdu);
	std::string macAddress = nemsta.getMacAddress();

	std::cout << std::endl;
	std::cout << "IP Address  : "<< nemsta.getIpAddress()<<std::endl;
	std::cout << "MAC Address : "<< nemsta.getMacAddress()<<std::endl;

	return 0;
}
