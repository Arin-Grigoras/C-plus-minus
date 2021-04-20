#ifndef BYTEBUFFER_H
#define BYTEBUFFER_H


#include "./C+-.h"

struct _ByteBuffer {
    uint8_t* buffer;
    int ptr;
    int size;
};
typedef struct _ByteBuffer ByteBuffer;


#endif //BYTEBUFFER_H