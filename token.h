#ifndef TOKEN_H
#define TOKEN_H

#include <QVariant>
#include <QString>

enum class TokenType{Number, Plus, Minus, Div, Mult, LParen, RParen, Pow, EndOfText, Error};

class Token {
public:
    QVariant value;
    QChar symbol;
    TokenType type;
    explicit Token();
};

#endif // TOKEN_H
