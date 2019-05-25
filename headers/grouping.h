#ifndef GROUPING_H
#define GROUPING_H

#include "expression.h"
#include <memory>

class Grouping : public Expression
{
public:
    Grouping(std::shared_ptr<Expression> e);

    std::shared_ptr<Expression> getExpression() const;

private:
    std::shared_ptr<Expression> expr;
};

#endif // GROUPING_H
