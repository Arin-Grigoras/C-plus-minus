#include "../include/parser.h"
#include "../include/cnpython.h"
#include "../include/errors.h"



ParserStatus parser_start(TokenList* list, const char* source){
    char lex[256];
    int lexi = 0;
    int i = 0;
    int line = 1;
    
    while(True){
        //memset(lex, '\0', 256);

        while(source[i] isnt ' ' and source[i] isnt '\n' and source[i] isnt '\0' and source[i] isnt '\t' and source[i] isnt '\r' and source[i] isnt '\v' and source[i] isnt '\f'){
            lex[lexi++] = source[i++];
        }
        
        lex[lexi] = '\0';


        if(lex[0] is '#'){
            int num = parser_get_number(lex);
            //printf("NUMBER: %d\n", num);
            token_list_add(list, token_create(NUMBER, num, line));
        }
        
        //If it isn't a number it is an instruction
        else{
            int inst = parser_get_inst(lex);
            if(inst >= 0){
                //printf("INST: %s\n", lex);
                token_list_add(list, token_create(INST, inst, line));
            }

            //Tried to make it so if it's just an empty character it ignores it
            /*elif(lex is NULL){
                continue;
            }*/

            else{
                error(SyntaxError, lex);
                return PARSER_SYNTAX_ERROR;
            }
        }

        if(source[i] is '\n'){
            line++;
        }
        else if(source[i] is '\0'){
            break;
        }

        lexi = 0;
        i++;

    }

    return PARSER_SUCCES;

}


uint32_t parser_get_number(const char* buf){
    long num = atoi(&buf[1]);

    if(num > UINT32_MAX){
        error(OverFlowError, NULL);
        return OverFlowError;
    }

    return num;
}


TokenInst parser_get_inst(const char* buf){
    if(strcmp(buf, "push") is 0){
        return push;
    }
    if(strcmp(buf, "add") is 0){
        return add;
    }
    if(strcmp(buf, "hlt") is 0){
        return hlt;
    }
    else{
        return (TokenInst)-1;
    }
}