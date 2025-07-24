//FormAI DATASET v1.0 Category: Binary search trees ; Style: grateful
#include<stdio.h> 
#include<stdlib.h>

struct BSTNode {
    int data;
    struct BSTNode *left;
    struct BSTNode *right;
}; 

/*
  Create a new node
*/
struct BSTNode* createNode(int data) {
    struct BSTNode *newNode = (struct BSTNode*)malloc(sizeof(struct BSTNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

/*
  Insert data into binary search tree
*/
struct BSTNode* insert(struct BSTNode *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

/*
  In-order traversal of binary search tree
  Display the sorted elements
*/
void inOrderTraversal(struct BSTNode *root) {
    if (root != NULL) {
        inOrderTraversal(root->left);
        printf("%d ", root->data);
        inOrderTraversal(root->right);
    }
}

/*
  Driver function
*/
int main() {
    struct BSTNode *root = NULL;
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 2);
    insert(root, 7);
    insert(root, 12);
    insert(root, 20);
    printf("Binary Search Tree Data:\n");
    inOrderTraversal(root);
    return 0;
}