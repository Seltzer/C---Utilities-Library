#include "../include/utilities.h"

#include <cassert>


#ifdef _WIN32
	#include <windows.h>
#else
	#include <sys/time.h>
#endif


namespace util
{


bool seeded = false;


void platformSeed()
{
	assert(!seeded);


	#ifdef _WIN32
		//srand(time(NULL));
		srand(GetTickCount());
	#else
		struct timeval;
		gettimeofday(&time,NULL);
	
		srand((time.tv_sec * 1000) + (time.tv_usec / 1000));
	#endif


	seeded = true;
}



int generateRandomNumber(int min, int max)
{
	if (!seeded)
		platformSeed();
	

	int randomNumber = min + (int) (rand() / (RAND_MAX + 1.0) * (max + 1 - min));
	return randomNumber;
}









}


