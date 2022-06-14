cmake_minimum_required(VERSION 3.22)
project(train5)

set(CMAKE_CXX_STANDARD 14)

add_executable(train5 main.cpp cmake-build-debug/course.cpp cmake-build-debug/course.h person.cpp person.h Student.cpp Student.h Professor.cpp Professor.h University.cpp University.h)
