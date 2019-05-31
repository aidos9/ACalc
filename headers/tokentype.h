#ifndef TOKENTYPE_H
#define TOKENTYPE_H

#include <string>

enum TokenType
{
    tok_add = 0,
    tok_sub = 1,
    tok_mul = 2,
    tok_div = 3,
    tok_number = 4,
    tok_eof = 5,
    tok_lParen = 6,
    tok_rParen = 7,
    tok_exp = 8,
    tok_mod = 9,
    tok_identifier = 10,
    tok_comma = 11,
    tok_call = 12,
};

inline std::string tokenTypeToString(const TokenType& t)
{
    switch (t) {
    case tok_add:
        return "Token-Add";
    case tok_sub:
        return "Token-Subtract";
    case tok_mul:
        return "Token-Multiply";
    case tok_div:
        return "Token-Divide";
    case tok_exp:
        return "Token-Exponent";
    case tok_mod:
        return "Token-Modulo";
    case tok_number:
        return "Token-Number";
    case tok_lParen:
        return "Token-Left-Parentheses";
    case tok_rParen:
        return "Token-Right-Parentheses";
    case tok_eof:
        return "Token-End-Of-File";
    case tok_identifier:
        return "Token-Identifier";
    case tok_comma:
        return "Token-Comma";
    case tok_call:
        return "Token-Call";
    }
}

#endif // TOKENTYPE_H
