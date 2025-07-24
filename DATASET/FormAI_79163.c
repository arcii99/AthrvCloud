//FormAI DATASET v1.0 Category: Binary search trees ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// Definition of a node in the binary search tree
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node
struct node* create_node(int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a node into the binary search tree
struct node* insert_node(struct node* root, int data) {
    if (root == NULL) {
        return create_node(data);
    } else if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else {
        root->right = insert_node(root->right, data);
    }
    return root;
}

// Function to perform an inorder traversal of the binary search tree
void inorder_traversal(struct node* root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d ", root->data);
        inorder_traversal(root->right);
    }
}

int main() {
    // Create the binary search tree
    struct node* root = NULL;
    root = insert_node(root, 5);
    insert_node(root, 3);
    insert_node(root, 1);
    insert_node(root, 4);
    insert_node(root, 7);
    insert_node(root, 6);
    insert_node(root, 9);
    
    // Print the elements of the binary search tree in inorder traversal
    printf("Inorder traversal of the binary search tree: ");
    inorder_traversal(root);
    printf("\n");

    return 0;
}