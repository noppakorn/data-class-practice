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
add_executable(pointer "src/pointer.cpp")

add_executable(cppairtest "src/stl-cp/cppairtest.cpp")
add_executable(cpvectortest "src/stl-cp/cpvectortest.cpp")
add_executable(cpstacktest "src/stl-cp/cpstacktest.cpp")
add_executable(cpqueuetest "src/stl-cp/cpqueuetest.cpp")
add_executable(cpdequetest "src/stl-cp/cpdequetest.cpp")
add_executable(cppriority_queuetest "src/stl-cp/cppriority_queuetest.cpp")
add_executable(cplisttest "src/stl-cp/cplisttest.cpp")

add_executable(huffman "src/tree/huffman.cpp")
add_executable(recursion "src/tree/recursion.cpp")
add_executable(tree_operation "src/tree/tree_operation.cpp")

add_executable(cpmap_bsttest "src/stl-cp/cpmap_bsttest.cpp")
add_executable(cpmap_avltest "src/stl-cp/cpmap_avltest.cpp")