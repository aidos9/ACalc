#ifndef ASTNODE_H
#define ASTNODE_H

enum ASTOperation {
    ast_add = 0,
    ast_sub = 1,
    ast_div = 2,
    ast_mul = 3,
    ast_none = 4,
};

class ASTNode
{
public:
    ASTNode(const ASTOperation& o, const double& v, ASTNode* l, ASTNode* r);
    ASTNode(const ASTOperation& o, ASTNode* l, ASTNode* r);

    ASTOperation getOperation() const;
    double getValue() const;
    ASTNode* getLeft() const;
    ASTNode* getRight() const;
    bool getHasValue() const;

private:
    ASTOperation op;
    double value;
    ASTNode* left;
    ASTNode* right;
    bool hasValue = false;
};

#endif // ASTNODE_H
