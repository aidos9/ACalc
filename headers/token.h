#ifndef TOKEN_H
#define TOKEN_H

#include "tokentype.h"
#include <string>

class Token
{
public:
    Token();
    Token(const TokenType& t, const std::string& v);

    TokenType type;
    std::string value;
};

#endif // TOKEN_H
