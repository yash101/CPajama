#pragma once
#ifndef _ARRAY_H
#define _ARRAY_H
#include "stdafx.h"
#include "exceptions.h"
namespace base
{
	template<class T> class Array						//ARC array
	{
	private:
		T* _pointer;									//Pointer to the array
		size_t* _references;							//Pointer to the int containing the number of references to the pointer
		size_t* _numElem;
	public:
		Array()											//Main empty initializer
		{
			_references = new size_t;					//Allocate a new int for the reference counter
			*_references = 1;							//Set it to 1 (us only)
			_numElem = new size_t;						//Allocate space for array length
		}

		Array(size_t numElem)							//Initializer which allocates certain amount of space
		{
			_references = new size_t;					//Allocate a new int for the reference counter
			*_references = 1;							//Set it to 1 (us only)
			_numElem = new size_t;						//Allocate space for the array length
			*_numElem = numElem;						//Set the array length
			_pointer = new T[numElem];					//Allocate space for the array, based off the number of elements requested
		}

		Array(Array<T> array)							//Initializer which loads data from another array, keeping into account ARC
		{
			_references = array._references;			//Synchronize the reference counter
			(*_references)++;							//Increment the reference counter
			_pointer = array._pointer;					//Synchronize the data pointer
		}

		Array<T>& operator=(Array<T> array)				//Assignment operator
		{
			_references = array._references;			//Copy over reference counter pointer
			(*_references)++;							//Increment reference counter
			_pointer = array._pointer;					//Synchronize pointer
			return *this;
		}

		~Array()										//Destructor, which does GC (if necessary)
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

		T& operator[](size_t pos)						//Access operator
		{
			if (pos >= _numElem)						//Check if within the bounds of the array or die
			{
				throw base::ArrayIndexOutOfBoundsException("T& base::Array::operator[](size_t) FATAL: Index provided outside bounds of array!");
			}
			
			return _pointer[pos];
		}

		T* operator()()									//Gives access to the bare pointer; BE CAREFUL. BAD THINGS CAN HAPPEN
		{
			return _pointer;
		}

		Array<T> allocate(size_t num)
		{
			Array<T> ret = (*this);						//We will return the old Array; If unused, the old Array will perform the GC
			(*_references--);

			_references = new size_t;					//Yes, we are overwriting the pointer
			_numElem = new size_t;						//Yes, we are overwriting the pointer
			(*_references) = 1;							//Set the default value for the reference counter (us)
			(*_numElem) = num;							//Set the number of elements in the array
			_pointer = new T[*_numElem];				//Allocate more space for our pointer
		}
	};
}

#endif