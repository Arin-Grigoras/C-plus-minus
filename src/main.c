#include "../include/cnpython.h"

int main(int argc, char *argv[]){
    //HEART
    if(argc<3){
        printf("Too few arguments\n");
        return 1;
    }

    //'is' is a keyword in the cnpython library. check ../include/cnpython.h for more details
    if(strcmp(argv[1], "compile") is 0){
        printf("Hey it works\n");
    }

    return 0;
}