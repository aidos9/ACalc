#define CATCH_CONFIG_MAIN
#include "../libs/catch.hpp"

#include "../headers/parser.h"
#include "../headers/lexer.h"
#include "../headers/exception.h"
#include "../headers/printer.h"

static std::string test1 = "sin(5-3)+4^2";
static std::string test2 = "5/(3*3)+4^(3-1)";
static std::string test3 = "183^(4-3)*22-(88)+12";
static std::string test4 = "sin(pi)";
static std::string test5 = "log(e,2*e)";

TEST_CASE("Test 1","[test1]")
{
    Lexer lx = Lexer();
    lx.setEquation(test1);

    try {
        lx.parse();
    } catch (const Exception& e) {
        std::stringstream ss;
        ss <<  "An exception occurred with description: " << e.getDescription() << " with code: " << e.getCode();
        FAIL(ss.str());
    }

    std::vector<Token> tokens = lx.getTokens();


    Parser p = Parser(tokens);
    std::shared_ptr<Expression> e;

    try {
        e = p.parse();
    } catch (const Exception& e) {
        std::stringstream ss;
        ss <<  "An exception occurred with description: " << e.getDescription() << " with code: " << e.getCode();
        FAIL(ss.str());
    }

    Printer printer = Printer();

    REQUIRE(printer.printTree(e) == test1);
}

TEST_CASE("Test 2","[test2]")
{
    Lexer lx = Lexer();
    lx.setEquation(test2);

    try {
        lx.parse();
    } catch (const Exception& e) {
        std::stringstream ss;
        ss <<  "An exception occurred with description: " << e.getDescription() << " with code: " << e.getCode();
        FAIL(ss.str());
    }

    std::vector<Token> tokens = lx.getTokens();


    Parser p = Parser(tokens);
    std::shared_ptr<Expression> e;

    try {
        e = p.parse();
    } catch (const Exception& e) {
        std::stringstream ss;
        ss <<  "An exception occurred with description: " << e.getDescription() << " with code: " << e.getCode();
        FAIL(ss.str());
    }

    Printer printer = Printer();

    REQUIRE(printer.printTree(e) == test2);
}

TEST_CASE("Test 3","[test3]")
{
    Lexer lx = Lexer();
    lx.setEquation(test3);

    try {
        lx.parse();
    } catch (const Exception& e) {
        std::stringstream ss;
        ss <<  "An exception occurred with description: " << e.getDescription() << " with code: " << e.getCode();
        FAIL(ss.str());
    }

    std::vector<Token> tokens = lx.getTokens();


    Parser p = Parser(tokens);
    std::shared_ptr<Expression> e;

    try {
        e = p.parse();
    } catch (const Exception& e) {
        std::stringstream ss;
        ss <<  "An exception occurred with description: " << e.getDescription() << " with code: " << e.getCode();
        FAIL(ss.str());
    }

    Printer printer = Printer();

    REQUIRE(printer.printTree(e) == test3);
}

TEST_CASE("Test 4","[test4]")
{
    Lexer lx = Lexer();
    lx.setEquation(test4);

    try {
        lx.parse();
    } catch (const Exception& e) {
        std::stringstream ss;
        ss <<  "An exception occurred with description: " << e.getDescription() << " with code: " << e.getCode();
        FAIL(ss.str());
    }

    std::vector<Token> tokens = lx.getTokens();


    Parser p = Parser(tokens);
    std::shared_ptr<Expression> e;

    try {
        e = p.parse();
    } catch (const Exception& e) {
        std::stringstream ss;
        ss <<  "An exception occurred with description: " << e.getDescription() << " with code: " << e.getCode();
        FAIL(ss.str());
    }

    Printer printer = Printer();

    REQUIRE(printer.printTree(e) == test4);
}

TEST_CASE("Test 5","[test5]")
{
    Lexer lx = Lexer();
    lx.setEquation(test5);

    try {
        lx.parse();
    } catch (const Exception& e) {
        std::stringstream ss;
        ss <<  "An exception occurred with description: " << e.getDescription() << " with code: " << e.getCode();
        FAIL(ss.str());
    }

    std::vector<Token> tokens = lx.getTokens();


    Parser p = Parser(tokens);
    std::shared_ptr<Expression> e;

    try {
        e = p.parse();
    } catch (const Exception& e) {
        std::stringstream ss;
        ss <<  "An exception occurred with description: " << e.getDescription() << " with code: " << e.getCode();
        FAIL(ss.str());
    }

    Printer printer = Printer();

    REQUIRE(printer.printTree(e) == test5);
}
