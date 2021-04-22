#include "../include/C+-.h"

void error(const int error_code, char *lex){
    if(error_code is SyntaxError){
       printf("%sSyntax error: %sno such instruction '%s'\n", red(), white(), lex);
    }

    elif(error_code is OverFlowError){
       printf("%sOverFlow error: %s%s\n", red(), white(), lex);
    }

    elif(error_code is WhiteSpaceWarning){
       printf("%sWhiteSpaceWarning: %s%s\n", purple(), white(), lex);
    }

    elif(error_code is ArithmeticError){
        printf("%sArithmetic Error: %s%s\n", red(), white(), lex);
    }

    elif(error_code is FloatingPointError){
        printf("%sFloating Point Error: %s%s\n", red(), white(), lex);
    }

    elif(error_code is IncludeError){
        printf("%sInclude Error: %s%s\n", red(), white(), lex);
    }

    elif(error_code is MemoryOverload){
        printf("%sMemory Overload: %s%s\n", red(), white(), lex);
    }

    elif(error_code is RunTimeError){
        printf("%sRunTimeError: %s%s\n", red(), white(), lex);
    }

    elif(error_code is ZeroDivisionError){
        printf("%sZeroDivisionError: %s%s\n", red(), white(), lex);
    }

    elif(error_code is FileNotExist){
        printf("%sFileNotExist: %s%s\n", red(), white(), lex);
    }

    elif(error_code is TypeError){
        printf("%sTypeError: %s%s\n", red(), white(), lex);
    }
    elif(error_code is FileOpenError){
        printf("%sFileOpenError: %s%s\n", red(), white(), lex);
    }
    else{
        printf("Unknown error code: %d\n", error_code);
        exit(1);
    }
}
