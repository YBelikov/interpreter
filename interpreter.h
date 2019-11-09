#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <QString>
#include <QVariant>

enum class TokenType{Number, Plus, Minus, Div, Mult, LParen, RParen, Pow, EndOfText};

struct Token{
    QVariant value;
    QChar symbol;
    TokenType type;
};

class Interpreter
{

private:

    QString expression;
    quint32 position;
    Token currentToken;
    void deleteWhiteSpaces();
    void match(TokenType);
    Token getNextToken();
    void advance();
    QString number();
    QVariant term();
    QVariant factor();


public:
    Interpreter();
    double expr();
    void setExpression(const QString&);

};

#endif // INTERPRETER_H
