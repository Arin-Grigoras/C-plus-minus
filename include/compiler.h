#ifndef COMPILER_H
#define COMPILER_H

#include "./C+-.h"
#include "./token.h"

enum _CompilerStatus {
    COMPILER_SUCCESS,
    COMPILER_FAILURE,
};
typedef enum _CompilerStatus CompilerStatus;


void check_instruction(const int inst_code, const int type);
int check_push(const int inst_code, const int type1);
int check_add(const int inst_code, const int type);
int check_ext(const int inst_code, const int type);
int check_num(const int inst_code, const int type);
FILE *create_file();
CompilerStatus compiler_start(TokenList *list, const char *path);


#endif //COMPILER_H
