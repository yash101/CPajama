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

		Array(T* ptr, size_t* ref, size_t* nel) :		//Initialzer which initializes by values passed to it
			_pointer(ptr),								//Set the variable values
			_references(ref),							//...
			_numElem(nel)								//...
		{
		}
	public:
		Array()	:										//Main empty initializer
			_pointer(NULL),								//Initialize everything to NULL initially
			_references(NULL),							//...
			_numElem(NULL)								//...
		{
			_references = new size_t;					//Allocate a new int for the reference counter
			_numElem = new size_t;						//Allocate space for array length

			*_references = 1;							//We are the only reference
			*_numElem = 0;								//We have zero elements
		}

		Array(size_t numElem) :							//Initializer which allocates certain amount of space
			_pointer(NULL),								//Initialize everything to NULL initially
			_references(NULL),							//...
			_numElem(NULL)								//...
		{
			_references = new size_t;					//Allocate a new int for the reference counter
			_numElem = new size_t;						//Allocate space for the array length

			*_references = 1;							//We are the only reference
			*_numElem = numElem;						//Set the array length

			_pointer = new T[numElem];					//Allocate space for the array, based off the number of elements requested
		}

		Array(Array<T>& array) :						//Initializer which loads data from another array, keeping into account ARC
			_references(array._references),
			_pointer(array._pointer),
			_numElem(array._numElem)
		{
			(*_references)++;							//Increment the reference counter
		}

		Array<T>& operator=(Array<T> array)				//Assignment operator
		{
			_references = array._references;			//Copy over reference counter pointer
			_pointer = array._pointer;					//Synchronize pointer
			_numElem = array._numElem;					//Synchronize the number of elements

			(*_references)++;							//Increment reference counter

			return *this;
		}

		~Array()										//Destructor, which does GC (if necessary)
		{
			if (_references != NULL)					//Check to make sure we even have a reference counter
			{
				(*_references)--;						//Decrement the reference counter
				if (*_references <= 0)					//Check if there are zero references; if so, deallocate all memory
				{
					delete _references;					//Deallocate memory

					if(_pointer != NULL)				//Check before deallocation
						delete[] _pointer;				//Deallocate memory

					if(_numElem != NULL)				//Check before deallocation
						delete _numElem;				//Deallocate memory

					_references = NULL;					//Set as NULL, just to make errors more distinguishable
					_pointer = NULL;					//...
					_numElem = NULL;					//...
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
		{												//Note, pointer will be NULL if no data has been allocated
			return _pointer;
		}

		Array<T> allocate(size_t num)					//Allocates a block of memory
		{
			(*_references)--;							//Decrement the reference because we are going to overwrite our pointers
			Array<T> ret(_pointer, _references, _numElem);//We will return the old Array; If unused, the old Array will perform the GC

			_references = new size_t;					//Yes, we are overwriting the pointer
			_numElem = new size_t;						//Yes, we are overwriting the pointer

			(*_references) = 1;							//Set the default value for the reference counter (us)
			(*_numElem) = num;							//Set the number of elements in the array

			_pointer = new T[*_numElem];				//Allocate space for our pointer, replacing its old value

			return ret;									//Return the newly-created object containing the old Array
		}

		Array<T> clone(size_t num)						//Clones the Array - Creates a new array with a copy of the data and a reset reference counter
		{
			Array<T> ret(_numElem);						//Create the Array, and allocate space for _numElem elements

			if (ret() != NULL)							//Check to make sure the pointer is not null
			{
				memcpy(ret(), _pointer, _numElem * sizeof(T));//Copy over the memory
			}

			return ret;									//Return the newly constructed Array
		}
	};
}

#endif