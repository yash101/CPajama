#include "stdafx.h"
// CPajama.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "base/array.h"

class big
{
public:
	long a, b, c, d, e, f, g;
};

int main()
{
	base::Array<big> array(10240);
	for (size_t i = 0; i < 100; i++)
	{
		base::Array<big> array2 = array.allocate(i * 10000000);
	}
	return 0;
}

