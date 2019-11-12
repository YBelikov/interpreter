#include "binaryoperationnode.h"

BinaryOperationNode::BinaryOperationNode(ASTNode *l, Token token, ASTNode* r)
{
    left = l;
    right = r;
    operation = token;
}

QVariant BinaryOperationNode::accept(NodeVisitor* visitor){
   return visitor->visit(this);
}

BinaryOperationNode::~BinaryOperationNode(){
    delete left;
    delete right;
}
