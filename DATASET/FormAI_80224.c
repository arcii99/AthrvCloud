//FormAI DATASET v1.0 Category: Database Indexing System ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of the key
#define MAX_KEY_LEN 32

// Define the maximum number of records
#define MAX_RECORDS 1000

// Define the structure of a record
typedef struct {
    char key[MAX_KEY_LEN];
    int data;
} Record;

// Define the structure of a node in the index
typedef struct IndexNode {
    char key[MAX_KEY_LEN];
    int address;
    struct IndexNode *next;
} IndexNode;

// Define the structure of the index
typedef struct {
    IndexNode *root;
} Index;

// Function to insert a record into the index
void insert(Index *index, char *key, int address) {
    // Create a new index node
    IndexNode *node = (IndexNode*) malloc(sizeof(IndexNode));
    strcpy(node->key, key);
    node->address = address;
    node->next = NULL;
    
    // Traverse the index to find the correct position to insert the new node
    IndexNode *prev = NULL;
    IndexNode *curr = index->root;
    while (curr != NULL && strcmp(key, curr->key) > 0) {
        prev = curr;
        curr = curr->next;
    }
    
    // Insert the new node
    if (prev == NULL) {
        node->next = index->root;
        index->root = node;
    } else {
        node->next = prev->next;
        prev->next = node;
    }
}

// Function to search for a key in the index and return the corresponding address
int search(Index *index, char *key) {
    // Traverse the index to find the node with the matching key
    IndexNode *curr = index->root;
    while (curr != NULL && strcmp(key, curr->key) > 0) {
        curr = curr->next;
    }
    
    // Return the corresponding address if found, or -1 if not found
    if (curr != NULL && strcmp(key, curr->key) == 0) {
        return curr->address;
    } else {
        return -1;
    }
}

// Main function
int main() {
    // Create the index and initialize the root node to NULL
    Index index;
    index.root = NULL;
    
    // Create an array of records
    Record records[MAX_RECORDS] = {
        {"apple", 10},
        {"banana", 20},
        {"cherry", 30},
        {"date", 40},
        {"eggplant", 50},
        {"fig", 60},
        {"grape", 70},
        {"honeydew", 80},
        {"kiwi", 90},
        {"lemon", 100},
        {"mango", 110},
        {"nectarine", 120},
        {"orange", 130},
        {"peach", 140},
        {"quince", 150},
        {"raspberry", 160},
        {"strawberry", 170},
        {"tangerine", 180},
        {"ugli fruit", 190},
        {"watermelon", 200}
    };
    
    // Insert the records into the index
    int i;
    for (i = 0; i < MAX_RECORDS; i++) {
        insert(&index, records[i].key, i);
    }
    
    // Search for some keys in the index
    int address;
    address = search(&index, "apple");
    printf("The address of the record with key 'apple' is %d\n", address);
    
    address = search(&index, "banana");
    printf("The address of the record with key 'banana' is %d\n", address);
    
    address = search(&index, "watermelon");
    printf("The address of the record with key 'watermelon' is %d\n", address);
    
    address = search(&index, "pear");
    printf("The address of the record with key 'pear' is %d\n", address);
    
    // Free the memory used by the index
    IndexNode *curr = index.root;
    IndexNode *temp;
    while (curr != NULL) {
        temp = curr;
        curr = curr->next;
        free(temp);
    }
    
    return 0;
}