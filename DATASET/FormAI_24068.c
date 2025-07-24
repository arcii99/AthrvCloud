//FormAI DATASET v1.0 Category: Binary search trees ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define node structure
typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
} Node;
 
// Create new node
Node* createNode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}
 
// Insert node recursively
Node* insert(Node* node, int key) {
    if (node == NULL) return createNode(key);
 
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);    
 
    return node;
}

// Search for node recursively
Node* search(Node* node, int key) {
    if (node == NULL || node->key == key)
        return node;
    if (node->key < key)
        return search(node->right, key);
    return search(node->left, key);
}

// Traverse the tree in-order
void traverseInOrder(Node* node) {
    if (node == NULL) return;

    traverseInOrder(node->left);
    printf("%d ", node->key);
    traverseInOrder(node->right);
}

int main() {
    Node* root = NULL;

    // Generate random keys
    srand(time(NULL));
    int keys[10];
    for (int i = 0; i < 10; i++)
        keys[i] = rand() % 100;
 
    // Insert keys into tree
    for (int i = 0; i < 10; i++)
        root = insert(root, keys[i]);

    printf("The Cyberpunk Binary Search Tree:\n");
    traverseInOrder(root);
    printf("\n");

    // Search for a specific key
    int searchKey = keys[rand() % 10];
    Node* searchResult = search(root, searchKey);
    if (searchResult != NULL)
        printf("The key %d was found in the tree.\n", searchKey);
    else
        printf("The key %d was not found in the tree.\n", searchKey);
 
    return 0;
}