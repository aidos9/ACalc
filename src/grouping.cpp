#include "../headers/grouping.h"

Grouping::Grouping(std::shared_ptr<Expression> e)
{
    expr = e;
    type = grp;
}

std::shared_ptr<Expression> Grouping::getExpression() const
{
    return expr;
}
