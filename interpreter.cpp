#include "interpreter.h"
#include "numbernode.h"
#include "binaryoperationnode.h"
#include "unaryoperationnode.h"

#include <QDebug>

Interpreter::Interpreter()
{

}

QVariant Interpreter::visit(NumberNode* node){

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
   if(node->operation.type == TokenType::Plus){
       return QVariant{node->left->accept(this).toDouble() + node->right->accept(this).toDouble()};
   }else if(node->operation.type == TokenType::Minus){
       return QVariant{node->left->accept(this).toDouble() - node->right->accept(this).toDouble()};
   }else if(node->operation.type == TokenType::Mult){
       return QVariant{node->left->accept(this).toDouble() * node->right->accept(this).toDouble()};
   }else if(node->operation.type == TokenType::Div){
       return QVariant{node->left->accept(this).toDouble() / node->right->accept(this).toDouble()};
   }else if(node->operation.type == TokenType::Pow){
       return QVariant{pow(node->left->accept(this).toDouble(), node->right->accept(this).toDouble())};
   }
   return QVariant{};
}


double Interpreter::interpret(const QString& expr){
       parser.setExpression(expr);
       ASTNode *root = parser.parse();
       return root->accept(this).toDouble();
}





