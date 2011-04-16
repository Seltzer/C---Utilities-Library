/*
#ifndef LOCK_MANAGER_H_
#define LOCK_MANAGER_H_


#include "windows.h"
#include "boost/thread/shared_mutex.hpp"
#include "boost/thread/condition_variable.hpp"




/* LockManager provides a way to easily create and manage any number of 
 * reader-writer locks. It is intended that a class either encapsulate a LockManager
 * or inherit from LockManager. Note:
 *		- Locks are numbered from 1..numLocks
 *		- All locks are recursive and the number of Release calls must match the number 
 *				of pending Acquire calls before the lock is released.
 *		- The above applies unless ForceReleaseWriteLock is called
 *		- Calling AcquireReadLock then AcquireWriteLock subsequently on the same thread will 
 *			cause indefinite blocking.
 *		- RAII locks for LockManagers are provided below
 *		- Still a bit of work to be done (increasing compile time safety, handling read-write recursion etc.)
 * Example Usage:
 *		LockManager<3> lockMgr;
 *		lockMgr<1>.AcquireReadLock();
 */
/*
namespace util
{

	template<int numLocks>
	class LockManager
	{

	public:
		LockManager();

		template<int lock>
		void AcquireReadLock() const;

		template<int lock>
		void AcquireWriteLock() const;

		template<int lock>
		void ReleaseReadLock() const;

		template<int lock>
		void ReleaseWriteLock() const;

		template<int lock>
		void ForceReleaseWriteLock() const;



	private:
		mutable boost::shared_mutex rwLocks[numLocks+1];
		mutable DWORD writeLockOwners[numLocks+1];
		mutable unsigned lockCount[numLocks+1];
	};

	#include "../src/lockManager.inl"




	// RAII ReaderLock for LockManager
	template<class Lockable, int Lock>
	class ReaderLock
	{
	public:
		ReaderLock(const Lockable& lockable)
		{
			this->lockable = &lockable;
			this->lockable->AcquireReadLock<Lock>();
		}

		~ReaderLock()
		{
			lockable->ReleaseReadLock<Lock>();
		}

	private:

		const Lockable* lockable;

	};


	// RAII WriterLock for LockManager
	template<class Lockable, int Lock>
	class WriterLock
	{
	public:
		WriterLock(const Lockable& lockable)
		{
			this->lockable = &lockable;
			this->lockable->AcquireWriteLock<Lock>();
		}

		~WriterLock()
		{
			lockable->ReleaseWriteLock<Lock>();
		}

	private:

		const Lockable* lockable;

	};


}




#endif
*/