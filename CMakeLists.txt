cmake_minimum_required(VERSION 3.12)
cmake_policy(SET CMP0048 NEW)
set(CMAKE_CXX_STANDARD 11)

project(MathAST VERSION 0.1)

set(SOURCES src/main.cpp
    src/astNode.cpp
    src/astEvaluator.cpp
    src/astPrinter.cpp
    src/lexer.cpp
    src/token.cpp
    src/parser.cpp
    src/expression.cpp
    src/unary.cpp
    src/binary.cpp
    src/literal.cpp
    src/grouping.cpp)

set(HEADERS headers/astNode.h
    headers/astEvaluator.h
    headers/astPrinter.h
    headers/lexer.h
    headers/token.h
    headers/tokenType.h
    headers/parser.h
    headers/expression.h
    headers/unary.h
    headers/binary.h
    headers/literal.h
    headers/grouping.h
    headers/expressions.h)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
