#ifndef ASTEVALUATOR_H
#define ASTEVALUATOR_H

#include "expressions.h"
#include "exception.h"
#include <string>

namespace Evaluator {
    double evaluateNode(std::shared_ptr<Expression> e);
    long long mod(long long number, long long divisor);
    long long gcd(long long a, long long b);
}

#endif // ASTEVALUATOR_H
