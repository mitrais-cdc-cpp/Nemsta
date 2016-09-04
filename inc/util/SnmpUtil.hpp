#ifndef NEMSTA_INC_SNMPUTIL_H_
#define NEMSTA_INC_SNMPUTIL_H_

#include <iostream>
#include <vector>

#include "../../env/SNMPLib/inc/SNMP.hpp"
#include "../../env/SNMPLib/inc/OID.hpp"
#include "../../env/SNMPLib/inc/MibDefinitions.hpp"
#include "../../env/SNMPLib/inc/SnmpMode.hpp"
#include "../../env/SNMPLib/inc/PDU.hpp"
#include "../../env/SNMPLib/inc/VariableBinding.hpp"
#include "../../env/SNMPLib/inc/ReturnStatus.hpp"
#include "../../env/SNMPLib/inc/Target.hpp"

namespace Mitrais
{
	namespace Nemsta
	{
		class SnmpUtil
		{
		public:
			/*
			 * Default constructor
			 */
			SnmpUtil();

			/*
			 * Default desctructor
			 */
			~SnmpUtil();

			/*
			 * Set the SNMP
			 *
			 * @param PUD
			 * @param IpAddress
			 * @param mode
			 *
			 * @return Return status
			 */
			Mitrais::SNMP::ReturnStatus set(Mitrais::SNMP::PDU& pdu, std::string ipAddress, Mitrais::SNMP::SnmpMode mode);
			
		private:			
			/*
			 * Set Variable Binding
			 *
			 * @param OID
			 * @return Variable Binding
			 */
			Mitrais::SNMP::VariableBinding setVariableBinding(std::string oid);
		};
	}
}

#endif /* NEMSTA_INC_NEMSTAUTIL_H_ */
