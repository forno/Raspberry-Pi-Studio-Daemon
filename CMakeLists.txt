cmake_minimum_required(VERSION 3.1.3)
project(StudioDaemon
  VERSION   0.1.0
  LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD          14  CACHE STRING "CXX standard version")
set(CMAKE_CXX_STANDARD_REQUIRED ON  CACHE BOOL   "version required")
set(CMAKE_CXX_EXTENSIONS        OFF CACHE BOOL   "compiler extension")

find_package(Threads REQUIRED)

add_executable(studio_daemon src/main.cpp src/daemon.cpp)
target_link_libraries(studio_daemon Threads::Threads wiringPi)
target_compile_options(studio_daemon PRIVATE
  $<$<CXX_COMPILER_ID:Clang>:-Weverything -Wno-c++98-compat>
  $<$<CXX_COMPILER_ID:GNU>:-Wall -Wextra>)
