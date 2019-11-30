QT += testlib
QT -= gui

CONFIG += qt console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app


SOURCES +=  tst_testinterpreter.cpp\
            D:/cpp/QtProjects/interpreter/interpreter.cpp\
        D:/cpp/QtProjects/interpreter/astnode.cpp \
        D:/cpp/QtProjects/interpreter/binaryoperationnode.cpp \
        D:/cpp/QtProjects/interpreter/interpreter.cpp \
        D:/cpp/QtProjects/interpreter/lexer.cpp \
        D:/cpp/QtProjects/interpreter/nodevisitor.cpp \
        D:/cpp/QtProjects/interpreter/numbernode.cpp \
        D:/cpp/QtProjects/interpreter/parser.cpp \
        D:/cpp/QtProjects/interpreter/token.cpp \
        D:/cpp/QtProjects/interpreter/unaryoperationnode.cpp \
        D:/cpp/QtProjects/interpreter/variablenode.cpp



INCLUDEPATH += "D:\cpp\QtProjects\interpreter"
