//FormAI DATASET v1.0 Category: Binary search trees ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void printTree(struct Node* root) {
    if (root != NULL) {
        printTree(root->left);
        printf("%d ", root->data);
        printTree(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int values[] = {10, 2, 5, 20, 1, 30};
    int size = sizeof(values) / sizeof(values[0]);
    
    for (int i=0; i<size; ++i) {
        root = insertNode(root, values[i]);
    }
    
    printf("Binary Search Tree elements (in-order): ");
    printTree(root);

    return 0;
}