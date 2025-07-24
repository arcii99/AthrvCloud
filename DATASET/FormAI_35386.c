//FormAI DATASET v1.0 Category: Database Indexing System ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define the size of the hash table
#define TABLE_SIZE 100

// define the structure of the hash table node
typedef struct Node {
    char key[50];
    int value;
    struct Node* next;
} Node;

// define the hash table
Node* hashTable[TABLE_SIZE];

// initialize the hash table
void initHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = NULL;
    }
}

// generate hash code for a given string key
int getHashCode(char* key) {
    int hash = 0;
    for (int i = 0; i < strlen(key); i++) {
        hash = hash + (int)key[i];
    }
    return hash % TABLE_SIZE;
}

// insert a key-value pair to the hash table
void insert(char* key, int value) {
    int hash = getHashCode(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->key, key);
    newNode->value = value;
    newNode->next = NULL;
    if (hashTable[hash] == NULL) {
        hashTable[hash] = newNode;
    } else {
        Node* current = hashTable[hash];
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// find the value associated with a given key
int find(char* key) {
    int hash = getHashCode(key);
    Node* current = hashTable[hash];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return -1;
}

// print the hash table
void printHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d]", i);
        Node* current = hashTable[i];
        while (current != NULL) {
            printf(" -> (%s, %d)", current->key, current->value);
            current = current->next;
        }
        printf("\n");
    }
}

// example usage of the hash table
int main() {
    initHashTable();
    insert("Alice", 25);
    insert("Bob", 28);
    insert("Charlie", 30);
    insert("David", 33);
    printf("Value of Alice: %d\n", find("Alice"));
    printf("Value of Charlie: %d\n", find("Charlie"));
    printf("Value of Emma: %d\n", find("Emma"));
    printHashTable();
    return 0;
}