cmake_minimum_required(VERSION 3.10)

# Set the project name and version
project(SDL3Game VERSION 1.0)

# Set the C++ standard to C++17
set(CMAKE_CXX_COMPILER g++)
# remove console -mwindows
set(CMAKE_CXX_FLAGS "-mwindows -std=c++17 -static-libgcc -static-libstdc++ -static")

add_executable(game main.cpp)

#define the path to the SDL3 include directory and libarary
include_directories(game PUBLIC ${CMAKE_SOURCE_DIR}/src/include)
target_include_directories(game PUBLIC ${CMAKE_SOURCE_DIR}/src/include/SDL3)
include_directories(game PUBLIC ${CMAKE_SOURCE_DIR}/src/lib)
target_link_libraries(game PUBLIC ${CMAKE_SOURCE_DIR}/src/lib/SDL3.lib)

# Copy the SDL3.dll to the build directory
# This is necessary for the game to run, as it needs the SDL3.dll in the same directory as the executable
configure_file(${CMAKE_SOURCE_DIR}/src/lib/SDL3.dll ${CMAKE_SOURCE_DIR}/build COPYONLY)