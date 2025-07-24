//FormAI DATASET v1.0 Category: Binary search trees ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Define the structure for the binary search tree node
typedef struct BSTNode {
    int value;
    struct BSTNode* left;
    struct BSTNode* right;
} BSTNode;

// Function to create a new BST node with the given value
BSTNode* createBSTNode(int value) {
    BSTNode* node = (BSTNode*) malloc(sizeof(BSTNode));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node into the BST
BSTNode* insertBSTNode(BSTNode* root, int value) {
    if (root == NULL) {
        return createBSTNode(value);
    }
    if (value < root->value) {
        root->left = insertBSTNode(root->left, value);
    } else if (value > root->value) {
        root->right = insertBSTNode(root->right, value);
    }
    return root;
}

// Function to print the BST in-order
void printInOrder(BSTNode* root) {
    if (root != NULL) {
        printInOrder(root->left);
        printf("%d ", root->value);
        printInOrder(root->right);
    }
}

int main() {
    // Create the root node
    BSTNode* root = createBSTNode(10);

    // Insert nodes into the BST
    insertBSTNode(root, 5);
    insertBSTNode(root, 7);
    insertBSTNode(root, 13);
    insertBSTNode(root, 11);

    // Print the BST in-order
    printf("Binary Search Tree:\n");
    printInOrder(root);

    return 0;
}