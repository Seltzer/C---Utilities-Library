/*
#ifndef LOCK_MANAGER_INL_
#define LOCK_MANAGER_INL_


#include "lockManager.h"


template<int numLocks>
LockManager<numLocks>::LockManager()
{
	for (int i = 0; i < numLocks; i++)
	{
		//rwLocks[i] = boost::shared_mutex;
		lockCount[i] = 0;
		writeLockOwners[i] = NULL;
	}
}


template<int numLocks>
template<int lock>
void LockManager<numLocks>::AcquireReadLock() const
{
	if (writeLockOwners[lock] == GetCurrentThreadId())
		return;

	rwLocks[lock].lock_shared();
}

template<int numLocks>
template<int lock>
void LockManager<numLocks>::AcquireWriteLock() const
{
	if (writeLockOwners[lock] == GetCurrentThreadId())
	{
		++lockCount[lock];
	}
	else
	{
		rwLocks[lock].lock_upgrade();
		rwLocks[lock].unlock_upgrade_and_lock();
		writeLockOwners[lock] = GetCurrentThreadId();
		lockCount[lock] = 1;
	}
}

template<int numLocks>
template<int lock>
void LockManager<numLocks>::ReleaseReadLock() const
{
	if (GetCurrentThreadId() != writeLockOwners[lock])
		rwLocks[lock].unlock_shared();
}

template<int numLocks>
template<int lock>
void LockManager<numLocks>::ReleaseWriteLock() const
{
	if (GetCurrentThreadId() != writeLockOwners[lock])
		return;

	if (--lockCount[lock] == 0)
	{
		writeLockOwners[lock] = NULL;
		rwLocks[lock].unlock();
	}
}


template<int numLocks>
template<int lock>
void LockManager<numLocks>::ForceReleaseWriteLock() const
{
	if (GetCurrentThreadId() != writeLockOwners[lock])
		return;

	writeLockOwners[lock] = NULL;
	lockCount[lock] = 0;

	rwLocks[lock].unlock();
}




#endif
*/