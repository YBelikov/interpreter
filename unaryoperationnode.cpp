#include "unaryoperationnode.h"

UnaryOperationNode::UnaryOperationNode(Token token, ASTNode* node)
{
    operation = token;
    child = node;
}

QVariant UnaryOperationNode::accept(NodeVisitor *visitor){
    return visitor->visit(this);
}

UnaryOperationNode::~UnaryOperationNode(){
    delete child;
}
