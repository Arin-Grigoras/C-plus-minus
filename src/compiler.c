#include "../include/C+-.h"



int check_push(const int inst_code, const int type){
    if(inst_code == PUSH && type == 0){
        return PUSH;
    }
    return -1;
}



int check_add(const int inst_code, const int type){
    if(inst_code == ADD && type == 0){
        return ADD;
    }
    return -1;
}



int check_ext(const int inst_code, const int type){
    if(inst_code == EXT && type == 0){
        return EXT;
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
    int number = check_num(inst_code, type);

    if(number != -1){
        fprintf(fptr, " %d\n", number);
    }

    
    
    if(check_push(inst_code, type) == PUSH){
        srand(time(NULL));
        fprintf(fptr, "\tmov %s,", registers[rand() % 2]);
    }
    else if(check_add(inst_code, type) == ADD){
        fprintf(fptr, "\tadd %s, %s\n", registers[0], registers[1]);
        
        //basically to print the result
    }
    else if(check_ext(inst_code, type) == EXT){
        fprintf(fptr, "\tmov eax, 1\n\tint 0x80\n");
    }
    //fprintf(fptr, "");
}




CompilerStatus compiler_start(TokenList *list, const char *path){
    FILE *fptr = fopen(path, "wb");
    
    if(!fptr){
        perror("FileOpenError");
        return FileOpenError;
    }

    FILE *file;
    
    file = fopen("./a.asm", "a+");

    if(!file){
        perror("FileOpenError");
        exit(1);
       //return FileOpenError;
    }

    //Intel syntax btw

    //fprintf(fptr, "\nsection .text\n"); doesnt work for some reason

    fprintf(file, "global _start");

    //fprintf(fptr, "SECTION .text");


    fprintf(file, "\n\n_start:\n");


    for(uint32_t i = 0; i < list->ptr; i++){
            Token* t = token_list_get(*&list, i);
            get_instruction(t->data, t->type, file);
            
    }

    fclose(fptr);
    fclose(file);

    read_ascii_file("./a.asm");

    printf("\n\nDone...\n\n");
    printf("\nRun %s to run the program\n", path);


    return COMPILER_SUCCESS;
}
