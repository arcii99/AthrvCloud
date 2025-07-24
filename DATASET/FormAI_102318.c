//FormAI DATASET v1.0 Category: Binary search trees ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* node, int data) {
    if (node == NULL) {
        return createNode(data);
    }
    if (data < node->data) {
        node->left = insertNode(node->left, data);
    } else if (data > node->data) {
        node->right = insertNode(node->right, data);
    }
    return node;
}

Node* searchNode(Node* node, int data) {
    if (node == NULL || node->data == data) {
        return node;
    }
    if (data < node->data) {
        return searchNode(node->left, data);
    }
    return searchNode(node->right, data);
}

void inorderTraversal(Node* node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d ", node->data);
        inorderTraversal(node->right);
    }
}

int main() {
    Node* root = NULL;
    root = insertNode(root, 10);
    insertNode(root, 20);
    insertNode(root, 30);
    insertNode(root, 40);
    insertNode(root, 50);
    insertNode(root, 60);
    
    printf("Inorder traversal: ");
    inorderTraversal(root);
    
    int searchValue = 50;
    Node* searchedNode = searchNode(root, searchValue);
    if (searchedNode != NULL) {
        printf("\n%d found in the tree.", searchValue);
    } else {
        printf("\n%d not found in the tree.", searchValue);
    }
    return 0;
}