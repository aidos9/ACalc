#include "../headers/token.h"

Token::Token()
{

}

Token::Token(const TokenType& t, const std::string& v)
{
    type = t;
    value = v;
}
