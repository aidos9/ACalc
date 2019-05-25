#ifndef LEXER_H
#define LEXER_H

#include "token.h"
#include <string>
#include <vector>

class Lexer
{
public:
    Lexer();
    Lexer(const std::string& equation);
    void setEquation(const std::string& equation);
    void parse();
    std::vector<Token> getTokens();

private:
    Token handleNumber();
    std::string str;
    std::vector<Token> tokens;
    size_t index = 0;
};
#endif
