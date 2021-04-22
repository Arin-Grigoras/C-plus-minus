#include "../include/C+-.h"

void error(const int error_code, char *lex, const int line){
    if(error_code == SyntaxError){
       printf("%sSyntax error: %sno such instruction '%s' at line: %d\n", red(), white(), lex, line);
    }

    else if(error_code == OverFlowError){
       printf("%sOverFlow error: %s%s at line: %d\n", red(), white(), lex, line);
    }

    else if(error_code == WhiteSpaceWarning){
       printf("%sWhiteSpaceWarning: %s%s at line: %d\n", purple(), white(), lex, line);
    }

    else if(error_code == ArithmeticError){
        printf("%sArithmetic Error: %s%s at line: %d\n", red(), white(), lex, line);
    }

    else if(error_code == FloatingPointError){
        printf("%sFloating Point Error: %s%s at line: %d\n", red(), white(), lex, line);
    }

    else if(error_code == IncludeError){
        printf("%sInclude Error: %s%s at line: %d\n", red(), white(), lex, line);
    }

    else if(error_code == MemoryOverload){
        printf("%sMemory Overload: %s%s at line: %d\n", red(), white(), lex, line);
    }

    else if(error_code == RunTimeError){
        printf("%sRunTimeError: %s%s at line: %d\n", red(), white(), lex, line);
    }

    else if(error_code == ZeroDivisionError){
        printf("%sZeroDivisionError: %s%s at line: %d\n", red(), white(), lex, line);
    }

    else if(error_code == FileNotExist){
        printf("%sFileNotExist: %s%s at line: %d\n", red(), white(), lex, line);
    }

    else if(error_code == TypeError){
        printf("%sTypeError: %s%s at line: %d\n", red(), white(), lex, line);
    }
    else if(error_code == FileOpenError){
        printf("%sFileOpenError: %s%s at line %d\n", red(), white(), lex, line);
    }
    else{
        printf("Unknown error code: %d\n", error_code);
        exit(1);
    }
}
