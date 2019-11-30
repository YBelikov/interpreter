#include "interpreter.h"
#include "numbernode.h"
#include "binaryoperationnode.h"
#include "unaryoperationnode.h"

#include <QDebug>

Interpreter::Interpreter()
{

}

QVariant Interpreter::visit(NumberNode* node){
    if(!node) return error();
    return node->getValue();
}

QVariant Interpreter::visit(UnaryOperationNode* node){

    if(node->operation.type == TokenType::Plus){
            return node->child->accept(this);
        }else if(node->operation.type == TokenType::Minus){
            return QVariant{-node->child->accept(this).toDouble()};
        }
        return QVariant{};
}

QVariant Interpreter::visit(BinaryOperationNode* node){
   QVariant leftOp = node->left->accept(this);
   QVariant rightOp= node->right->accept(this);
   if(leftOp.isNull() || rightOp.isNull()) return error();
   if(node->operation.type == TokenType::Plus){
       return leftOp.toDouble() + rightOp.toDouble();
   }else if(node->operation.type == TokenType::Minus){
       return leftOp.toDouble() - rightOp.toDouble();
   }else if(node->operation.type == TokenType::Mult){
       return leftOp.toDouble() * rightOp.toDouble();
   }else if(node->operation.type == TokenType::Div){
       if(rightOp.toDouble() == 0.0 ) return error();
       return leftOp.toDouble() / rightOp.toDouble();
   }else if(node->operation.type == TokenType::Pow){
       return pow(leftOp.toDouble(), rightOp.toDouble());
   }
   return error();
}



QVariant Interpreter::interpret(const QString& expr){
       parser.setExpression(expr);
       ASTNode *root = parser.parse();
       if(!root) return error();
       QVariant res = root->accept(this);
       if(res.isNull()) return error();
       return res.toDouble();
}

void Interpreter::reset(){
    parser.reset();
}




