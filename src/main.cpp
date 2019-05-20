#include "../headers/astNode.h"
#include "../headers/astEvaluator.h"
#include "../headers/astPrinter.h"
#include <iostream>

int main()
{
    ASTNode fiveNode = ASTNode(ASTOperation::ast_none, 5, nullptr, nullptr);
    ASTNode fourNode = ASTNode(ASTOperation::ast_none, 4, nullptr, nullptr);
    ASTNode addNode = ASTNode(ASTOperation::ast_add, &fiveNode, &fourNode);
    ASTNode threeNode = ASTNode(ASTOperation::ast_none, 3, nullptr, nullptr);
    ASTNode sixNode = ASTNode(ASTOperation::ast_none, 6, nullptr, nullptr);
    ASTNode subNode = ASTNode(ASTOperation::ast_sub, &sixNode, &threeNode);
    ASTNode timesNode = ASTNode(ASTOperation::ast_mul, &addNode, &subNode);
    ASTNode nineNode = ASTNode(ASTOperation::ast_none, 9, nullptr, nullptr);
    ASTNode divNode = ASTNode(ASTOperation::ast_div, &timesNode, &nineNode);
    ASTNode secMul = ASTNode(ASTOperation::ast_mul, &fiveNode, &fourNode);
    ASTNode secAddNode = ASTNode(ASTOperation::ast_add, &divNode, &secMul);

    double result = ASTEvaluator::evaluateNode(&secAddNode);

    std::cout << result << std::endl;
    ASTPrinter printer;
    std::cout << printer.printTree(&secAddNode) << " = " << result << std::endl;
    return 0;
}
