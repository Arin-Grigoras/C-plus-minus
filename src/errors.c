#include "../include/C+-.h"

void error(const int error_code, char *lex){
   if(error_code is SyntaxError){
       printf("\033[0;31mSyntax error: \033[0;37m no such instruction '%s'\n", lex);
   }

   elif(error_code is OverFlowError){
       printf("\033[0;31mOverFlow error: \033[0;37m%s\n", lex);
   }

   elif(error_code is WhiteSpaceWarning){
       printf("\033[0;35mWhiteSpaceWarning: %s\n", lex);
   }
}