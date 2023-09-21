cmake_minimum_required(VERSION 3.16)
project(ExpressionTree)

set(CMAKE_CXX_STANDARD 17)

add_executable(ExpressionTree main.cpp
        lexicalAnalyzer.h
        Token.h
        parseException.h
        Tree.h
        parse.h)
