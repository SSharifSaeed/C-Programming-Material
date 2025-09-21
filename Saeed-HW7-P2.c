/*
Sharif Saeed
ECE 340 Data Structures
HW 7 Part 2
*/
#include <stdio.h>
#include <stdlib.h>

void Enqueue(LinkedList_t* priorQue, int val) {
    Node_t *newNode = (Node_t*)malloc(sizeof(Node_t));
    newNode->data = val;
    newNode->next = NULL;

    if (priorQue->head == NULL) {
        priorQue->head = newNode;
        priorQue->tail = newNode;
    } else {
        priorQue->tail->next = newNode;
        priorQue->tail = newNode;
    }
}

int Dequeue(LinkedList_t* priorQue) {
    if (priorQue->head == NULL) {
        return -1;
    }
    Node_t *current = priorQue->head;
    Node_t *prev = NULL;
    Node_t *maxPrev = NULL;
    Node_t *maxNode = priorQue->head;
    int maxVal = current->data;
    while (current != NULL) {
        if (current->data > maxVal) {
            maxVal = current->data;
            maxNode = current;
            maxPrev = prev;
        }
        prev = current;
        current = current->next;
    }

    if (maxPrev == NULL) {
        priorQue->head = priorQue->head->next;
    } else {
        maxPrev->next = maxNode->next;
    }
    if (maxNode == priorQue->tail) {
        priorQue->tail = maxPrev;
    }
    return maxVal;
}