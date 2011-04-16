// Template method implementations for ThreadsafeBuffer<T>
/*

template<class T>
ThreadsafeBuffer<T>::ThreadsafeBuffer(unsigned maxItems)
	: writeLockOwner(NULL), lockCount(0), isFull(false), maxItems(maxItems)
{
	UL_ASSERT(maxItems > 0);
}

template<class T>
bool ThreadsafeBuffer<T>::IsFull() const 
{
	return isFull;
}

template<class T>
void ThreadsafeBuffer<T>::LockBuffer()
{
	if (writeLockOwner == GetCurrentThreadId())
	{
		++lockCount;
		return;
	}		
	
	bufferMutex.lock();
	lockCount = 1;
	writeLockOwner = GetCurrentThreadId();
}

template<class T>
void ThreadsafeBuffer<T>::UnlockBuffer()
{
	if (writeLockOwner != GetCurrentThreadId())
		return;

	if (--lockCount == 0)
	{
		writeLockOwner = NULL;
		bufferMutex.unlock(); 
	}
}


template<class T>
T& ThreadsafeBuffer<T>::at(unsigned position)  
{
	//LockBuffer();
	UL_ASSERT(position <= buffer.size());
	return buffer.at(position);
	//UnlockBuffer();
}


template<class T>
void ThreadsafeBuffer<T>::PushBack(const T& value)
{
	//LockBuffer();

	while(isFull);
	//	bufferIsFull.wait<boost::shared_mutex>(bufferMutex);

	buffer.push_back(value);
	isFull = buffer.size() == maxItems;

	//UnlockBuffer();
}

template<class T>
bool ThreadsafeBuffer<T>::TryPushBack(const T& value)
{
	//LockBuffer();

	if (isFull)
		return false;

	buffer.push_back(value);
	isFull = buffer.size() == maxItems;

	//UnlockBuffer();
	return true;
}


template<class T>
bool ThreadsafeBuffer<T>::PopFront()
{
	//LockBuffer();
	//bufferMutex.lock();
	
	if (buffer.size())
	{
		buffer.pop_front();
		isFull = false;

	//	bufferMutex.unlock();
	//	bufferIsFull.notify_all();
		return true;
	}

	// Forcibly unlock
	lockCount = 0;
	writeLockOwner = NULL;
	//bufferMutex.unlock();

	return false;
}

template<class T>
bool ThreadsafeBuffer<T>::PopBack()
{
	//LockBuffer();
	//bufferMutex.lock();
	
	if (buffer.size())
	{
		buffer.pop_back();
		isFull = false;

		//bufferMutex.unlock();
		//bufferIsFull.notify_all();
		return true;
	}

	// Forcibly unlock
	lockCount = 0;
	writeLockOwner = NULL;
	//bufferMutex.unlock();
	return false;
}*/