/*
Sharif Saeed
ECE 340 Data structures and systems
Project #3
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayList {
    int *array;
    int length;
    int allocationSize;
} ArrayList_t;

ArrayList_t* CreateAndInitPQueue() {
    ArrayList_t *pQue = (ArrayList_t*)malloc(sizeof(ArrayList_t));
    pQue->array = (int*)malloc(4 * sizeof(int));
    pQue->length = 0;
    pQue->allocationSize = 4;
    return pQue;
}

void Resize(ArrayList_t *pQue) {
    pQue->allocationSize *= 2;
    pQue->array = (int*)realloc(pQue->array, pQue->allocationSize * sizeof(int));
}

void HeapifyUp(ArrayList_t *pQue, int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (pQue->array[parent] >= pQue->array[index]) break;
        int temp = pQue->array[parent];
        pQue->array[parent] = pQue->array[index];
        pQue->array[index] = temp;
        index = parent;
    }
}

void Enqueue(ArrayList_t *pQue, int value) {
    if (pQue->length == pQue->allocationSize) {
        Resize(pQue);
    }
    pQue->array[pQue->length] = value;
    HeapifyUp(pQue, pQue->length);
    pQue->length++;
}

void HeapifyDown(ArrayList_t *pQue, int index) {
    while (2 * index + 1 < pQue->length) {
        int left = 2 * index + 1;
        int right = 2 * index + 2;
        int largest = index;
        if (left < pQue->length && pQue->array[left] > pQue->array[largest]) {
            largest = left;
        }
        if (right < pQue->length && pQue->array[right] > pQue->array[largest]) {
            largest = right;
        }
        if (largest == index) break;
        int temp = pQue->array[index];
        pQue->array[index] = pQue->array[largest];
        pQue->array[largest] = temp;
        index = largest;
    }
}

int Dequeue(ArrayList_t *pQue) {
    if (pQue->length == 0) return -1;
    int maxValue = pQue->array[0];
    pQue->array[0] = pQue->array[--pQue->length];
    HeapifyDown(pQue, 0);
    return maxValue;
}

int Peek(ArrayList_t *pQue) {
    return (pQue->length > 0) ? pQue->array[0] : -1;
}

int IsEmpty(ArrayList_t *pQue) {
    return pQue->length == 0;
}

int GetLength(ArrayList_t *pQue) {
    return pQue->length;
}

int GetHeight(ArrayList_t *pQue) {
    int height = 0, size = pQue->length;
    while (size > 1) {
        size /= 2;
        height++;
    }
    return height;
}

void PrintPQueue(ArrayList_t *pQue) {
    for (int i = 0; i < pQue->length; i++) {
        printf("%d ", pQue->array[i]);
    }
    printf("\n");
}























