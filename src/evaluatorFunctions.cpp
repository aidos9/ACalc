#ifndef EVAULATORFUNCTIONS_H
#define EVAULATORFUNCTIONS_H

#include "../headers/evaluator.h"
#include <cmath>

bool Evaluator::cmpf(double A, double B, double epsilon)
{
    return (fabs(A - B) < epsilon);
}

long long Evaluator::mod(long long number, long long divisor)
{
    long long x = static_cast<long long>(floor(number/divisor));
    return number - divisor * x;
}

long long Evaluator::gcd(long long a, long long b)
{
    long long c;
    long long d;

    if(a == b)
    {
        return a;
    }else if(a > b)
    {
        c = a;
        d = b;
    }else{
        c = b;
        d = a;
    }

    long long r = -1;
    while(r != 0)
    {
        r = mod(c, d);
        c = d;
        d = r;
    }

    return c;
}

long long Evaluator::lcm(long long a, long long b)
{
    return (a * b / gcd(a, b));
}

#endif // EVAULATORFUNCTIONS_H
