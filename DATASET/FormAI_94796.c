//FormAI DATASET v1.0 Category: Binary search trees ; Style: careful
#include <stdio.h>
#include <stdlib.h>

// Structure definition for a node in the binary search tree
typedef struct bst_node {
    int data;
    struct bst_node* left;
    struct bst_node* right;
} bst_node;

// Function to create a new node with the given data
bst_node* create_node(int data) {
    bst_node* new_node = (bst_node*) malloc(sizeof(bst_node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a node with the given data into the binary search tree
bst_node* insert_node(bst_node* root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else if (root->data > data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

// Function to perform a pre-order traversal of the binary search tree
void pre_order_traversal(bst_node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        pre_order_traversal(root->left);
        pre_order_traversal(root->right);
    }
}

int main() {
    bst_node* root = create_node(50);
    insert_node(root, 30);
    insert_node(root, 20);
    insert_node(root, 40);
    insert_node(root, 70);
    insert_node(root, 60);
    insert_node(root, 80);
    printf("Pre-order traversal of binary search tree:\n");
    pre_order_traversal(root);
    return 0;
}