#pragma once
#ifndef _CLOSEABLE_H
#define _CLOSEABLE_H

namespace io
{
	/* May throw /io/ioexception.h -> io::IOException */
	/* If an input/output stream is closeable, it must inherit from this */
	class Closeable
	{
	public:
		virtual void close();
	};
}

#endif