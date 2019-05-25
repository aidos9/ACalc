#ifndef UNARY_H
#define UNARY_H

#include "expression.h"
#include "token.h"

class Unary : public Expression
{
public:
    Unary(Token o, std::shared_ptr<Expression> r);

private:
    Token op;
    std::shared_ptr<Expression> right;
};

#endif // UNARY_H
