#include "Stack.h"
#include "List.h"
#include "Vector.h"
#ifdef SList
Stack *newStackL() {
    Stack *res = (Stack *) calloc(1, sizeof(Stack));
    res->data = (List *) list_new();
    return res;
}
int CheckEmpty(Stack *s)
{
    return CheckEmptyList(s->data);
}
void Push(Stack *s, char elem)
{
    list_push(s->data, elem);
}
int Top(Stack *s)
{
    return list_top(s->data);
}
char Pop(Stack *s)
{
    int res = 0;
    list_pop(s->data, &res);
    return res;
}
void FreeStack(Stack *s)
{
    list_delete(s->data);
    free(s);
}
#endif
#ifdef SVector
Stack *newStackL() {
    Stack *res = (Stack *) calloc(1, sizeof(Stack));
    res->data = CreateVector();
    return res;
}
int CheckEmpty(Stack *s)
{
    return CheckEmptyVector(s->data);
}
void Push(Stack *s, char elem)
{
    PushVector(s->data, elem);
}
int Top(Stack *s)
{
    return TopVector(s->data);
}
char Pop(Stack *s)
{
    int res = PopVector(s->data);
    return res;
}
void FreeStack(Stack *s) {
    freeVector(s->data);
    free(s);
}
#endif
