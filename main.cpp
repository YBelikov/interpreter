#include <QCoreApplication>
#include <QDebug>
#include "interpreter.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString exp = "(1+2)^(1+1)";
    Interpreter interp;
    interp.setExpression(exp);
    qDebug() << interp.expr();

    return a.exec();
}
