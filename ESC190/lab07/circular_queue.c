#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CircularQueue{
    int *data;
    int front;
    int rear;
    int size;
    int cur_size;
} CircularQueue;

void create_CircularQueue(CircularQueue **p_q, int size, int start)
{
    (*p_q) = (CircularQueue*)malloc(sizeof(CircularQueue));
    (*p_q)->data = (int*)malloc(sizeof(int)*size);
    (*p_q)->front = start;
    (*p_q)->rear = start;
    (*p_q)->size = size;
    (*p_q)->cur_size = 0;

    for (int i = 0; i < size; i++) {
        (*p_q)->data[i] = 0;
    }
}

void enqueue(CircularQueue *q, int new_elem)
{
    if (q->cur_size == q->size) {
        printf("Queue is full!\n");
        q->data = realloc(q->data, sizeof(int)*(q->size + 1));
        q->size++;
        if (q->rear < q->front) {
            for (int i = q->size - 1; i > q->rear; i--) {
                q->data[i] = q->data[i - 1];
            }
            q->front = q->front + 1;
        }
        q->rear = q->rear + 1;
        q->data[q->rear] = new_elem;
        q->cur_size++;
        return;
    }

    if (q->cur_size == 0) {
        q->data[q->rear] = new_elem;
    } else {
        q->rear = (q->rear + 1) % q->size;
        q->data[q->rear] = new_elem;
    }

    q->cur_size++;
}

int dequeue(CircularQueue *q)
{
    if (q->cur_size == 0) {
        printf("Queue is empty!\n");
        return -1;
    }

    int val = q->data[q->front];
    q->data[q->front] = 0;
    q->front = (q->front + 1) % q->size;
    q->cur_size--;

    return val;
}

void print_CircularQueue(CircularQueue *q)
{
    printf("Circular Queue: ");
    for (int j = 0; j < q->size; j++) {
        printf("%d ", q->data[j]);
    }
    printf("\n");
}

void main()
{
    CircularQueue *q;
    create_CircularQueue(&q, 5, 1);
    enqueue(q, 1);
    enqueue(q, 2);
    enqueue(q, 3);
    enqueue(q, 4);
    print_CircularQueue(q);
    enqueue(q, 5);
    printf("Dequeue: %d\n", dequeue(q));
    print_CircularQueue(q);
    enqueue(q, 6);
    print_CircularQueue(q);
    enqueue(q, 7);
    print_CircularQueue(q);
    free(q->data);
    free(q);
}