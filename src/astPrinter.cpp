#include "../headers/astPrinter.h"

ASTPrinter::ASTPrinter()
{
    ss = std::stringstream();
}

void ASTPrinter::printNode(const ASTNode* n)
{
    if(n->getOperation() == ASTOperation::ast_none)
    {
        ss << n->getValue();
    }else if(n->getOperation() == ASTOperation::ast_div)
    {
        printNode(n->getLeft());
        ss << " / ";
        printNode(n->getRight());
    }else if(n->getOperation() == ASTOperation::ast_mul)
    {
        printNode(n->getLeft());
        ss << " * ";
        printNode(n->getRight());
    }else if(n->getOperation() == ASTOperation::ast_add)
    {
        ss << "(";
        printNode(n->getLeft());
        ss << " + ";
        printNode(n->getRight());
        ss << ")";
    }else if(n->getOperation() == ASTOperation::ast_sub)
    {
        ss << "(";
        printNode(n->getLeft());
        ss << " - ";
        printNode(n->getRight());
        ss << ")";
    }
}

std::string ASTPrinter::printTree(const ASTNode* n)
{
    printNode(n);
    return ss.str();
}
