#include <dirent.h>
#include <errno.h>
#include <string.h>
#include "lua.h"
#include "lauxlib.h"

int l_dir(lua_State *L)
{
	DIR *dir;
	struct dirent *entry;
	int i;
	const char *path = luaL_checkstring(L, 1);
	dir = opendir(path);
	if (NULL == dir)
	{
		lua_pushnil(L);
		printf("NULL == dir");
		lua_pushstring(L, strerror(errno));
		return 2;
	}

	lua_newtable(L);
	i = 1;
	while ((entry=readdir(dir))!=NULL)
	{
		lua_pushnumber(L, i++);
		lua_pushstring(L, entry->d_name);
		lua_settable(L, -3);
	}
	closedir(dir);
	return 1;
}

