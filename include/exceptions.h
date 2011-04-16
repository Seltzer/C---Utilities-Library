/* C++ utilities library - exception handling framework (in progress)
 */




#include <string>


namespace util
{


	
	
template<int errorCode>
std::string static exceptionMessage(std::string exMessage = std::string(""))
{
	static std::string message = exMessage;

	return message;
}

template<int errorCode>
std::string getFormattedExceptionMessage(int error, ...)
{
	assert(errorCode == error);

	va_list varargs;
	va_start(varargs,error);

	std::string returnString(formatString(exceptionMessage<errorCode>()));

	va_end(varargs);

	return returnString;
}

template<int errorCode>
std::string setExceptionMessage(std::string message)
{
	if (message != exceptionMessage<errorCode>(message))
		assert(false);
}




}
 


