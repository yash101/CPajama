#include "../stdafx.h"
#include "exceptions.h"

base::ArrayIndexOutOfBoundsException::ArrayIndexOutOfBoundsException() :
	_msg("An ArrayIndexOutOfBoundsException was thrown!")
{
}

base::ArrayIndexOutOfBoundsException::ArrayIndexOutOfBoundsException(const char* msg) :
	_msg(msg)
{
}

base::ArrayIndexOutOfBoundsException::~ArrayIndexOutOfBoundsException()
{
}

const char* base::ArrayIndexOutOfBoundsException::what() const throw()
{
	return _msg;
}


base::IndexOutOfBoundsException::IndexOutOfBoundsException() :
	_msg("An IndexOutOfBoundsException was thrown!")
{
}

base::IndexOutOfBoundsException::IndexOutOfBoundsException(const char* msg) :
	_msg(msg)
{
}

base::IndexOutOfBoundsException::~IndexOutOfBoundsException()
{
}

const char* base::IndexOutOfBoundsException::what() const throw()
{
	return _msg;
}


base::NullPointerException::NullPointerException() :
	_msg("A NullPointerException was thrown!")
{
}

base::NullPointerException::NullPointerException(const char* msg) :
	_msg(msg)
{
}

base::NullPointerException::~NullPointerException()
{
}

const char* base::NullPointerException::what() const throw()
{
	return _msg;
}


base::StringIndexOutOfBounds::StringIndexOutOfBounds() :
	_msg("A StringIndexOutOfBounds was thrown!")
{
}

base::StringIndexOutOfBounds::StringIndexOutOfBounds(const char* msg) :
	_msg(msg)
{
}

base::StringIndexOutOfBounds::~StringIndexOutOfBounds()
{
}

const char* base::StringIndexOutOfBounds::what() const throw()
{
	return _msg;
}