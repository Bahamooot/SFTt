cmake_minimum_required(VERSION 3.23)
project(SFTt)

set(CMAKE_CXX_STANDARD 20)

include(/opt/homebrew/Cellar/sdl2/2.26.0/lib/cmake/SDL2/sdl2-config.cmake)
include_directories(./include)
include_directories(./lib)
#find_library(SDL2_LIBRARY NAME SDL2 HINTS /opt/homebrew/Cellar/sdl2/2.26.0/lib/cmake REQUIRED)

add_executable(SFTt main.cpp include/self_renderer.h include/color.h include/interface/noise.h include/notTrueRandom.h  lib/basic_noise.cpp include/basic_noise.h lib/average2D.cpp include/average2D.h lib/random_noise.cpp include/random_noise.h lib/notTrueRandom.cpp lib/linear_wave_noise.cpp include/linear_wave_noise.h lib/jubog_noise.cpp include/jubog_noise.h lib/berlin_noise.cpp include/berlin_noise.h)

#set(SDL2_INCLUDE_DIRS /opt/homebrew/Cellar/sdl2/2.26.0/include)
#set(SDL2_LIBRARIES /opt/homebrew/Cellar/sdl2/2.26.0/lib/libSDL2.a)

target_include_directories(SFTt PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(SFTt PRIVATE ${SDL2_LIBRARIES})

message("Found SLD at: ${SDL2_INCLUDE_DIRS}")
