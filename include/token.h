#ifndef TOKEN_H
#define TOKEN_H

#include "./C+-.h"

enum _TokenType{
    INST,
    TYPE,
    COMMENT,
    NUMBER
};

enum _TokenInst{
    PUSH,
    ADD,
    EXT,
    RETURN,
    IF,
    ELIF,
    WHILE,
    FOR,
    STRUCT,
    INCLUDE,
    DEFINE,
    BREAK,
    CONST,
    CONTINUE,
    TYPEDEF,
    VOID,
    INT,
    FLOAT,
    LONG,
    CHAR,
    STRING,
    DOUBLE,
    SHORT,
    BOOL,
    TRUE,
    FALSE,
    SIGNED,
    UNSIGNED,
    DEFAULT,
    OR,
    AND,
    NOT,
    ISNT,
};

typedef enum _TokenInst TokenInst;

enum _TokenOP{
    plus,
    minus,
    multiply,
    divide,
    modulus,
};
typedef enum _TokenOP TokenOP;

typedef enum _TokenTypes TokenTypes;


//#define comment 10


struct _Token{
    int data;
    int type;
    int line;

};
typedef struct _Token Token;

Token* token_create(int type, int data, int line);
void token_destroy(Token* tok);

struct _TokenList{
    Token** data;
    int ptr;
    int size;
};
typedef struct _TokenList TokenList;

void token_list_create(TokenList* list, int size);
void token_list_add(TokenList* list, Token* tok);
Token* token_list_get(TokenList* list, int index);
void token_list_destroy(TokenList* list);

#endif //TOKEN_H
