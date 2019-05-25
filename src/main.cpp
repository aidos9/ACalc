#include "../headers/astEvaluator.h"
#include "../headers/astPrinter.h"
#include "../headers/expressions.h"
#include "../headers/lexer.h"
#include "../headers/parser.h"
#include <iostream>

int main()
{
    Lexer lx = Lexer("(5 + 4) * (3 + 2)");
    lx.parse();

    std::vector<Token> tok = lx.getTokens();

    Parser p = Parser(tok);

    ASTPrinter PX;
    std::cout << PX.printTree(p.parse()) << std::endl;
    return 0;
}
