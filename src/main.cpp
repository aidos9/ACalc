#include "../headers/astEvaluator.h"
#include "../headers/astPrinter.h"
#include "../headers/expressions.h"
#include "../headers/lexer.h"
#include "../headers/parser.h"
#include <iostream>

int main()
{
    Lexer lx = Lexer("(5 - 4) * (10 / 2)");
    lx.parse();

    std::vector<Token> tok = lx.getTokens();

    Parser p = Parser(tok);
    auto top = p.parse();

    ASTPrinter PX;
    std::cout << PX.printTree(top) << std::endl;
    std::cout << ASTEvaluator::evaluateNode(top) << std::endl;

    return 0;
}
