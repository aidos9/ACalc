#include "../headers/unary.h"

Unary::Unary(Token o, std::shared_ptr<Expression> r)
{
    op = o;
    right = r;
    type = uny;
}
