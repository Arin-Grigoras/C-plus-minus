#ifndef TOKEN_H
#define TOKEN_H

#include "./C+-.h"

enum _TokenType{
    INST,
    OP,
    TYPE,
    COMMENT,
    NUMBER
};

enum _TokenInst{
    push,
    add,
    ext
};

typedef enum _TokenInst TokenInst;

/*enum _TokenOP{

};
Tried but failed :(
*/

enum _TokenTypes{
    inte,
    chr,
    string,
    lng,
    dbl,
    flt,
};

typedef enum _TokenTypes TokenTypes;


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