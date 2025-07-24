//FormAI DATASET v1.0 Category: Data structures visualization ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

/* Node structure for binary search tree */
typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} Node;

/* Function to create new node */
Node* newNode(int key) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->key = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

/* Function to insert a node into BST */
Node* insert(Node* node, int key) {
    if (node == NULL) {
        return newNode(key);
    }
    if (key < node->key) {
        node->left = insert(node->left, key);
    }
    else if (key > node->key) {
        node->right = insert(node->right, key);
    }
    return node;
}

/* Function to print tree in increasing order */
void printInOrder(Node* node) {
    if (node == NULL) {
        return;
    }
    printInOrder(node->left);
    printf("%d -> ", node->key);
    printInOrder(node->right);
}

int main() {
    printf("Creating a binary search tree...\n");
    Node* root = NULL;
    root = insert(root, 10);
    insert(root, 7);
    insert(root, 15);
    insert(root, 5);
    insert(root, 12);
    insert(root, 17);

    /* Print the tree in increasing order */
    printf("The binary search tree:\n");
    printInOrder(root);
    printf("\n");

    return 0;
}