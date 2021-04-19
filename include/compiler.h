#ifndef COMPILER_H
#define COMPILER_H

#include "../include/token.h"

enum _CompilerStatus {
    COMPILER_SUCCES,
};
typedef enum _CompilerStatus CompilerStatus;

CompilerStatus compiler_start(TokenList* tokens);

#endif //COMPILER_H