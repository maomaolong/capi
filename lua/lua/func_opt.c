#include <stdio.h>
#include "lua.h"
#include "lauxlib.h"
#include "head.h"

int f(lua_State *L, int a, int b)
{
	loadfile(L, "config");
	lua_getglobal(L, "f");
	if (!lua_isfunction(L, -1))
		error(L, "f is not a function");
	lua_pushnumber(L, a);
	lua_pushnumber(L, b);
	if (LUA_OK != lua_pcall(L, 2, 1, 0))
		error(L, "lua_pcall error");
	int isnum;
	int result = lua_tonumberx(L, -1, &isnum);
	if (!isnum)
		error(L, "function f must return a number value");
	lua_pop(L, 1);
	return result;
}

//int main(int argc, char *argv[])
//{
//	lua_State *L = luaL_newstate();
//	printf("the result is:%d", f(L,1, 2));
//	getchar();
//	return 0;
//}