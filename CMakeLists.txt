cmake_minimum_required(VERSION 3.12)

project(data-class-practice VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#add_executable(pair "pair.cpp")
#
#file(GLOB MyCSources src/*.cpp)
#add_executable(MyExecutable ${MyCSources})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
add_executable(pair "src/pair.cpp")
add_executable(cpvectortest "src/cpvectortest.cpp")
