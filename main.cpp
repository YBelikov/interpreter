#include <QCoreApplication>
#include <QDebug>
#include "interpreter.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Interpreter interp;
    QVariant res = interp.interpret("(-2)^-2");
    if(res.isNull()) qDebug() << "Error";
    else qDebug() << res.toDouble();
    return a.exec();
}
