#include "../stdafx.h"
#include "inputstream.h"

int io::InputStream::available()
{
	return 0;
}

void io::InputStream::close()
{
	return;
}

void io::InputStream::mark(int limit)
{
	return;
}

bool io::InputStream::markSupported()
{
	return false;
}

int io::InputStream::read()
{
	return 0;
}

int io::InputStream::read(char* buffer, int len)
{
	return 0;
}

int io::InputStream::read(char* buffer, int offset, int length)
{
	return 0;
}

void io::InputStream::reset()
{
	return;
}

long io::InputStream::skip(long n)
{
	return 0;
}