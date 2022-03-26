#include "List.h"

int CheckEmptyList(List *list)
{
    return !list->Size;
}

List *list_new() {
    return (List *) calloc(1, sizeof(List));
}

void list_delete(List *list) {
    Item *ptr = list->head, *ptr_prev;
    while (ptr) {
        ptr_prev = ptr;
        ptr = ptr->next;
        free(ptr_prev);
    }
    free(list);
}

int list_push(List *list, int data) {
    Item *new = (Item *) malloc(sizeof(Item));
    if(!new) {
        return -1;
    }
    new->data = data;
    new->next = list->head;
    list->head = new;
    list->Size++;
    return 0;
}

int list_pop(List *list, int *output) {
    if(!list->head) {
        return -1;
    }

    *output = list->head->data;
    Item *head = list->head;
    list->head = head->next;
    free(head);
    list->Size--;
    return 0;
}

int list_top(List *list) {
    if(!list->head) {
        return -1;
    }
    return list->head->data;
}

void list_print(const List *stuck) {
    Item *ptr = stuck->head;
    while (ptr) {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}

