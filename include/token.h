#ifndef TOKEN_H
#define TOKEN_H

#include <stdio.h>

enum _TokenType{
    INST,
    NUMBER
};

enum _TokenInst{
    push,
    add,
    hlt
};

typedef enum _TokenInst TokenInst;

struct _Token{
    int data;
    int type;
    int line;
};

typedef struct _Token Token;

Token *token_create(int type, int data, int line);
void token_destroy(Token *tok);

struct _TokenList{
    Token **data;
    int ptr;
    int size;
};
typedef struct _Tokenlist TokenList;

void token_list_create(TokenList *list, int size);
void token_list_add(TokenList *list, Token *tok);
Token *token_list_get(TokenList *list, int index);
void token_list_destroy(TokenList* list);

#endif //TOKEN_H