#include "../include/C+-.h"

int check_push(const int inst_code, const int line){
    if(inst_code == 0){
        return push;
    }
    return UINT32_MAX;
}

int check_add(const int inst_code, const int line){
    if(inst_code == 1){
        return add;
    }
    return UINT32_MAX;
}


int check_ext(const int inst_code, const int line){
    if(inst_code == 2){
        return ext;
    }
    return UINT32_MAX;
}


char* get_instruction(const int inst_code, const int line){
    if(check_push(inst_code, line)){
        return "push";
    }
    elif(check_add(inst_code, line)){
        return "add";
    }
    elif(check_ext(inst_code, line)){
        return "ext";
    }

    else{
        return "unknown";
    }

}

CompilerStatus compiler_start(TokenList *list, const char *path){
    FILE *fptr = fopen(path, "wb");

    if(not fptr){
        printf("\nFileOpenError: 'a.out'\n");
        return FileOpenError;
    }

    for(uint32_t i = 0; i < list->ptr; i++){
        Token *t = token_list_get(*&list, i);
        printf("%d\n", t->data);
    }

    for(uint32_t i = 0; i < list->ptr; i++){
            Token* t = token_list_get(*&list, i);
            
            printf("%s \n", get_instruction(t->data, t->line));
            //printf("\n");
            
    }

    fclose(fptr);

    printf("Done...\n");
    printf("Run %s to run the program\n", path);


    return COMPILER_SUCCES;
}


