#ifndef COMPILER_H
#define COMPILER_H

#include "./C+-.h"
#include "./token.h"

enum _CompilerStatus {
    COMPILER_SUCCES,
    COMPILER_FAILURE,
};
typedef enum _CompilerStatus CompilerStatus;


char* check_instruction(const int inst_code, const int line);
int check_push(const int inst_code, const int line);
int check_add(const int inst_code, const int line);
int check_ext(const int inst_code, const int line);
CompilerStatus compiler_start(TokenList *list, const char *path);


#endif //COMPILER_H
