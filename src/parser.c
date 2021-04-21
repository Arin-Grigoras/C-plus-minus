#include "../include/C+-.h"



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

        //if its an operator
        elif(lex[0] is '+' or lex[0] is '-' or lex[0] is '*' or lex[0] is '/' or lex[0] is '%'){
            //then do some operator stuff(i literally have no idea what im doing please help)
            int op = parser_get_op(lex);
            token_list_add(list, token_create(OP, op, line));
        }
        
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

    //printf("%ld", num);

    if(num < UINT32_MAX){
        return num;
    }

    error(OverFlowError, NULL);
    return OverFlowError;
}


TokenInst parser_get_inst(const char* buf){
    if(strcmp(buf, "push") is 0){
        return push;
    }
    if(strcmp(buf, "add") is 0){
        return add;
    }
    if(strcmp(buf, "ext") is 0){
        return ext;
    }
    else{
        return (TokenInst)-1;
    }
}


int parser_get_op(const char *buf){
    if(strcmp(buf, "+") is 0){
        return plus;
    }
    elif(strcmp(buf, "-") is 0){
        return minus;
    }
    elif(strcmp(buf, "*") is 0){
        return multiply;
    }
    elif(strcmp(buf, "/") is 0){
        return divide;
    }
    elif(strcmp(buf, "%") is 0){
        return modulus;
    }

}