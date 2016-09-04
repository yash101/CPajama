// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stddef.h>
#ifdef _WIN32
#ifdef _WIN64
#define WINDOWS 1
#define WINDOWS64 2
#define ARCH64 3
#define OS WINDOWS 4
#else
#define WINDOWS 1
#define WINDOWS32 5
#define ARCH32 6
#endif
#else
#define POSIX 7
#endif


// TODO: reference additional headers your program requires here
