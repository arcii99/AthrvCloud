//FormAI DATASET v1.0 Category: Binary search trees ; Style: excited
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* leftChild;
    struct node* rightChild;
} Node;

Node* createNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->leftChild = NULL;
    node->rightChild = NULL;

    return node;
}

Node* insert(Node* node, int data) {
    if (node == NULL) {
        return createNode(data);
    }

    if (data < node->data) {
        node->leftChild = insert(node->leftChild, data);
    } else if (data > node->data) {
        node->rightChild = insert(node->rightChild, data);
    }

    return node;
}

void inOrderTraverse(Node* node) {
    if (node == NULL) {
        return;
    }

    inOrderTraverse(node->leftChild);
    printf("%d ", node->data);
    inOrderTraverse(node->rightChild);
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

    printf("In-order traversal of the binary search tree: ");
    inOrderTraverse(root);
    printf("\n");

    return 0;
}