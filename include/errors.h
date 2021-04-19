#ifndef ERRORS_H
#define ERRORS_H

//errors & warningsthat can happen in the program

enum _Errors{
    SyntaxError = 0,
    OverFlowError = 1,
    WhiteSpaceWarning = 2,
};
typedef enum _Errors Errors;


void error(const int error_code, char *lex);


#endif //ERRORS_H