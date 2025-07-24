//FormAI DATASET v1.0 Category: Binary search trees ; Style: scientific
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int value;
    struct Node* left;
    struct Node* right;
} Node;

Node* newNode(int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->value = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insert(Node* node, int value) {
    if (node == NULL) {
        return newNode(value);
    }

    if (value < node->value) {
        node->left = insert(node->left, value);
    } else {
        node->right = insert(node->right, value);
    }

    return node;
}

Node* search(Node* node, int value) {
    if (node == NULL || node->value == value) {
        return node;
    }

    if (value < node->value) {
        return search(node->left, value);
    } else {
        return search(node->right, value);
    }
}

void inorder(Node* node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%d ", node->value);
        inorder(node->right);
    }
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Binary Search Tree (Inorder): ");
    inorder(root);
    printf("\n");

    int value = 60;
    Node* result = search(root, value);
    if (result == NULL) {
        printf("%d not found\n", value);
    } else {
        printf("%d found\n", value);
    }

    return 0;
}