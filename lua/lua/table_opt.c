#include <stdio.h>
#include "lua.h"
#include "lauxlib.h"
#include "head.h"
#define MAX_COLOR 255
int getcolorfield(lua_State *L, const char *key)
{
	double result;
	//lua_pushstring(L, key);
	//lua_gettable(L, -2);
	lua_getfield(L, -1, key);
	if (!lua_isnumber(L, -1))
		error(L, "get color is not a number value");
	result = lua_tonumber(L, -1);
	lua_pop(L, 1);
	return (int)(result*MAX_COLOR);
}

//int main(int argc, char *argv[])
//{
//	lua_State *L = luaL_newstate();
//	if (LUA_OK != luaL_loadfile(L, "config"))
//		error(L, "luaL_loadfile error");
//	if (LUA_OK != lua_pcall(L, 0, 0, 0))
//		error(L, "lua_pcall error");
//	lua_getglobal(L, "background");
//	if (!lua_istable(L, -1))
//		error(L, "background is not a table");
//	printf("r = %d\n", getcolorfield(L, "r"));
//	printf("g = %d\n", getcolorfield(L, "g"));
//	printf("b = %d\n", getcolorfield(L, "b"));
//
//	getchar();
//	return 0;
//}