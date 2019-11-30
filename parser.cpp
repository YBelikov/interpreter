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

int Parser::match(TokenType expected){
    if(currentToken.type == expected){
        currentToken = lexer.getNextToken();
        return 1;
    }
    else return 0;
}

ASTNode* Parser::expr(){
    ASTNode *node = term();
    Token token;
    if(currentToken.type == TokenType::Error) return nullptr;
    while(currentToken.type == TokenType::Plus || currentToken.type == TokenType::Minus /*|| currentToken.type == TokenType::Pow*/){
        token = currentToken;
        if(token.type == TokenType::Plus){
            if(!match(TokenType::Plus)) return nullptr;
        }else if(token.type == TokenType::Minus){
            if(!match(TokenType::Minus)) return nullptr;
        }/*else if(token.type == TokenType::Pow){

            if(!match(TokenType::Pow)) return nullptr;
        }*/
         node = new BinaryOperationNode(node, token, term());
    }
    qDebug() << token.symbol;

    return node;
}

ASTNode* Parser::term(){
    ASTNode *node = factor();
    Token token;
    if(currentToken.type == TokenType::Error) return nullptr;
    while(currentToken.type == TokenType::Mult || currentToken.type == TokenType::Div
           /*|| currentToken.type == TokenType::Pow*/){
        token = currentToken;
        if(token.type == TokenType::Mult){
             if(!match(TokenType::Mult)) return nullptr;

         }else if(token.type == TokenType::Div){
             if(!match(TokenType::Div)) return nullptr;
         }/*else if(token.type == TokenType::Pow){
             if(!match(TokenType::Pow)) return nullptr;
         }*/
        node = new BinaryOperationNode(node, token, factor());
     }
     return node;
}

ASTNode* Parser::factor(){
    Token token;
    ASTNode* node = exponent();
    token = currentToken;
    if(token.type == TokenType::Error) return nullptr;
    else if(token.type == TokenType::Pow){
        token = currentToken;
        if(!match(TokenType::Pow)) return nullptr;
        node = new BinaryOperationNode(node, token, factor());
    }
     return node;
}

ASTNode* Parser::exponent(){
    Token token = currentToken;
    if(token.type == TokenType::Error) return nullptr;
    if(token.type == TokenType::Plus){
        if(!match(TokenType::Plus)) return nullptr;
        ASTNode *node = new UnaryOperationNode(token, factor());
        return  node;
    }
    if(token.type == TokenType::Minus){
        if(!match(TokenType::Minus)) return nullptr;
        ASTNode *node = new UnaryOperationNode(token, factor());
        return node;
    }
    if(token.type == TokenType::Number){
        if(!match(TokenType::Number)) return nullptr;
        return new NumberNode(token);
    }else if(token.type == TokenType::LParen){
        if(!match(TokenType::LParen)) return nullptr;
        ASTNode *node = expr();
        if(!match(TokenType::RParen)) return nullptr;
        return node;
    }
    return nullptr;
}

void Parser::reset(){
    lexer.reset();
}

