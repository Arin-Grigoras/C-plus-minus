/*    C*  Copyright (C) 2021  Arin Grigoras
    This program comes with ABSOLUTELY NO WARRANTY; for details type `show w'.
    This is free software, and you are welcome to redistribute it
    under certain conditions; type `show c' for details.
*/

#include "../include/cnpython.h"
#include "../include/util.h"
#include "../include/parser.h"
#include "../include/token.h"
#include "../include/compiler.h"


int main(int argc, char *argv[]){
    //HEART
    if(argc<3){
        //We want to transpile and run the program all in one
    }

    //'is' is a keyword in the cnpython library. check ../include/cnpython.h for more details
    //we want to only transpile the program into its C++ form
    if(strcmp(argv[1], "transpile") is 0){
        char* source = read_ascii_file(argv[2]);
        TokenList tokens;
        token_list_create(&tokens, 1);
        ParserStatus pstat = parser_start(&tokens, source);
        if(pstat isnt PARSER_SUCCES){
            return 1;
        }

        CompilerStatus cstat = compiler_start(&tokens);
        
        if(cstat isnt COMPILER_SUCCES){
            return 1;
        }

        /*for(int i = 0; i < tokens.ptr; i++){
            Token* t = token_list_get(&tokens, i);
            printf("%d, %d, %d\n", t->type, t->data, t->line);
        }*/

        token_list_destroy(&tokens);
        free(source);
    }

    return 0;
}