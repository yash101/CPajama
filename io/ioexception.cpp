#include "../stdafx.h"
#include "ioexception.h"

io::IOException::IOException() :
	_msg("An IOException was thrown!")
{}

io::IOException::IOException(const char* message) :
	_msg(message)
{}

const char* io::IOException::what() const throw()
{
	return _msg;
}

io::IOException::~IOException()
{
}