#ifndef ASTEVALUATOR_H
#define ASTEVALUATOR_H

#include "astNode.h"
#include <exception>
#include <string>

namespace ASTEvaluator {
    double evaluateNode(ASTNode* node);

    class ASTException : public std::exception
    {
    public:
        ASTException(const std::string& d, const int& c);
        std::string description;
        int code;
        const char * what () const noexcept
        {
            return description.c_str();
        }
    };
}

#endif // ASTEVALUATOR_H
