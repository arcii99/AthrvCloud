//FormAI DATASET v1.0 Category: Data structures visualization ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>

// Structure for a node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)
        malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

// Function to print the binary tree
void printTree(struct Node* root, int space) {
    // Base case
    if (root == NULL) {
        return;
    }
    // Increase distance between levels
    space += 10;
    // Print the right child recursively
    printTree(root->right, space);
    printf("\n");
    // Print current node
    for (int i = 10; i < space; i++) {
        printf(" ");
    }
    printf("%d\n", root->data);
    // Print the left child recursively
    printTree(root->left, space);
}

int main() {
    // Create the root node and its children
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    // Print the binary tree
    printf("Binary tree visualization example:\n\n");
    printTree(root, 0);
    return 0;
}