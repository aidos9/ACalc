#ifndef ASTEVALUATOR_H
#define ASTEVALUATOR_H

#include "expressions.h"
#include "exception.h"
#include <string>

namespace Evaluator {
    double evaluateNode(std::shared_ptr<Expression> e);
}

#endif // ASTEVALUATOR_H
