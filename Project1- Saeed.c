/*
Sharif Saeed
ECE 340 Data structures and systems
Project 1
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

LinkedList_t* CreateList() {
    LinkedList_t* list = (LinkedList_t*)malloc(sizeof(LinkedList_t));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

Node_t* CreateAndInitNode(int value) {
    Node_t* node = (Node_t*)malloc(sizeof(Node_t));
    node->data = value;
    node->next = NULL;
    return node;
}

Node_t* FindValue(LinkedList_t *list, int value) {
    Node_t* current = list->head;
    while (current) {
        if (current->data == value) return current;
        current = current->next;
    }
    printf("Value not found.\n");
    return NULL;
}

Node_t* FindIndex(LinkedList_t *list, int index) {
    if (index < 0) {
        printf("Invalid index.\n");
        return NULL;
    }
    Node_t* current = list->head;
    int count = 0;
    while (current) {
        if (count == index) return current;
        current = current->next;
        count++;
    }
    printf("Index not found.\n");
    return NULL;
}

void InsertAfter(LinkedList_t *list, Node_t *newNode, Node_t *currNode) {
    if (currNode == NULL) {
        newNode->next = list->head;
        list->head = newNode;
        if (list->tail == NULL) list->tail = newNode;
    } else {
        newNode->next = currNode->next;
        currNode->next = newNode;
        if (currNode == list->tail) list->tail = newNode;
    }
}

int InsertAfterValue(LinkedList_t *list, Node_t *newNode, int value) {
    Node_t* target = FindValue(list, value);
    if (!target) {
        printf("Node not inserted.\n");
        return -1;
    }
    InsertAfter(list, newNode, target);
    return 0;
}

int InsertAfterIndex(LinkedList_t *list, Node_t *newNode, int index) {
    Node_t* target = FindIndex(list, index);
    if (!target) {
        printf("Node not inserted.\n");
        return -1;
    }
    InsertAfter(list, newNode, target);
    return 0;
}

void Remove(LinkedList_t *list, Node_t *remNode) {
    if (!list->head) return;
    if (list->head == remNode) {
        list->head = remNode->next;
        free(remNode);
        return;
    }
    Node_t* prev = list->head;
    while (prev->next && prev->next != remNode) prev = prev->next;
    if (prev->next) {
        prev->next = remNode->next;
        if (remNode == list->tail) list->tail = prev;
        free(remNode);
    }
}

int RemoveByValue(LinkedList_t *list, int value) {
    Node_t* target = FindValue(list, value);
    if (!target) {
        printf("Node not removed.\n");
        return -1;
    }
    Remove(list, target);
    return 0;
}

int RemoveByIndex(LinkedList_t *list, int index) {
    Node_t* target = FindIndex(list, index);
    if (!target) {
        printf("Node not removed.\n");
        return -1;
    }
    Remove(list, target);
    return 0;
}

LinkedList_t* ReverseList(LinkedList_t *list) {
    LinkedList_t* revList = CreateList();
    Node_t* current = list->head;
    while (current) {
        Node_t* newNode = CreateAndInitNode(current->data);
        InsertAfter(revList, newNode, NULL);
        current = current->next;
    }
    return revList;
}

int IsPalindrome(LinkedList_t *list) {
    LinkedList_t* revList = ReverseList(list);
    Node_t* orig = list->head;
    Node_t* rev = revList->head;
    while (orig && rev) {
        if (orig->data != rev->data) return 0;
        orig = orig->next;
        rev = rev->next;
    }
    return 1;
}

void PrintList(LinkedList_t *list) {
    Node_t* current = list->head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

