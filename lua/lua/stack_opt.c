//a example of stack operation
#include <stdio.h>
#include "lua.h"
#include "lauxlib.h"
#include "head.h"

//int main(int argc, char *argv[])
//{
//	lua_State *L = luaL_newstate();
//	lua_pushboolean(L, 2);
//	lua_pushnumber(L, 10);
//	lua_pushstring(L, "hello");
//	lua_settop(L, -2);
//	stack_dump(L);
//	getchar();
//	return 0;
//}