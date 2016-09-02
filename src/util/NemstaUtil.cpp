/*
 * NemstaUtil.cpp
 *
 *  Created on: Aug 16, 2016
 *      Author: Ari Suarkadipa
 */

#include "../../inc/util/NemstaUtil.hpp"

using namespace Mitrais::Nemsta;

/*
 * Constructor of Nemsta Util class
 */
NemstaUtil::NemstaUtil()
{

}

/*
 * Destructor of Nemsta Util class
 */
NemstaUtil::~NemstaUtil()
{

}

Mitrais::SNMP::ReturnStatus NemstaUtil::capture(int argc, char* argv[], Mitrais::SNMP::PDU& pdu)
{
	std::string ipAddress;
	Mitrais::SNMP::SnmpMode mode;
	mode = Mitrais::SNMP::REQUEST;

	// there is no argments or parameter stored
	if (argc == 1)
	{
		// set the IP address as default
		ipAddress_ = "172.19.12.29";
	}
	else
	{
		// get the IP address from the parameter/argument
		std::string ipAddressArg(argv[1]);
		ipAddress_ = ipAddressArg;

		// check the number of parameter
		if (argc > 2)
		{
			std::string modeString(argv[2]);

			boost::to_lower(modeString);

			// check the mode
			if (modeString.compare("trap") == 0)
			{
				mode = Mitrais::SNMP::TRAP;
			}
		}
	}

	Mitrais::Nemsta::SnmpUtil snmp;
	Mitrais::SNMP::ReturnStatus status = snmp.set(pdu, ipAddress_, mode);

	return status;
}

/*
 * Get IP Address
 */
std::string NemstaUtil::getIpAddress()
{
	return ipAddress_;
}

/*
 * get MAC Address
 */
std::string NemstaUtil::getMacAddress()
{
	return macAddress_;
}

