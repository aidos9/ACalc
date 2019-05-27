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
    void clear();

    std::vector<Token> getTokens() const;

private:
    Token handleNumber();
    Token handleIdentifier();

    std::string str;
    std::vector<Token> tokens;
    size_t index = 0;
};
#endif
