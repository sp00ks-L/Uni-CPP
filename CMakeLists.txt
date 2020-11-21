cmake_minimum_required(VERSION 3.15.3)
project(Uni_C__)

#set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD 11)

add_executable(uniCPP "Virus Simulation/Person.hpp" "Virus Simulation/virusFunctions.cpp" "Virus Simulation/virusFunctions.hpp" "Virus Simulation/virusMain.cpp")
#add_executable(uniCPP matrixTranspose.cpp matrixTranspose.h matrixMain.cpp)
#add_executable(uniCPP Circle.cpp Circle.h)