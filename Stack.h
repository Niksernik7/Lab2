#include <stdlib.h>
#ifndef LAB2_STACK_H
#define LAB2_STACK_H
typedef struct Stack {
    void *data;
} Stack;
Stack *newStackL();
int CheckEmpty(Stack *s);
void Push(Stack *s, char elem);
int Top(Stack *s);
char Pop(Stack *s);
void FreeStack(Stack *s);
#endif
