/*
Sharif Saeed
ECE 340 data structures
HW 5 Part 1 (Dynamic Array)
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct ArrayStack {
    int *array;
    int size;
    int capacity;
} ArrayStack_t;

ArrayStack_t* CreateStack() {
    ArrayStack_t* stk = (ArrayStack_t*)malloc(sizeof(ArrayStack_t));
    stk->array = (int*)malloc(4 * sizeof(int));
    stk->size = 0;
    stk->capacity = 4;
    return stk;
}

void Push(ArrayStack_t* stk, int value) {
    if (stk->size == stk->capacity) {
        resize(stk);
    }
    stk->array[stk->size++] = value;
}

int Pop(ArrayStack_t* stk) {
    if (stk->size == 0) {
        printf("Empty\n");
        return -1;
    }
    int value = stk->array{stk->size - 1};
    stk->size--;
    return value;
}

int main() {
    ArrayStack_t* myStack = CreateStack();
    return 0;
}
