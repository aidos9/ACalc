#ifndef ASTEVALUATOR_H
#define ASTEVALUATOR_H

#include "astNode.h"
#include "expressions.h"
#include "exception.h"
#include <string>

namespace ASTEvaluator {
    double evaluateNode(ASTNode* node);
    double evaluateNode(std::shared_ptr<Expression> e);
}

#endif // ASTEVALUATOR_H
