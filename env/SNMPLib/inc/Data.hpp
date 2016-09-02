#ifndef SNMPLIB_INC_BINDING_HPP_
#define SNMPLIB_INC_BINDING_HPP_

#include <string>

namespace Mitrais
{
	namespace SNMP
	{
		/*
		 *  Data Struct
		 */
		struct Data
		{
			/*
			 * To store int data
			 */
			int intData;

			/*
			 * To store float data
			 */
			float floatData;

			/*
			 * To store string data
			 */
			std::string stringData;
		};
	}
}




#endif /* SNMPLIB_INC_BINDING_HPP_ */
