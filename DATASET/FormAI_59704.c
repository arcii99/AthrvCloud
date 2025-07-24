//FormAI DATASET v1.0 Category: Data structures visualization ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in a binary tree
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node_t;

// Function to create a new node with the given data
node_t* create_node(int data) {
    node_t* new_node = (node_t*) malloc(sizeof(node_t));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Recursive function to insert a node in the binary tree
node_t* insert_node(node_t* root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else if (data > root->data) {
        root->right = insert_node(root->right, data);
    }
    return root;
}

// Recursive function to print the binary tree in a visual format
void print_tree(node_t* root, int depth) {
    if (root == NULL) {
        return;
    }
    print_tree(root->right, depth+1);
    for (int i = 0; i < depth; i++) {
        printf("    ");
    }
    printf("%d\n", root->data);
    print_tree(root->left, depth+1);
}

// Main function to test the binary tree data structure
int main() {
    node_t* root = NULL;
    root = insert_node(root, 50);
    insert_node(root, 30);
    insert_node(root, 20);
    insert_node(root, 40);
    insert_node(root, 70);
    insert_node(root, 60);
    insert_node(root, 80);
    print_tree(root, 0);
    return 0;
}