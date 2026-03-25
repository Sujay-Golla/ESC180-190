#include "intlist.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void realloc_memory1(IntList *list){
    list->capacity = list->capacity * 2;
    list->data = (int *)realloc(list->data, sizeof(int) * list->capacity);
}