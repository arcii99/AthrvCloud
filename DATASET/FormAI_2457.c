//FormAI DATASET v1.0 Category: Database Indexing System ; Style: portable
#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent a node in our indexing system
struct IndexNode {
    int key;
    int value;
    struct IndexNode* next;
};

// Define a function to insert a new node into our indexing system
void insert(struct IndexNode** table, int key, int value) {
    // Calculate the hash value for the key
    int index = key % 100;
    
    // Create a new node to insert
    struct IndexNode* newNode = (struct IndexNode*) malloc(sizeof(struct IndexNode));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    
    // If the table at the given index is empty, set the head to the new node
    if (table[index] == NULL) {
        table[index] = newNode;
    } else {
        // Otherwise, traverse the linked list at the given index to find the end
        struct IndexNode* current = table[index];
        while (current->next != NULL) {
            current = current->next;
        }
        
        // Append the new node to the end of the linked list
        current->next = newNode;
    }
}

// Define a function to retrieve a value from our indexing system given a key
int retrieve(struct IndexNode** table, int key) {
    // Calculate the hash value for the key
    int index = key % 100;
    
    // Traverse the linked list at the given index to find the node with the matching key
    struct IndexNode* current = table[index];
    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    
    // If we reach this point, we didn't find a matching key
    return -1;
}

int main() {
    // Initialize an array of pointers to indexing system nodes
    struct IndexNode* table[100];
    for (int i = 0; i < 100; i++) {
        table[i] = NULL;
    }
    
    // Insert some values into our indexing system
    insert(table, 42, 10);
    insert(table, 3, 5);
    insert(table, 103, 7);
    insert(table, 142, 12);
    insert(table, 53, 2);
    
    // Retrieve some values from our indexing system
    printf("The value for key 42 is %d\n", retrieve(table, 42));
    printf("The value for key 103 is %d\n", retrieve(table, 103));
    printf("The value for key 53 is %d\n", retrieve(table, 53));
    
    // Free all allocated memory before exiting program
    for (int i = 0; i < 100; i++) {
        struct IndexNode* current = table[i];
        while (current != NULL) {
            struct IndexNode* temp = current;
            current = current->next;
            free(temp);
        }
    }
    
    return 0;
}