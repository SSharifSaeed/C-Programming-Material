/*
Sharif Saeed
ECE 340 data structures and systems
Project #4
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

typedef struct HashTable {
    LinkedList_t* arrayOfLL;
    int tableSize;
    int numOfItems;
} HashTable_t;

Node_t* CreateNode(int value);
LinkedList_t* CreateArrayOfLists(int size);
HashTable_t* CreateTable(int size);
int CalculateTableIndex(HashTable_t* table, int value);
void InsertTable(HashTable_t* table, int value);
void RemoveTable(HashTable_t* table, int value);
void PrintTable(HashTable_t* table);

Node_t* CreateNode(int value) {
    Node_t* newNode = (Node_t*)malloc(sizeof(Node_t));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

LinkedList_t* CreateArrayOfLists(int size) {
    LinkedList_t* array = (LinkedList_t*)malloc(sizeof(LinkedList_t) * size);
    for (int i = 0; i < size; i++) {
        array[i].head = NULL;
        array[i].tail = NULL;
    }
    return array;
}

HashTable_t* CreateTable(int size) {
    HashTable_t* table = (HashTable_t*)malloc(sizeof(HashTable_t));
    table->tableSize = size;
    table->numOfItems = 0;
    table->arrayOfLL = CreateArrayOfLists(size);
    return table;
}

int CalculateTableIndex(HashTable_t* table, int value) {
    return value % table->tableSize;
}

void InsertTable(HashTable_t* table, int value) {
    int index = CalculateTableIndex(table, value);
    LinkedList_t* list = &table->arrayOfLL[index];

    Node_t* current = list->head;
    while (current) {
        if (current->data == value) return; // Already exists
        current = current->next;
    }

    Node_t* newNode = CreateNode(value);
    if (!list->head) {
        list->head = list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
    table->numOfItems++;
}

void RemoveTable(HashTable_t* table, int value) {
    int index = CalculateTableIndex(table, value);
    LinkedList_t* list = &table->arrayOfLL[index];

    Node_t* current = list->head;
    Node_t* prev = NULL;

    while (current) {
        if (current->data == value) {
            if (prev) {
                prev->next = current->next;
            } else {
                list->head = current->next;
            }
            if (current == list->tail) {
                list->tail = prev;
            }
            free(current);
            table->numOfItems--;
            return;
        }
        prev = current;
        current = current->next;
    }
}

void PrintTable(HashTable_t* table) {
    for (int i = 0; i < table->tableSize; i++) {
        printf("%d:", i);
        Node_t* current = table->arrayOfLL[i].head;
        while (current) {
            printf(" %d", current->data);
            current = current->next;
        }
        printf("\n");
    }
    printf("\nload = %.3f\n\n", (float)table->numOfItems / table->tableSize);
}

// --- Main Program ---

int main() {
    int size, option, value;
    printf("Specify the size of the hash table: ");
    scanf("%d", &size);

    HashTable_t* table = CreateTable(size);

    while (1) {
        printf("Select the operation to perform:\n");
        printf("1.  Insert a value\n");
        printf("2.  Remove a value\n");
        printf("3.  Exit\n");
        printf("Select an option: ");
        scanf("%d", &option);

        if (option == 3) {
            printf("\nGood-bye.\n");
            break;
        }

        printf("Enter a value: ");
        scanf("%d", &value);

        if (option == 1) {
            InsertTable(table, value);
        } else if (option == 2) {
            RemoveTable(table, value);
        }

        PrintTable(table);
    }
    return 0;
}
