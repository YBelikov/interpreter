#include "interpreter.h"
#include <QDebug>

Interpreter::Interpreter()
{
    position = 0;

}

void Interpreter::setExpression(const QString& expr){
    expression = expr;
    deleteWhiteSpaces();
    expression.push_back(QChar::Null);
    currentToken = getNextToken();
}

void Interpreter::deleteWhiteSpaces(){
    expression.replace(" ", "");
}

void Interpreter::advance(){
    if(expression[position] != QChar::Null)
         ++position;
}
QString Interpreter::number(){
    QString res;
    while(expression[position].isNumber() || expression[position] == '.'){
        res += expression[position];
        advance();
    }
    qDebug() << res;
    return res;
}
void Interpreter::match(TokenType expected){
    if(currentToken.type == expected) currentToken = getNextToken();
    else return;
}

double Interpreter::expr(){

    double result = term().toDouble();

    qDebug() << currentToken.value;

    while(currentToken.type == TokenType::Plus || currentToken.type == TokenType::Minus || currentToken.type == TokenType::Pow){

        Token token = currentToken;
        if(token.type == TokenType::Plus){
            match(TokenType::Plus);
            result += term().toDouble();
        }else if(token.type == TokenType::Minus){
            match(TokenType::Minus);
            result  -= term().toDouble();
        }else if(token.type == TokenType::Pow){
            match(TokenType::Pow);
            result = pow(result, expr());
        }
    }
    return result;
}


Token Interpreter::getNextToken(){
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
    }
  }
    return token;

}

QVariant Interpreter::term(){
   double result = factor().toDouble();
    while(currentToken.type == TokenType::Mult || currentToken.type == TokenType::Div || currentToken.type == TokenType::Pow){
        Token token = currentToken;
        if(token.type == TokenType::Mult){
            match(TokenType::Mult);
            result *= factor().toDouble();
        }else if(token.type == TokenType::Div){
            match(TokenType::Div);
            result /= factor().toDouble();
        }else if(token.type == TokenType::Pow){
            match(TokenType::Pow);
            result = pow(result, factor().toDouble());
        }
    }
    return QVariant{result};
}

QVariant Interpreter::factor(){
    Token token = currentToken;
    if(token.type == TokenType::Number){
        match(TokenType::Number);
        return token.value;
    }else if(token.type == TokenType::LParen){
        match(TokenType::LParen);
        QVariant result = QVariant{expr()};
        match(TokenType::RParen);
        return result;
    }
}
