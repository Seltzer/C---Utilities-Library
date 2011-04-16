/* C++ utilities library (utilities-lib\utilities-lib.sln)
 *
 * Theoretically cross-platform
 */

#ifndef UTILITIES_H_
#define UTILITIES_H_



// Stdlib includes
#include <string>
#include <sstream>

// Other components of utilities-lib (for now, include them all and give the user no choice in the matter muahahaha)
#include "macros.h"
#include "dataStructures.h"
#include "templateMP.h"
#include "process.h"
#include "enum.h"
#include "exceptions.h"
#include "lockManager.h"



namespace util
{


// Random Numbers
void platformSeed();

int generateRandomNumber(int min, int max);


// Strings
std::string indent(short tabs);


template<class T>
std::string ToString(const T& value) 
{
	std::stringstream ss;
	ss << value;
	return ss.str();
}


std::string intToString(int);
std::string pointerToString(void*);

std::string formatString(std::string inputString, ...);
std::string formatString(std::string inputString, va_list varargs);
	
// Misc
// Time in seconds
void PlatformSleep(float time);


}



#endif