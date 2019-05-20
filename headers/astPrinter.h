#ifndef ASTPRINTER_H
#define ASTPRINTER_H

#include "astNode.h"
#include <string>
#include <sstream>

class ASTPrinter {
public:
    ASTPrinter();
    std::string printTree(const ASTNode* n);

private:
    void printNode(const ASTNode* n);
    std::stringstream ss;
};

#endif // ASTPRINTER_H
