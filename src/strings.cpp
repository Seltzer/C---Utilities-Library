#include "../include/utilities.h"

#include <sstream>
#include <cstdarg>
#include <algorithm>



namespace util
{




std::string indent(short tabs)
{
	std::stringstream ss;
	
	for (short i = 0; i < tabs; i++)
	{
		ss << "\t";
	}

	return ss.str();
}

std::string formatString(std::string inputString,...)
{
	va_list varargs;
	va_start(varargs, inputString);

	std::string returnString(formatString(inputString, varargs));

	va_end(varargs);
			
	return returnString;
}




// TODO Protect against buffer overflow
// TODO Either improve heuristic to consider # of varargs or use a version of vsnprint which calculates required size
std::string formatString(std::string inputString, va_list varargs)
{
	const char* inputStringAsChars = inputString.c_str();
	
	// Blind heuristic for estimating required buffer capacity
	size_t bufferSize = std::max<unsigned>(1024, inputString.size() * 4);

	while(true)
	{
		char* buffer = new char[bufferSize];

		if (vsnprintf_s(buffer, bufferSize, _TRUNCATE, inputStringAsChars, varargs) != -1)
		{
			std::string returnString(buffer);
			delete[] buffer;

			return returnString;
		}

		// Buffer isn't big enough, so increase its capacity and try again
		delete[] buffer;
		bufferSize *= 2;
	}
}




}

