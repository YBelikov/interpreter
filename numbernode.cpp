#include "numbernode.h"

NumberNode::NumberNode(Token token)
{
    operation = token;
    value = token.value;
}

QVariant NumberNode::accept(NodeVisitor* visitor){
    return visitor->visit(this);
}

NumberNode::~NumberNode(){
    delete this;
}
