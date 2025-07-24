//FormAI DATASET v1.0 Category: Binary search trees ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node *left;
    struct node *right;
} Node;

Node *createNode(int key) {
    Node *newNode = (Node *) malloc(sizeof(Node));
    newNode->key = key;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

void insert(Node **root, int key) {
    if (*root == NULL) {
        *root = createNode(key);
    } else if (key < (*root)->key) {
        insert(&((*root)->left), key);
    } else if (key > (*root)->key) {
        insert(&((*root)->right), key);
    }
}

void inorderTraversal(Node *root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->key);
        inorderTraversal(root->right);
    }
}

int main() {
    Node *root = NULL;
    insert(&root, 4);
    insert(&root, 5);
    insert(&root, 2);
    insert(&root, 3);
    insert(&root, 1);
    printf("Inorder traversal of binary search tree: ");
    inorderTraversal(root);
    return 0;
}