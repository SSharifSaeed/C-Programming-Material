/*
Sharif Saeed
ECE 340 Data Structures
HW 5 Part 2 (Linked List)
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node_t;

typedef struct LinkedList {
    Node_t* head;
    Node_t* tail;
} LinkedList_t;

LinkedList_t* CreateStack() {
    LinkedList_t* stk = (LinkedList_t*)malloc(sizeof(LinkedList_t));
    stk->head = NULL;
    stk->tail = NULL;
    return stk;
}

void Push(LinkedList_t* stk, Node_t* newNode) {
    newNode->next = stk->head;
    stk->head = newNode;
    if (stk->tail == NULL) {
        stk->tail = newNode;
    }
}

int Pop(LinkedList_t* stk) {
    if (stk->head == NULL) {
        printf("Empty\n");
        return -1;
    }
    Node_t* temp = stk->head;
    int value = temp->data;
    stk->head = stk->head->next;
    free(temp);
    return value;
}

int main() {
    LinkedList_t* myStack = CreateStack();
    Node_t* node1 = (Node_t*)malloc(sizeof(Node_t));
    node1->data = 1;
    node1->next = NULL;
    return 0;
}


