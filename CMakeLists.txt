cmake_minimum_required(VERSION 3.12)
cmake_policy(SET CMP0048 NEW)
set(CMAKE_CXX_STANDARD 11)

project(MathAST VERSION 0.1)

set(SOURCES src/main.cpp
    src/astNode.cpp
    src/astEvaluator.cpp
    src/astPrinter.cpp)

set(HEADERS headers/astNode.h
    headers/astEvaluator.h
    headers/astPrinter.h)

add_executable(${PROJECT_NAME} ${SOURCES})
