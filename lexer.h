#ifndef LEXER_H
#define LEXER_H

#include "token.h"

class Lexer
{
public:

    Lexer();
    void setExpression(const QString&);
    Token getNextToken();

private:

    void deleteWhiteSpaces();
    QString expression;
    quint32 position;
    void advance();
    QString number();

};

#endif // LEXER_H
