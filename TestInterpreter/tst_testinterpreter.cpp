#include <QtTest>
#include "interpreter.h"

// add necessary includes here
class TestInterpreter : public QObject
{
    Q_OBJECT

public:
    TestInterpreter();
    ~TestInterpreter();

private slots:
    void test_incorrectParenthesis();
    void test_incorrectNumberOfMultiplicationSigns();
    void test_incorrectNumberOfExponentSigns();
    void test_incorrectSymbolsInExpression();
private:
    Interpreter *interpreter;
};

TestInterpreter::TestInterpreter() : interpreter(new Interpreter){}

TestInterpreter::~TestInterpreter(){
    delete interpreter;
}

void TestInterpreter::test_incorrectNumberOfMultiplicationSigns(){
    QVERIFY(interpreter->interpret("3+4***2").isNull());
    interpreter->reset();
    QVERIFY(interpreter->interpret("3*").isNull());
    interpreter->reset();
    QVERIFY(interpreter->interpret("***2").isNull());
    interpreter->reset();
     QVERIFY(interpreter->interpret("3*(-2)+(((3*2").isNull());
    interpreter->reset();
}

void TestInterpreter::test_incorrectParenthesis(){
    QVERIFY(interpreter->interpret("2*((((3+2)--3)-2)").isNull());
    interpreter->reset();
    QVERIFY(interpreter->interpret("2^(((((3)+4-2").isNull());
    interpreter->reset();
    QVERIFY(interpreter->interpret("()(()((").isNull());
    interpreter->reset();

}

void TestInterpreter::test_incorrectNumberOfExponentSigns(){
    QVERIFY(interpreter->interpret("2^2^2^^3").isNull());
    interpreter->reset();
    QVERIFY(interpreter->interpret("2^(3^^^2) + 4").isNull());
    interpreter->reset();
    QVERIFY(interpreter->interpret("^32").isNull());
    interpreter->reset();
    QVERIFY(interpreter->interpret("3^").isNull());
    interpreter->reset();
}

void TestInterpreter::test_incorrectSymbolsInExpression(){
    QVERIFY(interpreter->interpret("2&^&").isNull());
    interpreter->reset();
    QVERIFY(interpreter->interpret("(2+(3*2)-(-3)+qsad)-3").isNull());
    interpreter->reset();
    QVERIFY(interpreter->interpret("@#!$(!$@!)").isNull());
    interpreter->reset();
}

QTEST_MAIN(TestInterpreter)
#include "tst_testinterpreter.moc"
