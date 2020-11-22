cmake_minimum_required(VERSION 3.5)
project(sdl_game_project CXX)

if(UNIX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE "Debug")
add_compile_options(-Wall -Wextra -pedantic -Werror)
elseif(MCVC)
add_compile_options(/W4)
endif()

find_package(Threads)

if(MSVC)
find_package(SDL2)
endif()

add_executable(sdl_game examples/sdl_game_example.cpp)
target_include_directories(sdl_game PRIVATE include)
target_link_libraries(sdl_game SDL2)