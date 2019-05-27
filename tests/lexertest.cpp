#include "../headers/lexer.h"
#include "../headers/exception.h"
#include "../headers/tokentype.h"
#include <iostream>

int main()
{
    std::string test1 = "sin(4)";
    std::string test2 = "cos(4 * (3-2))";
    std::string test3 = "5^(4%3) / 2";
    Lexer lx = Lexer(test1);
    try {
         lx.parse();
    } catch (const Exception& e) {
        std::cerr << "An exception occurred: "<< e.getDescription() << ". Code: " << e.getCode() << std::endl;
        return 1;
    }

    std::vector<Token> results = lx.getTokens();
    std::vector<TokenType> expectedTypes = {tok_identifier, tok_lParen, tok_number, tok_rParen, tok_eof};

    std::cout << std::endl << "Test 1" << std::endl << std::endl;

    if(expectedTypes.size() != results.size())
    {
        std::cerr << "The results array is not the expected length" << std::endl;
        return 1;
    }

    for(size_t i = 0; i < results.size(); i++)
    {
        std::cout << "Index: " << i << " : " << tokenTypeToString(results[i].type);
        if(expectedTypes[i] != results[i].type)
        {
            std::cout << " - " << "Unexpected type (" << tokenTypeToString(expectedTypes[i]) << ")";
        }

        std::cout << std::endl;
    }


    lx.setEquation(test2);

    try {
         lx.parse();
    } catch (const Exception& e) {
        std::cerr << "An exception occurred: "<< e.getDescription() << ". Code: " << e.getCode() << std::endl;
        return 1;
    }

    results = lx.getTokens();
    expectedTypes = {tok_identifier, tok_lParen, tok_number, tok_mul, tok_lParen, tok_number, tok_sub, tok_number, tok_rParen, tok_rParen, tok_eof};

    std::cout << std::endl << "Test 2" << std::endl << std::endl;

    if(expectedTypes.size() != results.size())
    {
        std::cout << "The results array is not the expected length" << std::endl;
        for(size_t i = 0; i < results.size(); i++)
        {
            std::cout << "Index: " << i << " : " << tokenTypeToString(results[i].type) << std::endl;
        }
        return 1;
    }

    for(size_t i = 0; i < results.size(); i++)
    {
        std::cout << "Index: " << i << " : " << tokenTypeToString(results[i].type);
        if(expectedTypes[i] != results[i].type)
        {
            std::cout << " - " << "Unexpected type (" << tokenTypeToString(expectedTypes[i]) << ")";
        }

        std::cout << std::endl;
    }

    lx.setEquation(test3);

    try {
         lx.parse();
    } catch (const Exception& e) {
        std::cerr << "An exception occurred: "<< e.getDescription() << ". Code: " << e.getCode() << std::endl;
        return 1;
    }

    results = lx.getTokens();
    expectedTypes = {tok_number, tok_exp, tok_lParen, tok_number, tok_mod, tok_number, tok_rParen, tok_div, tok_number, tok_eof};

    std::cout << std::endl << "Test 3" << std::endl << std::endl;

    if(expectedTypes.size() != results.size())
    {
        std::cout << "The results array is not the expected length" << std::endl;
        for(size_t i = 0; i < results.size(); i++)
        {
            std::cout << "Index: " << i << " : " << tokenTypeToString(results[i].type) << std::endl;
        }
        return 1;
    }

    for(size_t i = 0; i < results.size(); i++)
    {
        std::cout << "Index: " << i << " : " << tokenTypeToString(results[i].type);
        if(expectedTypes[i] != results[i].type)
        {
            std::cout << " - " << "Unexpected type (" << tokenTypeToString(expectedTypes[i]) << ")";
        }

        std::cout << std::endl;
    }

    std::cout << "All tests passed" << std::endl;

    return 0;
}
