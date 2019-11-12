#ifndef ASTNODE_H
#define ASTNODE_H

class NodeVisitor;
class QVariant;
enum class TokenType;

class ASTNode
{
public:
    virtual ~ASTNode();
    virtual QVariant accept(NodeVisitor*) = 0;

protected:
    ASTNode();

};

#endif // ASTNODE_H
