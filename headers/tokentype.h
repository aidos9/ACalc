#ifndef TOKENTYPE_H
#define TOKENTYPE_H

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
};

#endif // TOKENTYPE_H
