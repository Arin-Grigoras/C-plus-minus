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
    if(type == NUMBER){
        return inst_code;
    }
    return -1;
}



void get_instruction(const int inst_code, const int type, FILE *fptr){
    char *registers[] = {"eax", "ebx"};
    uint32_t number = check_num(inst_code, type);

    if(number != -1){
        fprintf(fptr, " %d", number);
    }
    
    srand(time(NULL));
    int random = rand() % 2;


    
    if(check_push(inst_code, type) == push){
        fprintf(fptr, "\tmov %s, \n", registers[random]);
    }
    else if(check_add(inst_code, type) == add){
        fprintf(fptr, "\tadd %s, %s\n", registers[0], registers[1]);
    }
    else if(check_ext(inst_code, type) == ext){
        fprintf(fptr, "\tmov eax, 1\n\tint 0x80\n");
    }

    

    fclose(fptr);


    //fprintf(fptr, "");
}



FILE *create_file(){
    FILE *fptr;
    
    fptr = fopen("./a.asm", "a+");

    if(!fptr){
        perror("FileOpenError");
        exit(1);
       //return FileOpenError;
    }

    //Intel syntax btw

    fprintf(fptr, "global _start");

    //fprintf(fptr, "SECTION .text");


    fprintf(fptr, "\n\n_start:\n");

    return fptr;
}



CompilerStatus compiler_start(TokenList *list, const char *path){
    FILE *fptr = fopen(path, "wb");
    
    if(!fptr){
        perror("FileOpenError");
        return FileOpenError;
    }

    FILE *file = create_file();


    for(uint32_t i = 0; i < list->ptr; i++){
            Token* t = token_list_get(*&list, i);
            get_instruction(t->data, t->type, file);
            
    }

    fclose(fptr);

    printf("\n\nDone...\n\n");
    printf("\nRun %s to run the program\n", path);


    return COMPILER_SUCCESS;
}
