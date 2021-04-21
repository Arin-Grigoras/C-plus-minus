#ifndef COMPILER_H
#define COMPILER_H

#include "./C+-.h"
#include "./token.h"

enum _CompilerStatus {
    COMPILER_SUCCES,
    COMPILER_FAILURE,
};
typedef enum _CompilerStatus CompilerStatus;

CompilerStatus compiler_start(TokenList* tokens);

#endif //COMPILER_H