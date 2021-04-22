#include "../include/C+-.h"

CompilerStatus compiler_start(TokenList *list){
    FILE *fptr = fopen("./a.out", "wb");

    if(not fptr){
        printf("\nFileOpenError: 'a.out'\n");
        return FileOpenError;
    }

    fprintf(fptr, "test");

    fclose(fptr);

    printf("Done...\n");


    return COMPILER_SUCCES;
}
