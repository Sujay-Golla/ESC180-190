#include "intlist.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void create_list_from_data(IntList **p_IntList, int *data_arr, int size)
{
    *p_IntList = malloc(sizeof(IntList));
    (*p_IntList)->data = malloc(size * sizeof(int));
    memcpy((*p_IntList)->data, data_arr, size * sizeof(int));
    (*p_IntList)->size = size;
    (*p_IntList)->capacity = size;
}

void list_append(IntList *list, int new_elem)
{
    if (list->size == list->capacity){
        //realloc_memory1(list);
        realloc_memory2(list);
    }
    list->data[list->size++] = new_elem;
}

// memmove is appropriate but not memcpy as memory regions can overlap and memcpy would break down whereas memmove would work
void list_insert(IntList *list, int new_elem, int index)
{
    if (list->size == list->capacity){
        //realloc_memory1(list);
        realloc_memory2(list);
    }
    memmove(&list->data[index + 1], &list->data[index], (list->size - index) * sizeof(int));
    list->data[index] = new_elem;
    list->size++;
}

void list_delete(IntList *list, int index)
{
    memmove(&list->data[index], &list->data[index + 1], (list->size - index - 1) * sizeof(int));
    list->size--;
    if (list->size * 2 <= list->capacity){
        realloc_memory_rem(list);
    }
}

void list_destroy(IntList *list)
{
    free(list->data);
    free(list);
}

int list_get(IntList *list, int index)
{
    return list->data[index];
}