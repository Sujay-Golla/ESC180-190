#include <stdio.h>
#include <stddef.h>
#include "LL.h"

int main()
{
    int data_arr[] = {1, 2, 3, 4, 5};
    LL *my_list;
    create_LL_from_data(&my_list, data_arr, 5);
    LL_append(my_list, 6);
    LL_insert(my_list, 67, 2);
    LL_delete(my_list, 3);
    printf("At index 4: %d\n", LL_get_rec(my_list, 4));
    node *cur = my_list->head;
    while(cur != NULL){
        printf("%d\n", cur->data);
        cur = cur->next;
    }
    LL_free_all(my_list);
    return 0;
}