#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "lua.h"
#include "lauxlib.h"
#include "head.h"

void call_va(lua_State *L, const char *func, const char *sig, ...)
{
	lua_getglobal(L, func);
	if (!lua_isfunction(L, -1))
		error(L, "lua_isfunction error");

	va_list va;
	va_start(va, sig);
	int narg,nres;
	for (narg = 0; *sig; narg++)
	{
		switch (*sig++)
		{
		case 'd':
			lua_pushnumber(L, va_arg(va, double));
			break;
		case 'i':
			lua_pushinteger(L, va_arg(va, int));
			break;
		case 's':
			lua_pushstring(L, va_arg(va, char*));
			break;
		case '>':
			goto endargs;
		default:
			error(L, "invalid sig");
		}
	}
endargs:
	
	nres = strlen(sig);
	if (LUA_OK != lua_pcall(L, narg, nres, 0))
		error(L, "lua_pcall error");
	nres = -nres;
	while (*sig)
	{
		switch (*sig++)
		{
		case 'd':
			*va_arg(va, double*) = lua_tonumber(L,nres);
			break;
		case 'i':
			*va_arg(va, int*) = lua_tonumber(L, nres);
			break;
		case 's':
			*va_arg(va, char**) = lua_tostring(L, nres);
			break;
		default:
			error(L, "invalid sig");
		}
		nres++;
	}
	lua_settop(L, 0);
	va_end(va);
}

//int main(int argc, char *argv[])
//{
//	lua_State *L = luaL_newstate();
//	loadfile(L, "config");
//	int res;
//	call_va(L, "f", "ii>i", 1, 2, &res);
//	printf("res = %d", res);
//	getchar();
//	return 0;
//}