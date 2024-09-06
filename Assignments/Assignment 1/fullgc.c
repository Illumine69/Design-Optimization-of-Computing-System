#include "./lua-5.4.7/src/lauxlib.h"
#include "./lua-5.4.7/src/lua.h"
#include "./lua-5.4.7/src/lualib.h"

int main(int argc, char *argv[]) {

    lua_State *L;

    // initialize Lua interpreter
    L = luaL_newstate();

    // load Lua base libraries (print / math / etc)
    luaL_openlibs(L);

    lua_gc(L, LUA_GCSTOP, 0);
    // We can use Lua here !
    luaL_dofile(L, "testbench.lua");

    // Cleanup:  Deallocate all space assocatated with the lua state */
    lua_gc(L, LUA_GCCOLLECT, 0);
    lua_close(L);

    // // Hack to prevent program from ending immediately
    // printf("Press enter to exit...");
    // getchar();

    return 0;
}