cmake_minimum_required(VERSION 3.20)

set(DUSKLIGHT_BUILD_GAME OFF CACHE BOOL "" FORCE)
set(DUSKLIGHT_BUILD_MODS_ONLY ON CACHE BOOL "" FORCE)

project(template_mod CXX)

set(DUSKLIGHT_VERSION "v2.0.3")

include(FetchContent)
FetchContent_Declare(
    dusklight
    GIT_REPOSITORY https://github.com/TwilitRealm/dusklight.git
    GIT_TAG ${DUSKLIGHT_VERSION}
    GIT_SHALLOW TRUE
)
FetchContent_MakeAvailable(dusklight)

add_mod(template_mod
    SOURCES src/mod.cpp
    MOD_JSON mod.json.in
)

set_target_properties(template_mod PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
)
