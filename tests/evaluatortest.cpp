#include "../headers/evaluator.h"
#include "../headers/parser.h"
#include "../headers/lexer.h"
#include <cmath>

#define CATCH_CONFIG_MAIN
#include "../libs/catch.hpp"

bool cmpf(double A, double B, double epsilon = 0.005)
{
    return (fabs(A - B) < epsilon);
}


TEST_CASE("Test 1","[test1]") {
    Lexer lx = Lexer();
    lx.setEquation("183^(4-3)*22-(88) + 44.6");

    try {
        lx.parse();
    } catch (const Exception& e) {
        std::stringstream ss;
        ss <<"An exception occurred with description: " << e.getDescription() << " with code: " << e.getCode();
        FAIL(ss.str());
    }

    std::vector<Token> tokens = lx.getTokens();


    Parser p = Parser(tokens);
    std::shared_ptr<Expression> e;

    try {
        e = p.parse();
    } catch (const Exception& e) {
        std::stringstream ss;
        ss <<"An exception occurred with description: " << e.getDescription() << " with code: " << e.getCode();
        FAIL(ss.str());
    }

    double ret = Evaluator::evaluateNode(e);

    REQUIRE(cmpf(ret, 3982.6, 0.0000001));
}

TEST_CASE("Test 2","[test2]") {
    Lexer lx = Lexer();
    lx.setEquation("88^(sin(0))");

    try {
        lx.parse();
    } catch (const Exception& e) {
        std::stringstream ss;
        ss <<"An exception occurred with description: " << e.getDescription() << " with code: " << e.getCode();
        FAIL(ss.str());
    }

    std::vector<Token> tokens = lx.getTokens();


    Parser p = Parser(tokens);
    std::shared_ptr<Expression> e;

    try {
        e = p.parse();
    } catch (const Exception& e) {
        std::stringstream ss;
        ss <<"An exception occurred with description: " << e.getDescription() << " with code: " << e.getCode();
        FAIL(ss.str());
    }

    double ret = Evaluator::evaluateNode(e);

    REQUIRE(cmpf(ret, 1, 0.0000001));
}

TEST_CASE("Test 3","[test3]") {
    Lexer lx = Lexer();
    lx.setEquation("(88*3) - 4 + 386*10^4");

    try {
        lx.parse();
    } catch (const Exception& e) {
        std::stringstream ss;
        ss <<"An exception occurred with description: " << e.getDescription() << " with code: " << e.getCode();
        FAIL(ss.str());
    }

    std::vector<Token> tokens = lx.getTokens();


    Parser p = Parser(tokens);
    std::shared_ptr<Expression> e;

    try {
        e = p.parse();
    } catch (const Exception& e) {
        std::stringstream ss;
        ss <<"An exception occurred with description: " << e.getDescription() << " with code: " << e.getCode();
        FAIL(ss.str());
    }

    double ret = Evaluator::evaluateNode(e);

    REQUIRE(cmpf(ret, 3860260, 0.0000001));
}
