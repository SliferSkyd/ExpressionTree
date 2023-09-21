cmake_minimum_required(VERSION 3.16)
project(Lab2)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab2 main.cpp
        lexicalAnalyzer.h
        Token.h
        parseException.h
        Tree.h
        parse.h)
