#ifndef NEMSTA_INC_NEMSTAUTIL_H_
#define NEMSTA_INC_NEMSTAUTIL_H_

#include <iostream>

#include "SnmpUtil.hpp"

#include "../../env/SNMPLib/inc/PDU.hpp"
#include "../../env/SNMPLib/inc/ReturnStatus.hpp"
#include "../../env/SNMPLib/inc/SnmpMode.hpp"

namespace Mitrais
{
	namespace Nemsta
	{
		class NemstaUtil
		{
			public:
				/*
				 * Constructor of Nemsta Util class
				 */
				NemstaUtil();
				
				/*
				 * Default desctructor
				 */
				~NemstaUtil();

				/*
				 * Capture the SNMP Value
				 *
				 *@param number of argment (argc)
				 *@param string parameter
				 *@param PDU&
				 *
				 *@return Return Status
				 */
				Mitrais::SNMP::ReturnStatus capture(int argc, char* argv[], Mitrais::SNMP::PDU& pdu);
				
				/*
				 * Get IP Address
				 *
				 *@return IP Address
				 */
				std::string getIpAddress();
				
				/*
				 * Get MAC Address
				 *
				 *@return MAC Address
				 */
				std::string getMacAddress();

			private:
				std::string ipAddress_;
				std::string macAddress_;
				Mitrais::SNMP::PDU pdu_;

				void toLower(std::string& str);
		};
	}
}

#endif /* NEMSTA_INC_NEMSTAUTIL_H_ */
