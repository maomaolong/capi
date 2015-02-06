//a simple lua interpreter
#include <stdio.h>
#include <math.h>
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
#include "head.h"

int l_square(lua_State *L)
{
	lua_Number n = lua_tonumber(L, 1);
	lua_pushnumber(L, n*n);
	return 1;
}

int main(int argc, char *argv[])
{
	char buff[256] = { 0 };
	int error;
	lua_State *L = luaL_newstate();
	luaL_openlibs(L);
	lua_pushcfunction(L, l_square);
	lua_setglobal(L, "mysquare");
	lua_pushcfunction(L, l_dir);
	lua_setglobal(L, "dir");
	while (fgets(buff, sizeof(buff), stdin) != NULL)
	{
		error = luaL_loadbuffer(L, buff, strlen(buff), "line");
		lua_pcall(L, 0, 0, 0);
		if (error)
		{
			fprintf(stderr, "%s", lua_tostring(L, -1));
			lua_pop(L, 1);
		}
	}

	lua_close(L);
	return 0;
}