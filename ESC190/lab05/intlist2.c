#include "intlist.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void realloc_memory2(IntList *list){
    list->capacity++;
    list->data = (int *)realloc(list->data, sizeof(int) * list->capacity);
}

void realloc_memory_rem(IntList *list)
{
    list->capacity = list->capacity / 2;
    list->data = (int *)realloc(list->data, sizeof(int) * list->capacity);
}