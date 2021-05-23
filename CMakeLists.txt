cmake_minimum_required(VERSION 3.17)
project(Myset)

set(CMAKE_CXX_STANDARD 17)

add_executable(Myset main.cpp mySet.cpp mySet.h mySetIterator.cpp mySetIterator.h mySetReverseIterator.h mySetReverseIterator.cpp)