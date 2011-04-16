#include <cassert>
#include <iostream>

// Keystroke friendly print macro
#define prt(x) std::cout << x << std::endl;

// Variable name/value printing macro
#define prtVar(x) std::cout << #x " = '" << x << "'" << std::endl;

// Print location in code
#define WHERES_WALLY std::cout << "Inside " << __FUNCTION__ << " at " << __LINE__ << std::endl;


// ASSERT macro:
// If NDEBUG is defined (i.e. release mode), (condition) code will still execute but 
// will not throw an assertion if the condition is false
#ifndef NDEBUG
	#include <cassert>

	#define UL_ASSERT(condition)															\
	{																						\
		if(!(condition))																	\
		{																					\
			std::cerr << "Assertion failed at " << __FILE__ << ":" << __LINE__;				\
			std::cerr << " inside " << __FUNCTION__ << std::endl;							\
			std::cerr << "Condition: " << #condition;										\
			abort();																		\
		}																					\
	}
#else
	#define UL_ASSERT(condition) (condition)	
#endif







