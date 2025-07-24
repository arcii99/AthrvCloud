//FormAI DATASET v1.0 Category: Binary search trees ; Style: creative
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* node, int data) {
    if (node == NULL) {
        return createNode(data);
    }

    if (data < node->data) {
        node->left = insert(node->left, data);
    } else if (data > node->data) {
        node->right = insert(node->right, data);
    }

    return node;
}

Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    } else if (root->data < data) {
        return search(root->right, data);
    } else {
        return search(root->left, data);
    }
}

void inOrder(Node* node) {
    if (node != NULL) {
        inOrder(node->left);
        printf("%d ", node->data);
        inOrder(node->right);
    }
}

int main() {
    Node* root = NULL;

    root = insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    insert(root, 1);
    insert(root, 9);

    printf("The tree contains: ");
    inOrder(root);
    printf("\n");

    int searchInt = 3;
    Node* result = search(root, searchInt);
    if (result == NULL) {
        printf("%d is not in the tree.\n", searchInt);
    } else {
        printf("%d is in the tree.\n", searchInt);
    }

    return 0;
}