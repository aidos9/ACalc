cmake_minimum_required(VERSION 3.12)
cmake_policy(SET CMP0048 NEW)
set(CMAKE_CXX_STANDARD 11)

#Versions
set(VERSION_MAJOR 0)
set(VERSION_MINOR 1)
set(VERSION_PATCH 0)
set(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

project(acalc VERSION 0.1.0 DESCRIPTION "A simple CLI calculator" LANGUAGES CXX)

include(CheckIncludeFile)
include(CheckIncludeFileCXX)
include(InstallRequiredSystemLibraries)

set(SOURCES src/main.cpp
    src/evaluator.cpp
    src/printer.cpp
    src/lexer.cpp
    src/token.cpp
    src/parser.cpp
    src/expression.cpp
    src/unary.cpp
    src/binary.cpp
    src/literal.cpp
    src/grouping.cpp
    src/exception.cpp)

set(HEADERS headers/evaluator.h
    headers/printer.h
    headers/lexer.h
    headers/token.h
    headers/tokenType.h
    headers/parser.h
    headers/expression.h
    headers/unary.h
    headers/binary.h
    headers/literal.h
    headers/grouping.h
    headers/expressions.h
    headers/exception.h)

check_include_file_cxx(iostream HAVE_IOSTREAM)
check_include_file_cxx(vector HAVE_VECTOR)
check_include_file_cxx(string HAVE_STRING)
check_include_file_cxx(memory HAVE_MEMORY)
check_include_file_cxx(sstream HAVE_SSTREAM)
check_include_file_cxx(cmath HAVE_CMATH)

if(NOT HAVE_IOSTREAM)
    message(FATAL_ERROR "Couldn't find <iostream>")
endif()

if(NOT HAVE_VECTOR)
    message(FATAL_ERROR "Couldn't find <vector>")
endif()

if(NOT HAVE_STRING)
    message(FATAL_ERROR "Couldn't find <string>")
endif()

if(NOT HAVE_MEMORY)
    message(FATAL_ERROR "Couldn't find <memory>")
endif()

if(NOT HAVE_SSTREAM)
    message(FATAL_ERROR "Couldn't find <sstream>")
endif()

if(NOT HAVE_CMATH)
    message(FATAL_ERROR "Couldn't find <cmath>")
endif()

configure_file(${PROJECT_SOURCE_DIR}/config.h.in ${PROJECT_SOURCE_DIR}/config.h)
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
