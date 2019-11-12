#ifndef BINARYOPERATIONNODE_H
#define BINARYOPERATIONNODE_H

#include "astnode.h"
#include "token.h"
#include "nodevisitor.h"

class BinaryOperationNode : public ASTNode
{
public:
    ASTNode *left;
    ASTNode *right;
    Token operation;
    BinaryOperationNode(ASTNode*, Token, ASTNode*);
    QVariant accept(NodeVisitor *vis) override;
    ~BinaryOperationNode() override;
};

#endif // BINARYOPERATIONNODE_H
