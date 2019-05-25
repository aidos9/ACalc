#ifndef UNARY_H
#define UNARY_H

#include "expression.h"
#include "token.h"

class Unary : public Expression
{
public:
    Unary(Token o, std::shared_ptr<Expression> r);

    std::shared_ptr<Expression> getRight() const;
    Token getOp() const;

private:
    Token op;
    std::shared_ptr<Expression> right;
};

#endif // UNARY_H
