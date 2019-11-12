#include <QCoreApplication>
#include <QDebug>
#include "interpreter.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString exp = "2^(-3)";
    Interpreter interp;
    qDebug() << interp.interpret(exp);

    return a.exec();
}
