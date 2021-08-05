cmake_minimum_required(VERSION 3.12)

project(data-class-practice VERSION 1.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#add_executable(pair "pair.cpp")
#
#file(GLOB MyCSources src/*.cpp)
#add_executable(MyExecutable ${MyCSources})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY bin)
add_executable(main "src/main.cpp")
add_executable(validParen "src/validParen.cpp")
add_executable(M3D2 "src/M3D2.cpp")

add_executable(cppairtest "src/cppairtest.cpp")
add_executable(cpvectortest "src/cpvectortest.cpp")
add_executable(cpstacktest "src/cpstacktest.cpp")
add_executable(cpqueuetest "src/cpqueuetest.cpp")
add_executable(cpdequetest "src/cpdequetest.cpp")
add_executable(cppriority_queuetest "src/cppriority_queuetest.cpp")
add_executable(cplisttest "src/cplisttest.cpp")

add_executable(huffman "src/huffman.cpp")
add_executable(recursion "src/recursion.cpp")
add_executable(tree_operation "src/tree_operation.cpp")
