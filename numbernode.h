#ifndef NUMBERNODE_H
#define NUMBERNODE_H

#include "astnode.h"
#include "token.h"
#include "nodevisitor.h"
class NumberNode : public ASTNode
{
private:
    Token operation;
    QVariant value;
    QVariant accept(NodeVisitor *vis) override;

public:
    QVariant getValue(){return value;};
    explicit NumberNode(Token);
    ~NumberNode() override;
};

#endif // NUMBERNODE_H
