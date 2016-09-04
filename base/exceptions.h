#pragma once
#ifndef _EXCEPTIONS_H
#define _EXCEPTIONS_H
#include "../stdafx.h"
#include <exception>

namespace base
{
	class ArrayIndexOutOfBoundsException;
	class IndexOutOfBoundsException;
	class NullPointerException;
	class StringIndexOutOfBounds;

	class ArrayIndexOutOfBoundsException
	{
	private:
		const char* _msg;
	public:
		ArrayIndexOutOfBoundsException();
		ArrayIndexOutOfBoundsException(const char* msg);

		virtual const char* what() const throw();

		virtual ~ArrayIndexOutOfBoundsException();
	};

	class IndexOutOfBoundsException
	{
	private:
		const char* _msg;
	public:
		IndexOutOfBoundsException();
		IndexOutOfBoundsException(const char* msg);

		virtual const char* what() const throw();

		virtual ~IndexOutOfBoundsException();
	};

	class NullPointerException
	{
	private:
		const char* _msg;
	public:
		NullPointerException();
		NullPointerException(const char* msg);

		virtual const char* what() const throw();

		virtual ~NullPointerException();
	};

	class StringIndexOutOfBounds
	{
	private:
		const char* _msg;
	public:
		StringIndexOutOfBounds();
		StringIndexOutOfBounds(const char* msg);

		virtual const char* what() const throw();

		virtual ~StringIndexOutOfBounds();
	};
}
#endif