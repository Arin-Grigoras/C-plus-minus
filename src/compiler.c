#include "../include/C+-.h"

CompilerStatus compiler_start(TokenList *list, const char *path){
    FILE *fptr = fopen(path, "wb");

    if(not fptr){
        printf("\nFileOpenError: 'a.out'\n");
        return FileOpenError;
    }


    /*for(uint32_t i = 0; i < list->ptr; i++){
            printf("%d\n", (*list->data)->data);
    }*/

    fclose(fptr);

    printf("Done...\n");
    printf("Run %s to run the program\n", path);


    return COMPILER_SUCCES;
}
