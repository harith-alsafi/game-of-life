# VERSION 2.8
cmake_minimum_required(VERSION 2.8)
project(lifegame)

# find_package(SDL2 REQUIRED)
# include_directories(${SDL2_INCLUDE_DIRS})

# Debug mode
set(CMAKE_BUILD_TYPE Debug)

# Egypt flags 
set(CMAKE_C_FLAGS "-std=c99 -fdump-rtl-expand")

# Directories  
include_directories(unity/src)
include_directories(src)
include_directories(tests)
include_directories(includes)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ../out)

# main lifegame
add_executable(lifegame src/main.c src/graphic.c src/logic.c src/misc.c)
# adds -lm and -lSDL2 -lSDL2_ttf flags 
target_link_libraries(lifegame SDL2 SDL2_ttf)

add_executable(logic tests/test_logic.c src/logic.c unity/src/unity.c)

add_executable(graphic tests/test_graphic.c src/logic.c src/graphic.c unity/src/unity.c)
target_link_libraries(graphic SDL2 SDL2_ttf)

add_executable(misc tests/test_misc.c src/logic.c src/graphic.c src/misc.c unity/src/unity.c)
target_link_libraries(misc SDL2 SDL2_ttf)