#include <stdlib.h>
#include <string.h>
#include <limits.h>
#ifndef VECTOR_H
#define VECTOR_H
#define KOEF 2
typedef struct Vector {
    int Size;
    int Count;
    int *data;
} Vector;
Vector *CreateVector();
void freeVector(Vector *v);
int CheckEmptyVector(Vector *v);
void PushVector(Vector *v, int elem);
int TopVector(Vector *v);
int PopVector(Vector *v);
#endif 
