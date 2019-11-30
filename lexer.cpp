#include "lexer.h"

Lexer::Lexer()
{
    position = 0;

}

void Lexer::setExpression(const QString& expr){
    expression = expr;
    deleteWhiteSpaces();
    expression.push_back(QChar::Null);
}

void Lexer::deleteWhiteSpaces(){
    expression.replace(" ", "");
}

Token Lexer::getNextToken(){
    Token token;
    token.type = TokenType::EndOfText;
    while(expression[position] != QChar::Null){

    if(expression[position].isNumber()){
        token.type = TokenType::Number;
        token.value = QVariant{number()};
        return token;
    }
    else if(expression[position] == '+'){
        token.type = TokenType::Plus;
        token.symbol = '+';
        ++position;
        return token;
    }else if(expression[position] == '-'){
        token.type = TokenType::Minus;
        token.symbol = '-';
        ++position;
        return token;
    }else if(expression[position] == '*'){
        token.type = TokenType::Mult;
        token.symbol = '*';
        ++position;
        return token;
    }else if(expression[position] == '/'){
        token.type = TokenType::Div;
        token.symbol = '/';
        ++position;
        return token;
    }else if(expression[position] == '('){
        token.type = TokenType::LParen;
        token.symbol = '(';
        ++position;
        return token;
    }else if(expression[position] == ')'){
        token.type = TokenType::RParen;
        token.symbol = ')';
        ++position;
        return token;
    }else if(expression[position] == '^'){
        token.type = TokenType::Pow;
        token.symbol = '^';
        ++position;
        return token;
    }else{
        token.type = TokenType::Error;
        ++position;
        return token;
    }
  }
    return token;
}

void Lexer::advance(){
    if(expression[position] != QChar::Null)
         ++position;
}

QString Lexer::number(){
    QString res;
    while(expression[position].isNumber() || expression[position] == '.'){
        res += expression[position];
        advance();
    }

    return res;
}

void Lexer::reset(){
    position = 0;
}
