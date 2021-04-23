#ifndef PARSER_H
#define PARSER_H

#include "./C+-.h"
#include "./token.h"


enum _ParserStatus {
    PARSER_SUCCESS,
    PARSER_SYNTAX_ERROR
};
typedef enum _ParserStatus ParserStatus;


ParserStatus parser_start(TokenList* list, const char* source);
uint32_t parser_get_number(const char* buf, const int line);
TokenInst parser_get_inst(const char* buf);
int parser_get_op(const char* buf);
int parser_get_com(const char *buf);

#endif //PARSER_H