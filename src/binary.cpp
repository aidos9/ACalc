#include "../headers/binary.h"

Binary::Binary(std::shared_ptr<Expression> l, Token o, std::shared_ptr<Expression> r)
{
    left = l;
    op = o;
    right = r;
    type = bin;
}

std::shared_ptr<Expression> Binary::getLeft() const
{
    return left;
}

Token Binary::getOp() const
{
    return op;
}

std::shared_ptr<Expression> Binary::getRight() const
{
    return right;
}
