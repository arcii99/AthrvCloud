//FormAI DATASET v1.0 Category: Binary search trees ; Style: complex
#include <stdio.h>
#include <stdlib.h>

// Struct for tree nodes
typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

// Function to create a new node with given value
Node* createNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a value into the BST
Node* insert(Node* node, int value) {
    if (node == NULL)
        return createNode(value);

    if (value < node->value)
        node->left = insert(node->left, value);
    else if (value > node->value)
        node->right = insert(node->right, value);

    return node;
}

// Function to print the BST in order
void printInOrder(Node* node) {
    if (node == NULL)
        return;

    printInOrder(node->left);
    printf("%d ", node->value);
    printInOrder(node->right);
}

// Main function
int main() {
    // Create BST
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    // Print BST in order
    printf("BST: ");
    printInOrder(root);
    printf("\n");

    return 0;
}