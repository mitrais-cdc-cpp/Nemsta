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

/*
 * Capture the SNMP Value
 *
 *@param number of argment (argc)
 *@param string parameter
 *@param PDU&
 *
 *@return Return Status
 */
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

			toLower(modeString);

			// check the mode
			if (modeString.compare("trap") == 0)
			{
				mode = Mitrais::SNMP::TRAP;
			}
		}
	}

	Mitrais::Nemsta::SnmpUtil snmp;
	Mitrais::SNMP::ReturnStatus status = snmp.set(pdu, ipAddress_, mode);
	pdu_ = pdu;

	return status;
}

/**
 * Converts string to lowercase
 *
 * @param str the string
 */
void NemstaUtil::toLower(std::string& str)
{
	for(int i=0; i<str.length(); i++)
	{
		str[i] = tolower(str[i]);
	}
}

/*
 * Get IP Address
 *
 *@return IP Address
 */
std::string NemstaUtil::getIpAddress()
{
	return ipAddress_;
}

/*
 * Get MAC Address
 *
 *@return MAC Address
 */
std::string NemstaUtil::getMacAddress()
{
	std::vector<Mitrais::SNMP::VariableBinding> vbs = pdu_.getBindingList();

	std::string macAddressOid = RFC1213_MIB_IF_PHYS_ADDRESS;
	
	for (std::vector<Mitrais::SNMP::VariableBinding>::iterator it = vbs.begin(); it != vbs.end(); ++it)
	{
		Mitrais::SNMP::VariableBinding vb = *it;
		if (vb.getOID().oid.compare(macAddressOid) == 0)
		{
			vb.getValue(macAddress_);
			break;
		}
	}
	
	return macAddress_.substr(2, 18);
}

