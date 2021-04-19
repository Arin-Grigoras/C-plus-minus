#ifndef PARSER_H
#define PARSER_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <limits.h>

#include "./token.h"

enum _ParserStatus{
    PARSER_SUCCES,
    PARSER_SYNTAX_ERROR
};
typedef enum _ParserStatus ParserStatus;

ParserStatus parser_start(TokenList *list, const char *source);
uint32_t parser_get_number(const char *buffer);
TokenList parser_get_inst(const char *buffer);

#endif //PARSER_H