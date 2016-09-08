#ifndef SNMPLIB_INC_VARIABLEBINDING_H_
#define SNMPLIB_INC_VARIABLEBINDING_H_

#include <iostream>

#include "OID.hpp"
#include "ReturnStatus.hpp"

namespace Mitrais
{
	namespace SNMP
	{
		/**
		 * Variable Binding class
		 */
		class VariableBinding
		{
		public:

			/**
			 * Default constructor
			 */
			VariableBinding();

			/**
			 * Default destructor
			 */
			~VariableBinding();

			/**
			 * get OID
			 *
			 * @return OID
			 */
			OID getOID();

			/**
			 * set the OID
			 *
			 * @param oid
			 */
			void setOID(OID& oid);

			/**
			 * get Value functuon
			 *
			 * @param value
			 * @return
			 */
			ReturnStatus getValue(std::string& value);

			/**
			 * Set value function
			 */
			void setValue(std::string value);

		private:

			/**
			 * Value of T
			 */
			std::string value_;

			/**
			 * The OID
			 */
			OID oid_;
		};
	}
}

#endif /* SNMPLIB_INC_VARIABLEBINDING_H_ */
