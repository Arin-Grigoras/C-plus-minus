#include "../include/C+-.h"

int check_push(const int inst_code, const int type, const int line){
    if(inst_code == push && type == 0){
        return push;
    }
    return -1;
}

int check_add(const int inst_code, const int type, const int line){
    if(inst_code == add && type == 0){
        return add;
    }
    return -1;
}


int check_ext(const int inst_code, const int type, const int line){
    if(inst_code == ext && type == 0){
        return ext;
    }
    return -1;
}


char* get_instruction(const int inst_code, const int type, const int line){
    if(check_push(inst_code, type, line) == push){
        return "push";
    }
    else if(check_add(inst_code, type, line) == add){
        return "add";
    }
    else if(check_ext(inst_code, type, line) == ext){
        return "ext";
    }

    else{
        return "number";
    }

}

CompilerStatus compiler_start(TokenList *list, const char *path){
    FILE *fptr = fopen(path, "wb");

    if(!fptr){
        printf("\nFileOpenError: 'a.out'\n");
        return FileOpenError;
    }

    for(uint32_t i = 0; i < list->ptr; i++){
            Token* t = token_list_get(*&list, i);
            
            printf("%d %s\n", t->data, get_instruction(t->data, t->type, t->line));
            //printf("\n");
            
    }

    fclose(fptr);

    printf("\n\nDone...\n\n");
    printf("\nRun %s to run the program\n", path);


    return COMPILER_SUCCES;
}


