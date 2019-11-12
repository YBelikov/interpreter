#ifndef UNARYOPERATIONNODE_H
#define UNARYOPERATIONNODE_H

#include "astnode.h"
#include "token.h"
#include "nodevisitor.h"

class Token;
class UnaryOperationNode : public ASTNode
{
public:
    UnaryOperationNode(Token, ASTNode*);
    ~UnaryOperationNode() override;
    QVariant accept(NodeVisitor *) override;
    Token operation;
    ASTNode *child;

};

#endif // UNARYOPERATIONNODE_H
