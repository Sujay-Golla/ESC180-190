#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "LL.h"

void create_node(node **p_n, int data)
{
    *p_n = (node*)malloc(sizeof(node));
    (*p_n)->next = NULL;
    (*p_n)->data = data;
}

// created a linked list that looks like data[0]->data[1]->data[2]->...->data[size-1]
void create_LL_from_data(LL **p_LL, int *data_arr, int size)
{
    (*p_LL) = (LL*)malloc(sizeof(LL));
    (*p_LL)->size = 0;
    node *cur = NULL;
    for(int i = 0; i < size; i++){
        node *n;
        create_node(&n, data_arr[i]); // n is a pointer to a node with data = data[i], next = NULL
        if(cur == NULL){
            (*p_LL)->head = n;
        }
        else{
            cur->next = n;
        }
        cur = n;
        (*p_LL)->size++;
    }
}


void LL_append(LL *my_list, int new_elem)
{
    node *cur = my_list->head;
    while(cur->next != NULL){
        cur = cur->next;
    }
    node *n;
    create_node(&n, new_elem);
    cur->next = n;
    my_list->size++;
}

void LL_insert(LL *my_list, int new_elem, int index)
{    
    node *new;
    create_node(&new, new_elem);
    
    if(index == 0){
        new->next = my_list->head;
        my_list->head = new;
        return;
    }
    
    node *cur = my_list->head;
    for (int i = 0; i < index-1; i++){
        cur = cur->next;
    }
    new->next = cur->next;
    cur->next = new;
    my_list->size++;
}

void LL_delete(LL *my_list, int index)
{
    node *cur = my_list->head;
    for (int i = 0; i < index-1; i++){
        cur = cur->next;
    }
    node *temp = cur->next;
    if ((cur->next)->next != NULL){
        cur->next = (cur->next)->next;
        free(temp);
    } else {
        cur->next = NULL;
        free(temp);
    }
    my_list->size--;
}

void LL_free_all(LL *my_list)
{
    node *cur = my_list->head;
    while (cur != NULL){
        node *temp = cur;
        cur = cur->next;
        free(temp);
    }
    free(my_list);
}


int LL_get_rec(LL *my_list, int index)
{
    return LL_get_rec_helper(my_list->head, index);
}

int LL_get_rec_helper(node *cur, int index)
{
    if (index == 0){
        return cur->data;
    }
    return LL_get_rec_helper(cur->next, index-1);
}