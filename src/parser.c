#include "../include/C+-.h"



ParserStatus parser_start(TokenList* list, const char* source){
    char lex[256];
    int lexi = 0;
    int i = 0;
    int line = 1;
    
    while(true){
        //memset(lex, '\0', 256);

        while(source[i] != ' ' && source[i] != '\n' && source[i] != '\0' && source[i] != '\t' && source[i] != '\r' && source[i] != '\v' && source[i] != '\f'){
            lex[lexi++] = source[i++];
        }
        
        lex[lexi] = '\0';


        if(lex[0] == '#'){
            int num = parser_get_number(lex, line);
            //printf("NUMBER: %d\n", num);
            token_list_add(list, token_create(NUMBER, num, line));
        }

        //if its an operator
        else if(lex[0] == '+' || lex[0] == '-' || lex[0] == '*' || lex[0] == '/' || lex[0] == '%'){
            //then do some operator stuff(i literally have no idea what im doing please help)
            int op = parser_get_op(lex);
            //printf("%d\n", op);
            token_list_add(list, token_create(INST, op, line));
        }

        else if(lex[0] == '@'){
            /*for(int i = 0; lex[i] != "\n"; i++){
                int com = parser_get_com(lex);
            }*/

            //here im trying to implement a comment
        }
        
        else{
            int inst = parser_get_inst(lex);
            if(inst >= 0){
                //printf("INST: %s\n", lex);
                token_list_add(list, token_create(INST, inst, line));
            }

            //Tried to make it so if it's just an empty character it ignores it
            /*else if(lex is NULL){
                continue;
            }*/

            else{
                error(SyntaxError, lex, line);
                return PARSER_SYNTAX_ERROR;
            }
        }

        if(source[i] == '\n'){
            line++;
        }
        else if(source[i] == '\0'){
            break;
        }

        lexi = 0;
        i++;

    }

    return PARSER_SUCCESS;

}


uint32_t parser_get_number(const char* buf, const int line){
    long num = atoi(&buf[1]);

    //printf("%ld", num);

    if(num < UINT32_MAX){
        return num;
    }

    perror("OverFlow error");
    return 0;
}


TokenInst parser_get_inst(const char* buf){
    if(strcmp(buf, "push") == 0){
        return PUSH;
    }
    if(strcmp(buf, "add") == 0){
        return ADD;
    }
    if(strcmp(buf, "ext") == 0){
        return EXT;
    }
    else{
        return (TokenInst)-1;
    }
}


int parser_get_op(const char *buf){
    if(strcmp(buf, "+") == 0){
        return plus;
    }
    else if(strcmp(buf, "-") == 0){
        return minus;
    }
    else if(strcmp(buf, "*") == 0){
        return multiply;
    }
    else if(strcmp(buf, "/") == 0){
        return divide;
    }
    else if(strcmp(buf, "%") == 0){
        return modulus;
    }

}


int parser_get_com(const char *buf){
    return COMMENT;
}