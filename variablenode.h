#ifndef VARIABLENODE_H
#define VARIABLENODE_H

#include "astnode.h"
#include "token.h"
#include "nodevisitor.h"

class VariableNode : public ASTNode
{
public:
    Token variable;
    ASTNode *child;
    VariableNode(Token, ASTNode*);
};

#endif // VARIABLENODE_H
