#include "ARC.h"

base::ARC::ARC() :
	_allocations(NULL),								//Initialize everything as a NULL pointer
	_allocSize(NULL),								//...
	_refct(NULL)									//...
{
	_refct = new size_t;							//Allocate memory for internal housekeeping
	_allocSize = new size_t;						//...

	*_refct = 1;									//Reset reference counter
	*_allocSize = 0;								//Reset allocation table size
}

base::ARC::~ARC()
{
	(*_refct)--;									//Decrement reference counter
	if (*_refct <= 0)								//Check if GC required
	{
		delete _refct;								//Delete the reference counter
		if (_allocations != NULL)					//Check if we even used the allocation table
		{
			for (size_t i = 0; i < *_allocSize; i++)//Delete each allocation, one-by-one
			{
				delete _allocations[i];				//...
			}

			delete[] _allocations;					//Delete allocation table
			delete _allocSize;						//Delete the allocation size
		}
	}
}

void* base::ARC::alloc(size_t len)
{
	void* ptr = new char[len];						//Allocate space for our new pointer
	trackPointer(ptr);								//Add the pointer into the allocation table
	return ptr;										//Return access to the data we just allocated
}

void base::ARC::trackPointer(void* ptr)
{
	if (_allocations == NULL)						//Create new allocation table if it never existed
	{
		_allocations = new void*[1];
		_allocations[0] = ptr;
	}

	(*_allocSize)++;								//Our allocation table is one larger now
	void** _newTable = new void*[*_allocSize];		//Allocate space for our new allocation table
	memcpy((void*)_newTable, _allocations, sizeof(void*) * ((*_allocSize) - 1));//Copy old allocation table data to new allocation table
	delete[] _allocations;							//GC
	_allocations = _newTable;						//Assign our newly-created table
	_allocations[(*_allocSize) - 1] = ptr;			//Add our new pointer into the new (and improved) table
}

void base::ARC::untrackPointer(void* ptr)
{
	bool exists = false;							//Flag to check if pointer even exists
	for (size_t i = 0; i < *_allocSize; i++)
	{
		if()
	}
}