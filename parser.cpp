#include "parser.h"
#include "numbernode.h"
#include "binaryoperationnode.h"
#include "unaryoperationnode.h"

#include <QDebug>

Parser::Parser()
{

}

void Parser::setExpression(const QString& expr){
    lexer.setExpression(expr);
    currentToken = lexer.getNextToken();
}

ASTNode* Parser::parse(){
    return expr();
}

void Parser::match(TokenType expected){
    if(currentToken.type == expected) currentToken = lexer.getNextToken();
    else return;
}

ASTNode* Parser::expr(){
    ASTNode *node = term();
    Token token;
    while(currentToken.type == TokenType::Plus || currentToken.type == TokenType::Minus || currentToken.type == TokenType::Pow){
        token = currentToken;
        if(token.type == TokenType::Plus){
            match(TokenType::Plus);
        }else if(token.type == TokenType::Minus){
            match(TokenType::Minus);
        }else if(token.type == TokenType::Pow){
            match(TokenType::Pow);
        }
         node = new BinaryOperationNode(node, token, term());
    }
    qDebug() << token.symbol;

    return node;
}

ASTNode* Parser::term(){
    ASTNode *node = factor();
    Token token;

    while(currentToken.type == TokenType::Mult || currentToken.type == TokenType::Div
           || currentToken.type == TokenType::Pow){
        token = currentToken;
        if(token.type == TokenType::Mult){
             match(TokenType::Mult);

         }else if(token.type == TokenType::Div){
             match(TokenType::Div);

         }else if(token.type == TokenType::Pow){
             match(TokenType::Pow);
         }
        node = new BinaryOperationNode(node, token, factor());
     }
     return node;
}

ASTNode* Parser::factor(){

    Token token = currentToken;
    if(token.type == TokenType::Plus){
        match(TokenType::Plus);
        ASTNode *node = new UnaryOperationNode(token, factor());
        return  node;
    }
    if(token.type == TokenType::Minus){
        match(TokenType::Minus);
        ASTNode *node = new UnaryOperationNode(token, factor());
        return node;
    }
    if(token.type == TokenType::Number){
        match(TokenType::Number);
        return new NumberNode(token);
    }else if(token.type == TokenType::LParen){
        match(TokenType::LParen);
        ASTNode *node = expr();
        match(TokenType::RParen);
        return node;
    }
    return nullptr;
}

