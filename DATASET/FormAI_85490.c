//FormAI DATASET v1.0 Category: Binary search trees ; Style: Ada Lovelace
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int key;
    struct node* left;
    struct node* right;
} node;

node* new_node(int key) {
    node* temp = (node*)malloc(sizeof(node));
    temp->key = key;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

node* insert(node* root, int key) {
    if (root == NULL) {
        return new_node(key);
    }
    if (key < root->key) {
        root->left = insert(root->left, key);
    } else if (key > root->key) {
        root->right = insert(root->right, key);
    }
    return root;
}

void preorder_traversal(node* root) {
    if (root != NULL) {
        printf("%d ", root->key);
        preorder_traversal(root->left);
        preorder_traversal(root->right);
    }
}

int main() {
    node* root = NULL;
    
    // insert elements into the binary search tree
    root = insert(root, 10);
    insert(root, 5);
    insert(root, 15);
    insert(root, 7);
    insert(root, 2);
    insert(root, 12);
    insert(root, 20);

    printf("Preorder Traversal of Binary Search Tree: ");
    preorder_traversal(root);
    
    return 0;
}