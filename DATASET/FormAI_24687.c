//FormAI DATASET v1.0 Category: Binary search trees ; Style: real-life
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

Node* insert(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

Node* search(Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (root->data < data) {
        return search(root->right, data);
    }
    return search(root->left, data);
}

int main(void) {

    Node* root = NULL;
    root = insert(root, 6);
    insert(root, 8);
    insert(root, 7);
    insert(root, 3);
    insert(root, 4);
    insert(root, 1);

    printf("Inorder traversal of the binary search tree: ");
    inorder(root);
    printf("\n");

    int searchValue = 4;
    Node* result = search(root, searchValue);
    if (result != NULL) {
        printf("%d is present in the binary search tree\n", searchValue);
    }
    else {
        printf("%d is not present in the binary search tree\n", searchValue);
    }

    return 0;
}