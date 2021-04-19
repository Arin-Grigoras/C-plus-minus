#include "../include/errors.h"
#include "../include/cnpython.h"

void error(const int error_code, char *lex){
   if(error_code is SyntaxError){
       printf("\033[0;31mSyntax error: \033[0;37m no such instruction '%s'\n", lex);
   } 
}