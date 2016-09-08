#ifndef SNMPLIB_INC_IPADDRESS_H_
#define SNMPLIB_INC_IPADDRESS_H_

#include <iostream>

namespace Mitrais
{
	namespace SNMP
	{
		/**
		 * IP address struct
		 */
		struct IpAddress
		{
			/**
			 * IP Address
			 */
			std::string IpAddress;
		};
	}
}

#endif /* SNMPLIB_INC_IPADDRESS_H_ */
