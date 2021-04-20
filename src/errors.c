#include "../include/C+-.h"

void error(const int error_code, char *lex){
    if(error_code is SyntaxError){
       printf("\033[0;31mSyntax error: \033[0;37m no such instruction '%s'\n", lex);
    }

    elif(error_code is OverFlowError){
       printf("\033[0;31mOverFlow error: \033[0;37m%s\n", lex);
    }

    elif(error_code is WhiteSpaceWarning){
       printf("\033[0;35mWhiteSpaceWarning: \033[0;37m%s\n", lex);
    }

    elif(error_code is ArithmeticError){
        printf("033[0;35mArithmetic Error: \033[0;37m%s\n", lex);
    }

    elif(error_code is FloatingPointError){
        printf("033[0;35mFloating Point Error: \033[0;37m%s\n", lex);
    }

    elif(error_code is IncludeError){
        printf("033[0;35mInclude Error: \033[0;37m%s\n", lex);
    }

    elif(error_code is MemoryOverload){
        printf("033[0;35mMemory Overload: \033[0;37m%s\n", lex);
    }

    elif(error_code is RunTimeError){
        printf("033[0;35mInclude Error: \033[0;37m%s\n", lex);
    }

    elif(error_code is ZeroDivisionError){
        printf("033[0;35mInclude Error: \033[0;37m%s\n", lex);
    }

    elif(error_code is FileNotExist){
        printf("033[0;35mInclude Error: \033[0;37m%s\n", lex);
    }

    elif(error_code is TypeError){
        printf("033[0;35mInclude Error: \033[0;37m%s\n", lex);
    }
}