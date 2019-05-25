#include "../headers/unary.h"

Unary::Unary(Token o, std::shared_ptr<Expression> r)
{
    op = o;
    right = r;
    type = uny;
}

std::shared_ptr<Expression> Unary::getRight() const
{
    return right;
}

Token Unary::getOp() const
{
    return op;
}
