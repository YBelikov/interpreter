#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include "astnode.h"

class Parser
{
private:
    Lexer lexer;
    Token currentToken;
public:

    Parser();
    void setExpression(const QString& expr);
    int match(TokenType);
    void reset();
    ASTNode* expr();
    ASTNode* term();
    ASTNode* factor();
    ASTNode* exponent();
    ASTNode* parse();

};

#endif // PARSER_H
