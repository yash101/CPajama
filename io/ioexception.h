#pragma once
#ifndef _IOEXCEPTION_H
#define _IOEXCEPTION_H
#include "../stdafx.h"
#include <exception>

namespace io
{
	class IOException : public std::exception
	{
	private:
		const char* _msg;
	public:
		IOException();
		IOException(const char* message);
		virtual const char* what() const throw();
		virtual ~IOException();
	};
}

#endif