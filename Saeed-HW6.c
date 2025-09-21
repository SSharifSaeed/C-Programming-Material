/*
Sharif Saeed
ECE 340 Data structures
HW 6
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct QueueArray {
    int *array;
    int size;
    int capacity;
    int front, back;
} QueueArray_t;

int main() {
    QueueArray_t* queue = (QueueArray_t*)malloc(sizeof(QueueArray_t));
    queue->array = (int*)malloc(8 * sizeof(int));
    queue->size = 0;
    queue->capacity = 8;
    queue->front = 0;
    queue->back = 0;
    
    return 0;
}

void Enqueue(QueueArray_t* que, int val) {
    if (que->size == que->capacity) {
        Resize(que);
        return;
    }

    que->array[que->back] = val;
    que->back = (que->back + 1) % que->capacity;
    que->size++;
}

int Dequeue(QueueArray_t* que) {
    if (que->size == 0) {
        printf("Queue is empty.\n");
        return -1;
    }

    int val = que->array[que->front];
    que->front = (que->front + 1) % que->capacity;
    que->size--;

    return val;
}