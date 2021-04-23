#include "../include/C+-.h"



int check_push(const int inst_code, const int type){
    if(inst_code == push && type == 0){
        return push;
    }
    return -1;
}



int check_add(const int inst_code, const int type){
    if(inst_code == add && type == 0){
        return add;
    }
    return -1;
}



int check_ext(const int inst_code, const int type){
    if(inst_code == ext && type == 0){
        return ext;
    }
    return -1;
}



int check_num(const int inst_code, const int type){
    if(type == 4){
        return NUMBER;
    }
    return -1;
}



void get_instruction(const int inst_code, const int type){
    char *registers[] = {"eax", "ebx"};
    FILE *fptr;
    
    fptr = fopen("./a.asm", "w+");

    if(!fptr){
        printf("Couldn't create assembly file");
        exit(1);
       //return FileOpenError;
    }

    //Intel syntax btw

    fprintf(fptr, "global _start");

    //fprintf(fptr, "SECTION .text");


    fprintf(fptr, "\n\n_start:\n");

    
    srand(time(NULL));
    int random = rand() % 2;


    if(check_push(inst_code, type) == push){
        fprintf(fptr, "\tmov %s, %d\n", registers[random], inst_code);
    }
    else if(check_add(inst_code, type) == add){
        fprintf(fptr, "\tadd %s, %s\n", registers[random], registers[random]);
    }
    else if(check_ext(inst_code, type) == ext){
        fprintf(fptr, "\tmov eax, 1\n\tint 0x80\n");
    }

    else if(check_num(inst_code, type) == NUMBER){
    }

    fclose(fptr);


    //fprintf(fptr, "");

    

}



CompilerStatus compiler_start(TokenList *list, const char *path){
    FILE *fptr = fopen(path, "wb");

    if(!fptr){
        printf("\nFileOpenError: 'a.out'\n");
        return FileOpenError;
    }

    for(uint32_t i = 0; i < list->ptr; i++){
            Token* t = token_list_get(*&list, i);
            
            get_instruction(t->data, t->type);
            
    }

    fclose(fptr);

    printf("\n\nDone...\n\n");
    printf("\nRun %s to run the program\n", path);


    return COMPILER_SUCCESS;
}
