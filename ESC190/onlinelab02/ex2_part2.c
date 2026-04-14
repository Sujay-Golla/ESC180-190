/** 
 * Part 2: C Min-Priority Queue
 * 
 * Now, you will implement a min-priority queue in C. 
 * It is the same as the one you implemented in Python, 
 * but will maintain the minimum element at the top of the queue.
 * 
 * The key value stored will also be restricted to non-negative integers.
 */

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int size;
    int capacity;
} MinHeap;

MinHeap* createHeap() {
    /* 
    TODO: Implement createHeap function
    Initialize the heap with a default capacity of 3.
    */
    int cap = 3;
    MinHeap *h = NULL;
    h = (MinHeap *)malloc(sizeof(MinHeap));
    h->data = (int *)malloc(cap * sizeof(int));
    h->size = 0;
    h->capacity = cap;
    return h;
}

void insert(MinHeap *h, int key) {
    /*
    TODO: Implement insert function
    If the queue is full, double the capacity 
    of the queue as a heuristic using realloc.
    */
   if (h->size == h->capacity) {
        h->capacity *= 2;
        h->data = (int *)realloc(h->data, h->capacity * sizeof(int));
    }
    if (h->size == 0) {
        h->data[0] = key;
        h->size++;
        return;
    }
    for (int i = 0; i < h->size; i++) {
        if (h->data[i] > key) {
            for (int j = h->size; j > i; j--) {
                h->data[j] = h->data[j - 1];
            }
            h->data[i] = key;
            h->size++;
            return;
        }
    }
    h->data[h->size] = key;
    h->size++;
}

int pop(MinHeap *h) {
    /* 
    TODO: Implement pop function 
    If the queue is empty, return -1.
    */
    if (h->size > 0) {
        int min = h->data[0];
        for (int i = 1; i < h->size; i++) {
            h->data[i - 1] = h->data[i];
        }
        h->size--;
        return min;
    }
   return -1;
}

int main() {
    // You can modify this main function to test your implementation
    MinHeap *h = createHeap();

    insert(h, 27);
    insert(h, 89);
    insert(h, 29);
    insert(h, 13);
    insert(h, 83);
    insert(h, 48);
    insert(h, 9);
    insert(h, 50);
    insert(h, 2);
    insert(h, 26);

    for (int i = 0; i < 11; i++) {
        printf("%d\n", pop(h));
    }
    
    free(h->data);
    free(h);
}