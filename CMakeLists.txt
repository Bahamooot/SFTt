cmake_minimum_required(VERSION 3.23)
project(SFTt)

set(CMAKE_CXX_STANDARD 20)

include(/opt/homebrew/Cellar/sdl2/2.26.0/lib/cmake/SDL2/sdl2-config.cmake)
#find_library(SDL2_LIBRARY NAME SDL2 HINTS /opt/homebrew/Cellar/sdl2/2.26.0/lib/cmake REQUIRED)

add_executable(SFTt main.cpp)

#set(SDL2_INCLUDE_DIRS /opt/homebrew/Cellar/sdl2/2.26.0/include)
#set(SDL2_LIBRARIES /opt/homebrew/Cellar/sdl2/2.26.0/lib/libSDL2.a)

target_include_directories(SFTt PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(SFTt PRIVATE ${SDL2_LIBRARIES})

message("Found SLD at: ${SDL2_INCLUDE_DIRS}")
