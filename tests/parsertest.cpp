#include "../headers/parser.h"
#include "../headers/lexer.h"
#include "../headers/exception.h"
#include "../headers/printer.h"
#include <iostream>

int main()
{
    std::cout << "Test 1: ";

    std::string test1 = "sin(5-3) + 4^2";
    std::string test2 = "5/(3*3)+4^(3-1)";

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

    Printer printer = Printer();
    std::string v = printer.printTree(e);

    if(v != "sin(5-3)+4^2")
    {
        std::cerr << "Failed" << std::endl << "The expected output was not detected. Instead \"" << v << "\" was outputted" << std::endl;
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
        std::cerr << "Failed" << std::endl<< "An exception occurred with description: " << e.getDescription() << " with code: " << e.getCode() << std::endl;
        return 1;
    }

    v = printer.printTree(e);

    if(v != "5/(3*3)+4^(3-1)")
    {
        std::cerr << "Failed" << std::endl << "The expected output was not detected. Instead \"" << v << "\" was outputted" << std::endl;
        return 1;
    }

    std::cout << "Passed" << std::endl;

    return 0;
}
