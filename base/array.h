#pragma once
#ifndef _ARRAY_H
#define _ARRAY_H
#include "stdafx.h"
namespace base
{
	template<class T> class Array
	{
	private:
		T* _pointer;
		size_t* _references;
	public:
		Array()
		{
			_references = new size_t;
			*_references = 1;
		}

		Array(T* array, size_t length)
		{
			_references = new size_t;
			*_references = 1;
			_pointer = array;
		}

		Array(Array<T>& array)
		{
			_references = array._references;
			(*_references)++;
		}

		~Array()
		{
			if(_references != NULL) (*_references)--;
		}
	};
}

#endif