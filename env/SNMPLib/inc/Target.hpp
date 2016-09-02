#ifndef SNMPLIB_INC_TARGET_H_
#define SNMPLIB_INC_TARGET_H_

#include <iostream>

#include "IpAddress.hpp"

namespace Mitrais
{
	namespace SNMP
	{
		/*
		 * Target class
		 */
		struct Target
		{
			/*
			 * IP Address
			 */
			IpAddress Ip;
		};
	}
}

#endif /* SNMPLIB_INC_TARGET_H_ */
