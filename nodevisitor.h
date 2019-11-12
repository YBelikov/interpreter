#ifndef NODEVISITOR_H
#define NODEVISITOR_H

class NumberNode;
class BinaryOperationNode;
class UnaryOperationNode;
class QVariant;

class NodeVisitor
{
public:

    virtual QVariant visit(NumberNode*) = 0;
    virtual QVariant visit(BinaryOperationNode*) = 0;
    virtual QVariant visit(UnaryOperationNode*) = 0;
    virtual ~NodeVisitor();
protected:
    NodeVisitor();
};

#endif // NODEVISITOR_H
