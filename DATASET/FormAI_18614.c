//FormAI DATASET v1.0 Category: Database Indexing System ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_KEY_SIZE 20
#define MAX_DATA_SIZE 64
#define MAX_TABLE_SIZE 100

// Define a structure for a node in the index
typedef struct IndexNode {
    char key[MAX_KEY_SIZE];
    char data[MAX_DATA_SIZE];
    struct IndexNode* next;
} IndexNode;

// Define a structure for the index itself
typedef struct Index {
    int size;
    IndexNode* table[MAX_TABLE_SIZE];
} Index;

// Initialize the index
void initIndex(Index* index) {
    index->size = 0;
    for (int i = 0; i < MAX_TABLE_SIZE; i++) {
        index->table[i] = NULL;
    }
}

// Hash function to convert key to index in table
int hashFunction(char* key) {
    int value = 0;
    for (; *key != '\0'; key++) {
        value += *key;
    }
    return value % MAX_TABLE_SIZE;
}

// Insert a node into the index
void insertNode(Index* index, char* key, char* data) {
    IndexNode* node = (IndexNode*) malloc(sizeof(IndexNode));
    strncpy(node->key, key, MAX_KEY_SIZE);
    strncpy(node->data, data, MAX_DATA_SIZE);
    node->next = NULL;

    int indexValue = hashFunction(key);

    if (index->table[indexValue] == NULL) {
        index->table[indexValue] = node;
    } else {
        IndexNode* currentNode = index->table[indexValue];
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = node;
    }
    index->size++;
}

// Search for a node in the index
IndexNode* searchNode(Index* index, char* key) {
    int indexValue = hashFunction(key);
    IndexNode* node = index->table[indexValue];

    while (node != NULL) {
        if (strncmp(node->key, key, MAX_KEY_SIZE) == 0) {
            return node;
        }
        node = node->next;
    }

    return NULL;
}

// Delete a node from the index
void deleteNode(Index* index, char* key) {
    int indexValue = hashFunction(key);
    IndexNode* node = index->table[indexValue];
    IndexNode* prevNode = NULL;

    while (node != NULL) {
        if (strncmp(node->key, key, MAX_KEY_SIZE) == 0) {
            if (prevNode == NULL) {
                index->table[indexValue] = node->next;
            } else {
                prevNode->next = node->next;
            }
            free(node);
            index->size--;
            return;
        }
        prevNode = node;
        node = node->next;
    }
}

// Print the contents of the index
void printIndex(Index* index) {
    printf("Index size: %d\n", index->size);
    for (int i = 0; i < MAX_TABLE_SIZE; i++) {
        if (index->table[i] != NULL) {
            printf("[%d]", i);
            IndexNode* currentNode = index->table[i];
            while (currentNode != NULL) {
                printf(" -> %s:%s", currentNode->key, currentNode->data);
                currentNode = currentNode->next;
            }
            printf("\n");
        }
    }
}

int main() {
    Index index;
    initIndex(&index);

    // Insert some nodes into the index
    insertNode(&index, "apple", "A pomaceous fruit");
    insertNode(&index, "banana", "An elongated tropical fruit");
    insertNode(&index, "cherry", "A small red fruit");
    insertNode(&index, "date", "A sweet brown fruit");

    // Print the contents of the index
    printIndex(&index);

    // Search for a node in the index
    printf("Search for 'cherry':\n");
    IndexNode* node = searchNode(&index, "cherry");
    if (node != NULL) {
        printf("Found: %s:%s\n", node->key, node->data);
    } else {
        printf("Not found.\n");
    }

    // Delete a node from the index
    printf("Delete 'banana':\n");
    deleteNode(&index, "banana");

    // Print the contents of the index again
    printIndex(&index);

    return 0;
}