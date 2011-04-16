/*
#include "windows.h"
#include <deque>
#include "boost/thread/shared_mutex.hpp"
#include "boost/thread/condition_variable.hpp"


namespace util
{


/* Threadsafe buffer.
 *
 * Note:
 *		- This is quite incomplete at the moment; iterators aren't provided yet
 *		- There are blocking and nonblocking versions of push, but only nonblocking versions of pop
 *		- Use LockBuffer() before and UnlockBuffer() after reading buffer contents
 *		- Each LockBuffer() invocation (whether recursive or not) should be followed by an UnlockBuffer() call
 *//*
template<class T>
class ThreadsafeBuffer
{

public:
	ThreadsafeBuffer(unsigned maxItems);

	void LockBuffer();
	void UnlockBuffer();

	// Can throw out_of_range exception.
	// TODO reconstify return value
	T& at(unsigned position);

	// Blocks if buffer is full
	void PushBack(const T&);
	bool TryPushBack(const T&);

	// Non-blocking... note that caller will lose all buffer locks after calling one of these
	bool PopFront();
	bool PopBack();
	
	bool IsFull() const;

private:
	std::deque<T> buffer;

	// Currently used as a vanilla mutex
	boost::shared_mutex bufferMutex;
	DWORD writeLockOwner;
	unsigned lockCount;

	// Condition variable which the PushBack operation waits on
	boost::condition_variable_any bufferIsFull;
	bool isFull;

	unsigned maxItems;
};


#include "../src/threadsafeBuffer.inl"





}
*/