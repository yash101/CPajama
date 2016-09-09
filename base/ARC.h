#pragma once
#ifndef _ARC_H
#define _ARC_H
#include "../stdafx.h"
namespace base
{
	class ARC
	{
	private:
		virtual ~ARC();							//Destroys the ARC base, releasing all of its allocated memory
		void** _allocations;					//Holds all of the allocations completed by this object
		size_t* _allocSize;						//_allocations' array length
		size_t* _refct;							//Reference counter
	protected:
		void* alloc(size_t len);				//Allocates a block of memory (can't be deallocated until class is destroyed)
		void trackPointer(void* pointer);		//Adds a pointer into the internal allocation table; will be deleted when _refct is zeroed
		void untrackPointer(void* pointer);
	public:
		ARC();									//Default constructor. Must be called to initialize ARC
	};
}

#endif