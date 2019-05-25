#ifndef BINARY_H
#define BINARY_H

#include "expression.h"
#include "token.h"
#include <memory>

class Binary : public Expression
{
public:
    Binary(std::shared_ptr<Expression> l, Token o, std::shared_ptr<Expression> r);

    std::shared_ptr<Expression> getLeft() const;
    Token getOp() const;
    std::shared_ptr<Expression> getRight() const;

private:
    std::shared_ptr<Expression> left;
    Token op;
    std::shared_ptr<Expression> right;
};

#endif // BINARY_H
