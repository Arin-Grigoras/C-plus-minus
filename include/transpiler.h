#ifndef TRANSPILER_H
#define TRANSPILER_H

#include "./token.h"

enum _TranspilerStatus {
    TRANSPILER_SUCCES,
};
typedef enum _TranspilerStatus TranspilerStatus;

TranspilerStatus compiler_start(TokenList* tokens);

#endif //TRANSPILER_H