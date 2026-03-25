#include "intlist.h"
#include <stdlib.h>
#include <stdio.h>

int main()
{
    IntList *list;
    int data[] = {1, 2, 3, 4, 5};
    create_list_from_data(&list, data, 5);

    list_append(list, 6);
    list_insert(list, 0, 0);
    list_delete(list, 3);

    for (int i = 0; i < list->size; i++) {
        printf("%d ", list_get(list, i));
    }
    printf("\n");

    list_destroy(list);
    return 0;
}