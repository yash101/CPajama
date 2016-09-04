#pragma once
#ifndef _ARRAY_H
#define _ARRAY_H
#include "stdafx.h"
namespace base
{
	template<class T> class Array
	{
	private:
		T* _pointer;									//Pointer to the array
		size_t* _references;							//Pointer to the int containing the number of references to the pointer
		size_t* _numElem;
	public:
		Array()
		{
			_references = new size_t;					//Allocate a new int for the reference counter
			*_references = 1;							//Set it to 1 (us only)
			_numElem = new size_t;						//Allocate space for array length
		}

		Array(size_t numElem)
		{
			_references = new size_t;					//Allocate a new int for the reference counter
			*_references = 1;							//Set it to 1 (us only)
			_numElem = new size_t;						//Allocate space for the array length
			*_numElem = numElem;						//Set the array length
			_pointer = new T[numElem];					//Allocate space for the array, based off the number of elements requested
		}

		Array(Array<T>& array)
		{
			_references = array._references;			//Synchronize the reference counter
			(*_references)++;							//Increment the reference counter
			_pointer = array._pointer;					//Synchronize the data pointer
		}

		~Array()
		{
			if (_references != NULL)					//Check to make sure we even have a reference counter
			{
				(*_references)--;						//Decrement the reference counter
				if (*_references <= 0)					//Check if there are zero references; if so, deallocate all memory
				{
					delete[] _pointer;					//Deallocate memory
					delete _references;					//...
					delete _numElem;					//...	
				}
			}
		}

		T& operator[](size_t pos)
		{
			if (pos >= _numElem)
			{
			}
			
			return _pointer[pos];
		}

		T* operator()()
		{
			return _pointer;
		}
	};
}

#endif