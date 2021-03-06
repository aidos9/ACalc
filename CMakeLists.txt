cmake_minimum_required(VERSION 3.12)
cmake_policy(SET CMP0048 NEW)
set(CMAKE_CXX_STANDARD 11)

#Versions
set(VERSION_MAJOR 0)
set(VERSION_MINOR 2)
set(VERSION_PATCH 0)
set(VERSION "${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}")

set(LIBRARY_NAME "acalc-lib")

project(acalc VERSION 0.2.0 DESCRIPTION "A simple CLI calculator" LANGUAGES CXX)

if(WITH_TESTS)
    message(STATUS "Enabled Tests")
    enable_testing()
else()
    message(STATUS "Disabled Tests")
endif()

include(CheckIncludeFile)
include(CheckIncludeFileCXX)
include(InstallRequiredSystemLibraries)

set(SOURCES src/evaluator.cpp
    src/printer.cpp
    src/lexer.cpp
    src/token.cpp
    src/parser.cpp
    src/expression.cpp
    src/unary.cpp
    src/binary.cpp
    src/literal.cpp
    src/grouping.cpp
    src/exception.cpp
    src/call.cpp
    src/evaluatorFunctions.cpp
    src/identifier.cpp)

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
    headers/exception.h
    headers/call.h
    headers/identifier.h)

check_include_file_cxx(iostream HAVE_IOSTREAM)
check_include_file_cxx(vector HAVE_VECTOR)
check_include_file_cxx(string HAVE_STRING)
check_include_file_cxx(memory HAVE_MEMORY)
check_include_file_cxx(sstream HAVE_SSTREAM)
check_include_file_cxx(cmath HAVE_CMATH)
check_include_file_cxx(cstring HAVE_CSTRING)
check_include_file_cxx(iomanip HAVE_IOMANIP)

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

if(NOT HAVE_CSTRING)
    message(FATAL_ERROR "Couldn't find <cstring>")
endif()

if(NOT HAVE_IOMANIP)
    message(FATAL_ERROR "Couldn't find <iomanip>")
endif()

configure_file(${PROJECT_SOURCE_DIR}/config.h.in ${PROJECT_SOURCE_DIR}/config.h)

add_library(${LIBRARY_NAME} STATIC ${SOURCES} ${HEADERS})

add_executable(${PROJECT_NAME} src/main.cpp)
target_link_libraries(${PROJECT_NAME} ${LIBRARY_NAME})

if(WITH_TESTS)
    add_executable(lexer-test tests/lexertest.cpp)
    target_link_libraries(lexer-test ${LIBRARY_NAME})
    add_test(lexer-test lexer-test)

    add_executable(parser-test tests/parsertest.cpp)
    target_link_libraries(parser-test ${LIBRARY_NAME})
    add_test(parser-test parser-test)

    add_executable(evaluator-test tests/evaluatortest.cpp)
    target_link_libraries(evaluator-test ${LIBRARY_NAME})
    add_test(evaluator-test evaluator-test)
endif()
