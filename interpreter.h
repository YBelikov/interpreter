#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <QString>
#include <QVariant>
#include "nodevisitor.h"
#include "parser.h"

class Interpreter : public NodeVisitor
{

private:
    Parser parser;
    QVariant error(){
        QVariant error{};
        error.setValue(nullptr);
        return error;
    }
public:
    Interpreter();
    QVariant interpret(const QString&);
    QVariant visit(NumberNode *) override;
    QVariant visit(BinaryOperationNode *) override;
    QVariant visit(UnaryOperationNode *) override;
    void setExpression(const QString&);
    void reset();

};

#endif // INTERPRETER_H
