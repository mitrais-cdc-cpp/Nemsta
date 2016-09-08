#ifndef SNMPLIB_INC_RETURNSTATUS_H_
#define SNMPLIB_INC_RETURNSTATUS_H_

#include <iostream>

namespace Mitrais
{
	namespace SNMP
	{
		/**
		 * Return Status class
		 */
		class ReturnStatus
		{
		public:

			/**
			 * Return Status default Constructor
			 */
			ReturnStatus();

			/**
			 * Return Status Constructor with one parameter
			 *
			 * @param isError
			 */
			ReturnStatus(bool isError);

			/**
			 * Return Status Constructor with two parameter
			 *
			 * @param isError
			 * @param errorMessage
			 */
			ReturnStatus(bool isError, std::string errorMessage);

			/**
			 * Return Status Constructor with two parameter			 *
			 *
			 * @param isError
			 * @param errorCode
			 */
			ReturnStatus(bool isError, int errorCode);

			/**
			 * Return Status Constructor with three parameter
			 *
			 * @param isError
			 * @param errorMessage
			 * @param errorCode
			 */
			ReturnStatus(bool isError, std::string errorMessage, int errorCode);

			/**
			 * Return Status default destructor
			 */
			~ReturnStatus();

			/**
			 * Check the error status
			 *
			 * @return the error status
			 */
			bool isError();

			/**
			 * Get error message function
			 *
			 * @return error message
			 */
			std::string getErrorMessage();

			/**
			 * Get error code function
			 *
			 * @return error code in integer
			 */
			int getErrorCode();

			/**
			 * Set error properties
			 *
			 * @param isError
			 * @param errorMessage
			 * @param errorCode
			 */
			void setError(bool isError, std::string errorMessage, int errorCode);

			/**
			 * Set is Error flag
			 *
			 * @param isError
			 */
			void setIsError(bool isError);

			/**
			 * Set error message
			 *
			 * @param errorMessage
			 */
			void setErrorMessage(std::string errorMessage);

			/**
			 * Set error code
			 *
			 * @param errorCode
			 */
			void setErrorCode(int errorCode);

		private:

			/**
			 * flag if the status is error or not
			 */
			bool isError_;

			/**
			 * store error message in string value
			 */
			std::string errorMessage_;

			/**
			 * store error code in int value
			 */
			int errorCode_;
		};
	}
}

#endif /* SNMPLIB_INC_RETURNSTATUS_H_ */
