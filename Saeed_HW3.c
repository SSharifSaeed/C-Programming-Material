/*
Sharif Saeed
ECE 340 Data structures
HW 3
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;   
    int size;      
    int capacity;  
} ArrayList_t;

int main() {
    ArrayList_t list;
    int initialCapacity = 4;

    list.array = (int*)malloc(initialCapacity * sizeof(int));
    if (list.array == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    for (int i = 0; i < initialCapacity; i++) {
        list.array[i] = 0;
    }

    list.size = 0; 
    list.capacity = initialCapacity;

    void Append(ArrayList_t *list, int newItem) {
        if (list->size < list->capacity) {
            list->array[list->size] = newItem;
            list->size++;
        } else {
            printf("Array is full. Cannot append new item.\n");
        }
    }

    int Search(ArrayList_t *list, int item) {
        for (int i = 0; i < list->size; i++) {
            if (list->array[i] == item) {
                return i;
            }
        }
        return -1;
    }


    return 0;
}