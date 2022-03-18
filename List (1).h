#ifndef LIST_H
#define LIST_H

#include <stdlib.h>
#include <stdio.h>
typedef struct Item {
    int data;
    struct Item *next;
} Item;
typedef struct List {
    Item *head;
    int Size;
} List;
List *list_new();

void list_delete(List *list);

int list_push(List *list, int data);

int list_pop(List *list, int *output);

int list_top(List *list);

void list_print(const List *stuck);
#endif
