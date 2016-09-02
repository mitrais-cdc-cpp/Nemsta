#ifndef SNMPLIB_INC_RETURNSTATUS_H_
#define SNMPLIB_INC_RETURNSTATUS_H_

#include <iostream>

namespace Mitrais
{
	namespace SNMP
	{
		/*
		 * Return Status class
		 */
		class ReturnStatus
		{
		public:

			/*
			 * Return Status default Constructor
			 */
			ReturnStatus();

			/*
			 * Return Status Constructor with one parameter
			 *
			 * @param error flag
			 */
			ReturnStatus(bool isError);

			/*
			 * Return Status Constructor with two parameter
			 *
			 * @param error flag
			 * @param error message
			 */
			ReturnStatus(bool isError, std::string errorMessage);

			/*
			 * Return Status Constructor with two parameter
			 *
			 * @param error flag
			 * @param error code
			 */
			ReturnStatus(bool isError, int errorCode);

			/*
			 * Return Status Constructor with three parameter
			 *
			 * @param error flag
			 * @param error message
			 * @param error code
			 */
			ReturnStatus(bool isError, std::string errorMessage, int errorCode);

			/*
			 * Return Status default destructor
			 */
			~ReturnStatus();

			/*
			 * Check the error status
			 *
			 * @return the error status
			 */
			bool isError();

			/*
			 * Get error message function
			 *
			 * @return get error message
			 */
			std::string getErrorMessage();

			/*
			 * Get error code function
			 *
			 * @return error code in integer
			 */
			int getErrorCode();

			/*
			 * Set error properties
			 *
			 * @param error flag
			 * @param error message (string)
			 * @param error code (int)
			 */
			void setError(bool isError, std::string errorMessage, int errorCode);

			/*
			 * Set is Error flag
			 *
			 * @param error flag
			 */
			void setIsError(bool isError);

			/*
			 * Set error message
			 *
			 * @param error message (string)
			 */
			void setErrorMessage(std::string errorMessage);

			/*
			 * Set error code
			 *
			 * @param error code (int)
			 */
			void setErrorCode(int errorCode);

		private:

			/*
			 * flag if the status is error or not
			 */
			bool isError_;

			/*
			 * store error message in string value
			 */
			std::string errorMessage_;

			/*
			 * store error code in int value
			 */
			int errorCode_;
		};
	}
}

#endif /* SNMPLIB_INC_RETURNSTATUS_H_ */
