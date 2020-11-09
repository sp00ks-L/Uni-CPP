cmake_minimum_required(VERSION 3.17)
project(Uni_C__)

set(CMAKE_CXX_STANDARD 98)

add_executable(uniCPP virusMain.cpp Person.h virusFunctions.cpp virusFunctions.h)
#add_executable(uniCPP matrixTranspose.cpp matrixTranspose.h matrixMain.cpp)
# add_executable(uniCPP Circle.cpp Circle.h)