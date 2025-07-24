//FormAI DATASET v1.0 Category: Binary search trees ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// Define a node in the binary search tree
typedef struct node {
    int key;
    struct node* left;
    struct node* right;
} Node;

// Function to create a new node with the given key value
Node* createNode(int key) {
    Node* node = malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node with the given key value
Node* insert(Node* node, int key) {
    if (node == NULL) {
        return createNode(key);
    }
    if (key < node->key) {
        node->left = insert(node->left, key);
    }
    else if (key > node->key) {
        node->right = insert(node->right, key);
    }
    return node;
}

// Function to print the binary search tree
void printTree(Node* node, int depth) {
    if (node == NULL) {
        return;
    }
    printTree(node->right, depth+1);
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("%d\n", node->key);
    printTree(node->left, depth+1);
}

// Main function
int main() {
    // Create the root node with key value 50
    Node* root = createNode(50);

    // Insert some nodes into the tree
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Print the binary search tree
    printf("Binary Search Tree:\n");
    printTree(root, 0);

    return 0;
}