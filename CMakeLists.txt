cmake_minimum_required(VERSION 3.13)
project(sdl_game_project CXX)

if(UNIX)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE "Debug")
add_compile_options(-Wall -Wextra -pedantic -Werror)
elseif(MCVC)
add_compile_options(/W4)
endif()

find_package(Threads)

add_subdirectory(Vector)
add_subdirectory(Logging)

if(MSVC)
find_package(SDL2)
endif()

add_library(sdl_game SHARED src/sdl_game_main.cpp
                            src/sdl_game_texture_manager.cpp
                            src/sdl_game_input_handler.cpp
                            src/sdl_game_game_object.cpp
                            src/sdl_game_player.cpp
                            src/sdl_game_text.cpp)
target_include_directories(sdl_game PRIVATE include)
target_link_libraries(sdl_game SDL2 SDL2_image SDL2_ttf vector logger)

add_executable(sdl_game_exe examples/sdl_game_example.cpp)
target_include_directories(sdl_game_exe PRIVATE include)
target_link_libraries(sdl_game_exe sdl_game logger)