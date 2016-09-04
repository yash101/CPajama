#pragma once
#ifndef _INPUTSTREAM_H
#define _INPUTSTREAM_H

namespace io
{
	class InputStream
	{
	public:
		virtual int available();
		virtual void close();
		virtual void mark(int limit);
		virtual bool markSupported();
		virtual int read();
		virtual int read(char* buffer, int len);
		virtual int read(char* buffer, int offset, int length);
		virtual void reset();
		virtual long skip(long n);
	};
}

#endif
