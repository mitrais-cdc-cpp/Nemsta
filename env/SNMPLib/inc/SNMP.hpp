#ifndef INC_SNMP_HPP_
#define INC_SNMP_HPP_

#include <iostream>

#include "PDU.hpp"
#include "Target.hpp"
#include "MibDefinitions.hpp"
#include "SnmpMode.hpp"

namespace Mitrais
{
	namespace SNMP
	{
		class SNMP
		{
			public:

				/// Default constructor
				SNMP();

				/// Default destructor
				~SNMP();

				/**
				 * Set function
				 *
				 * @param pdu
				 * @param target
				 * @param mode
				 * @return ReturnStatus
				 */
				ReturnStatus set(PDU& pdu, Target target, SnmpMode mode);

			private:
				/**
				 * Set error function
				 *
				 * @param message
				 * @param errorCode
				 * @return
				 */
				ReturnStatus setErrorMessage(std::string message, int errorCode);
		};
	}
}

#endif /* INC_SNMP_HPP_ */
