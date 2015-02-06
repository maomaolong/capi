#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include "lua.h"
#include "head.h"

void error(lua_State *L, const char *fmt, ...)
{
	va_list va;
	va_start(va, fmt);
	vfprintf(stderr, fmt, va);
	va_end(va);
	lua_close(L);
	exit(EXIT_FAILURE);
}