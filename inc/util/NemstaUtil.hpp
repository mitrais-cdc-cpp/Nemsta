#ifndef NEMSTA_INC_NEMSTAUTIL_H_
#define NEMSTA_INC_NEMSTAUTIL_H_

#include <iostream>
#include <boost/algorithm/string.hpp>

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
				NemstaUtil();
				~NemstaUtil();

				Mitrais::SNMP::ReturnStatus capture(int argc, char* argv[], Mitrais::SNMP::PDU& pdu);
				std::string getIpAddress();
				std::string getMacAddress();

			private:
				std::string ipAddress_;
				std::string macAddress_;

		};
	}
}

#endif /* NEMSTA_INC_NEMSTAUTIL_H_ */
