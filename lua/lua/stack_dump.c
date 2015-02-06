//a example to dump lua stack
#include <stdio.h>
#include "lua.h"
//#include "lualib.h"
#include "lauxlib.h"
#include "head.h"

void stack_dump(lua_State *L)
{
	size_t i = 1;
	int top = lua_gettop(L);
	for (i = 1; i <= top; i++)
	{
		int t = lua_type(L, i);
		switch (t)
		{
		case LUA_TBOOLEAN:
		{
			int value = lua_toboolean(L, i);
			printf("%d %d\n", i, value);
			break;
		}
		case LUA_TNUMBER:
		{
			lua_Number value = lua_tonumber(L, i);
			printf("%d %g\n", i, value);
			break;
		}
		case LUA_TSTRING:
		{
			char* value = lua_tostring(L, i);
			printf("%d %s\n", i, value);
			break;
		}
		default:
		{
			printf("%d %s\n", i, lua_typename(L, t));
			break;
		}
		}
	}
}

//int main(int argc, char *argv[])
//{
//	lua_State *L = luaL_newstate();
//	//luaL_openlibs(L);
//	lua_pushboolean(L, 0);
//	lua_pushnumber(L, 5);
//	lua_pushlstring(L, "helloworld",8);
//	stack_dump(L);
//	getchar();
//	return 0;
//}