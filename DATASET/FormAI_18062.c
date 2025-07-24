//FormAI DATASET v1.0 Category: Binary search trees ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node * left;
    struct node * right;
};

// Function to create new nodes
struct node * createNode(int value) {
    struct node * newNode = malloc(sizeof(struct node));

    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

// Function to insert a new node in the tree
struct node * insertNode(struct node * root, int value) {
    if (root == NULL) {
        return createNode(value);
    }

    if (value <= root->data) {
        root->left = insertNode(root->left, value);
    } else {
        root->right = insertNode(root->right, value);
    }

    return root;
}

// Function to print the tree in-order
void printInOrder(struct node * root) {
    if (root == NULL) {
        return;
    }

    printInOrder(root->left);
    printf("%d ", root->data);
    printInOrder(root->right);
}

int main() {
    struct node * root = NULL;

    // Insert nodes into the tree
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    // Print the tree in-order
    printf("The elements of the Binary Search Tree in order are: \n");
    printInOrder(root);

    return 0;
}