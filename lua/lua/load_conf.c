// a example of read config file by lua
#include <stdio.h>
#include "lua.h"
#include "lauxlib.h"
#include "head.h"

void loadfile(lua_State *L, const char *fname)
{
	if (LUA_OK != luaL_loadfile(L, fname))
		error(L, "luaL_loadfile error");
	if (LUA_OK != lua_pcall(L, 0, 0, 0))
		error(L, "lua_pcall error");
}

void load(lua_State *L, const char *fname, int *w, int *h)
{
	loadfile(L, fname);
	lua_getglobal(L, "width");
	lua_getglobal(L, "height");
	*w = lua_tointeger(L, -2);
	*h = lua_tointeger(L, -1);
}

//int main(int argc, char *argv[])
//{
//	lua_State *L = luaL_newstate();
//	int w, h;
//	load(L, "config",&w, &h);
//	printf("w = %d , h = %d ", w, h);
//
//	getchar();
//	return 0;
//}