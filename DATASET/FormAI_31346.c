//FormAI DATASET v1.0 Category: Binary search trees ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

node* create_node(int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node* insert(node* root, int data) {
    if (root == NULL) {
        return create_node(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

void inorder_traversal(node* root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

int main() {
    node* root = NULL;
    int array[] = {40, 20, 60, 10, 30, 50, 70};
    int array_size = sizeof(array) / sizeof(array[0]);
    for (int i = 0; i < array_size; i++) {
        root = insert(root, array[i]);
    }
    printf("Inorder traversal of the binary search tree: ");
    inorder_traversal(root);
    return 0;
}