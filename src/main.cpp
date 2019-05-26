#include "../headers/astEvaluator.h"
#include "../headers/astPrinter.h"
#include "../headers/expressions.h"
#include "../headers/lexer.h"
#include "../headers/parser.h"
#include <iostream>

int main(int argc, char* argv[])
{
    bool verbose = false;
    std::string passThroughStr = "5%5";

    if(argc > 1)
    {
        for(int i = 1; i < argc; i++)
        {
            if(strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0)
            {
                std::cout << "Welcome to MathAST v0.1" << std::endl;
                std::cout << "-h\t Show the help message" << std::endl;
                std::cout << "-v\t Show verbose information" << std::endl;
                std::cout << "-e\t Pass expression from command line" << std::endl;
                return 0;
            }else if(strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--verbose") == 0)
            {
                verbose = true;
            }else if(strcmp(argv[i], "-e") == 0)
            {
                if((i+1) == argc)
                {
                    std::cerr << "No expression provided" << std::endl;
                    return 1;
                }

                passThroughStr = argv[i+1];
            }
        }
    }

    if(passThroughStr != "")
    {
        Lexer lx = Lexer(passThroughStr);
        try {
            lx.parse();
        } catch (const Exception& e) {
            std::cerr << "An error occured: " + e.getDescription() << " " << e.getCode() << std::endl;
        }

        std::vector<Token> tok = lx.getTokens();

        Parser p = Parser(tok);

        std::shared_ptr<Expression> top;
        try {
            top = p.parse();
        } catch (const Exception& e) {
            std::cerr << "An error occured: " + e.getDescription() << " " << e.getCode() << std::endl;
        }

        if(verbose)
        {
            ASTPrinter PX;
            std::cout << PX.printTree(top) << std::endl;
        }

        std::cout << ASTEvaluator::evaluateNode(top) << std::endl;
        return 0;
    }

    bool should_exit = false;
    std::cout << "Welcome to basic MathAST v0.1" << std::endl;

    while(!should_exit)
    {
        std::cout << " > ";
        std::string str;
        getline(std::cin, str);

        if(str == "exit")
        {
            should_exit = true;
        }else{
            Lexer lx = Lexer(str);
            lx.parse();

            std::vector<Token> tok = lx.getTokens();

            Parser p = Parser(tok);
            auto top = p.parse();

            if(verbose)
            {
                ASTPrinter PX;
                std::cout << PX.printTree(top) << std::endl;
            }

            std::cout << ASTEvaluator::evaluateNode(top) << std::endl;
        }
    }
    return 0;
}
