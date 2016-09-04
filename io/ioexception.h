#pragma once
#ifndef _IOEXCEPTION_H
#define _IOEXCEPTION_H

#include <exception>

namespace io
{
	class IOException : public std::exception
	{
	private:
		const char* _msg;
	public:
		IOException() : _msg(NULL)
		{}
		IOException(const char* message) : _msg(message)
		{}

		virtual const char* what() const throw()
		{
			return _msg;
		}

		virtual ~IOException()
		{}
	};
}

#endif