#ifndef HEAD_H 
#define HEAD_H

#include "lua.h"

void stack_dump(lua_State *L);
void error(lua_State *L, const char *fmt, ...);
void loadfile(lua_State *L, const char *fname);
int l_dir(lua_State *L);

#endif