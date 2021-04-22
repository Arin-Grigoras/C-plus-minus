#ifndef ERRORS_H
#define ERRORS_H

#include "./C+-.h"

//errors & warningsthat can happen in the program


//ERRORS
#define SyntaxError 0
#define OverFlowError 1
#define ArithmeticError 2
#define FloatingPointError 3
#define IncludeError 4
#define MemoryOverload 5
#define RunTimeError 6

#ifdef ZeroDivisionError
    #undef ZeroDivisionError
    #define ZeroDivisionError 7
#endif

#define FileNotExist 8
#define TypeError 9
#define IllegalExpression 10
#ifdef FileOpenError
    #undef FileOpenError
    #define FileOpenerror 11
#endif

//WARNINGS
#define WhiteSpaceWarning 12


void error(const int error_code, char *lex, const int line);


#endif //ERRORS_H
