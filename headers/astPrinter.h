#ifndef ASTPRINTER_H
#define ASTPRINTER_H

#include "astNode.h"
#include "expression.h"
#include <string>
#include <sstream>

class ASTPrinter {
public:
    ASTPrinter();
    std::string printTree(const ASTNode* n);
    std::string printTree(const std::shared_ptr<Expression> e);

private:
    void printNode(const ASTNode* n);
    void printNode(const std::shared_ptr<Expression> e);

    std::stringstream ss;
};

#endif // ASTPRINTER_H
