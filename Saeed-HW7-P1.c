/*
Sharif Saeed
ECE 340 Data Structures
HW 7 Part 1
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node_t;

typedef struct LinkedList {
    Node_t *head;
    Node_t *tail;
} LinkedList_t;

int main() {
    LinkedList_t *priorQue = (LinkedList_t*)malloc(sizeof(LinkedList_t));
    
    priorQue->head = NULL;
    priorQue->tail = NULL;
    return 0;
}


void Enqueue(LinkedList_t* priorQue, int val) {
    Node_t *newNode = (Node_t*)malloc(sizeof(Node_t));
    newNode->data = val;
    newNode->next = NULL;
    if (priorQue->head == NULL) {
        priorQue->head = newNode;
        priorQue->tail = newNode;
        return;
    }
    if (val > priorQue->head->data) {
        newNode->next = priorQue->head;
        priorQue->head = newNode;
        return;
    }
    Node_t *current = priorQue->head;
    while (current->next != NULL && current->next->data >= val) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
    if (newNode->next == NULL) {
        priorQue->tail = newNode;
    }
}

int Dequeue(LinkedList_t* priorQue) {
    if (priorQue->head == NULL) {
        return -1;
    }
    Node_t *temp = priorQue->head;
    int val = temp->data;
    priorQue->head = priorQue->head->next;
    if (priorQue->head == NULL) {
        priorQue->tail = NULL;
    }

    return val;
}

