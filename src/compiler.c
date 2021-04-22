#include "../include/C+-.h"

CompilerStatus compiler_start(TokenList *list, const char *path){
    FILE *fptr = fopen(path, "wb");

    if(not fptr){
        printf("\nFileOpenError: 'a.out'\n");
        return FileOpenError;
    }


    for(uint32_t i = 0; i < list->ptr; i++){
            Token* t = token_list_get(*&list, i);
            printf("%d\n", t->line);
    }

    fclose(fptr);

    printf("Done...\n");
    printf("Run %s to run the program\n", path);


    return COMPILER_SUCCES;
}
