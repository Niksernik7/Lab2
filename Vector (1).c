#include "Vector.h"
Vector *CreateVector()
{
    Vector *res = (Vector *) calloc(1, sizeof(Vector));
    res->Size = 0;
    return res;
}
void freeVector(Vector *v)
{
    free(v->data);
    free(v);
}
int CheckEmptyVector(Vector *v)
{
    return !v->Count;
}
void PushVector(Vector *v, int elem)
{
    if (v->Size++ == v->Count) {
        v->Size *= KOEF;
        int* buf = (int *) malloc(sizeof(int) * v->Size);
        memcpy(buf, v->data, sizeof(int) * v->Count);
        free(v->data);
        v->data = buf;
    }
    v->data[v->Count] = elem;
    v->Count++;
}
int TopVector(Vector *v)
{
    if (v == NULL || v->Count < 0)
        return CHAR_MAX + 1;
    if (v->Count == 0)
        return -1;
    return v->data[v->Count - 1];
}
int PopVector(Vector *v)
{
    if (v == NULL || v->Count <= 0)
        return CHAR_MAX + 1;
    int res = v->data[v->Count - 1];
    v->Count--;
    if (v->Count < v->Size / KOEF) {
        v->Size /= KOEF;
        int* buf = (int *) malloc(sizeof(int) * v->Size);
        memcpy(buf, v->data, sizeof(int) * v->Count);
        free(v->data);
        v->data = buf;
    }
    return res;
}