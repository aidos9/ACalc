#include "../headers/evaluator.h"
#include "../headers/parser.h"
#include "../headers/lexer.h"
#include <iostream>
#include "../headers/printer.h"
#include <cmath>

//#define CATCH_CONFIG_MAIN
//#include "../libs/catch.hpp"

bool cmpf(double A, double B, double epsilon = 0.005)
{
    return (fabs(A - B) < epsilon);
}

/*
TEST_CASE("Test 1","[test]") {
    std::cout << "Test 1: ";
    Lexer lx = Lexer();
    lx.setEquation("183^(4-3)*22-(88) + 44.6");

    try {
        lx.parse();
    } catch (const Exception& e) {
        std::cerr << "Failed" << std::endl << "An exception occurred with description: " << e.getDescription() << " with code: " << e.getCode() << std::endl;

    }

    std::vector<Token> tokens = lx.getTokens();


    Parser p = Parser(tokens);
    std::shared_ptr<Expression> e;

    try {
        e = p.parse();
    } catch (const Exception& e) {
        std::cerr << "Failed" << std::endl <<  "An exception occurred with description: " << e.getDescription() << " with code: " << e.getCode() << std::endl;
        FAIL();
    }

    double ret = Evaluator::evaluateNode(e);

    REQUIRE(cmpf(ret, 3982.6, 0.0000001));
}
*/

int main()
{
    std::string test1 = "183^(4-3)*22-(88)+44.6";
    std::string test2 = "88^(sin(0))";
    std::string test3 = "(88*3) - 4 + 386*10^4";

    std::cout << "Test 1: ";
    Lexer lx = Lexer();
    lx.setEquation(test1);

    try {
        lx.parse();
    } catch (const Exception& e) {
        std::cerr << "Failed" << std::endl << "An exception occurred with description: " << e.getDescription() << " with code: " << e.getCode() << std::endl;
        return 1;
    }

    std::vector<Token> tokens = lx.getTokens();


    Parser p = Parser(tokens);
    std::shared_ptr<Expression> e;

    try {
        e = p.parse();
    } catch (const Exception& e) {
        std::cerr << "Failed" << std::endl <<  "An exception occurred with description: " << e.getDescription() << " with code: " << e.getCode() << std::endl;
        return 1;
    }

    double ret = Evaluator::evaluateNode(e);

    Printer printer = Printer();
    std::cout << printer.printTree(e) << std::endl;

    if(!cmpf(ret, 3982.6, 0.0000001))
    {
        std::cout << "Failed" << std::endl << "The returned value was not correct instead: " << ret << " was calculated" << std::endl;
        return 1;
    }

    std::cout << "Passed" << std::endl << "Test 2: ";

    lx.setEquation(test2);

    try {
        lx.parse();
    } catch (const Exception& e) {
        std::cerr << "Failed" << std::endl << "An exception occurred with description: " << e.getDescription() << " with code: " << e.getCode() << std::endl;
        return 1;
    }

    tokens = lx.getTokens();

    p.setTokens(tokens);

    try {
        e = p.parse();
    } catch (const Exception& e) {
        std::cerr << "Failed" << std::endl <<  "An exception occurred with description: " << e.getDescription() << " with code: " << e.getCode() << std::endl;
        return 1;
    }

    ret = Evaluator::evaluateNode(e);

    if(!cmpf(ret, 1, 0.0000001))
    {
        std::cout << "Failed" << std::endl << "The returned value was not correct instead: " << ret << " was retrieved" << std::endl;
        return 1;
    }

    std::cout << "Passed" << std::endl << "Test 3: ";

    lx.setEquation(test3);

    try {
        lx.parse();
    } catch (const Exception& e) {
        std::cerr << "Failed" << std::endl << "An exception occurred with description: " << e.getDescription() << " with code: " << e.getCode() << std::endl;
        return 1;
    }

    tokens = lx.getTokens();


    p.setTokens(tokens);

    try {
        e = p.parse();
    } catch (const Exception& e) {
        std::cerr << "Failed" << std::endl <<  "An exception occurred with description: " << e.getDescription() << " with code: " << e.getCode() << std::endl;
        return 1;
    }

    ret = Evaluator::evaluateNode(e);

    if(!cmpf(ret, 3860260, 0.0000001))
    {
        std::cout << "Failed" << std::endl << "The returned value was not correct instead: " << ret << " was retrieved" << std::endl;
        return 1;
    }

    std::cout << "Passed" << std::endl;

    return 0;
}
