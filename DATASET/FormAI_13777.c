//FormAI DATASET v1.0 Category: Binary search trees ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Create a new node
struct node* new_node(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert a new node into the tree
struct node* insert(struct node* node, int data) {
    if(node == NULL) {
        return new_node(data);
    }
    if(data < node->data) {
        node->left = insert(node->left, data);
    }
    else if(data > node->data) {
        node->right = insert(node->right, data);
    }
    return node;
}

// Inorder traversal of the tree
void inorder_traversal(struct node* node) {
    if(node != NULL) {
        inorder_traversal(node->left);
        printf("%d ", node->data);
        inorder_traversal(node->right);
    }
}

// Main program
int main() {
    printf("Welcome to our Binary Search Tree program!\n");

    // Create an empty Binary Search Tree
    struct node* root = NULL;

    // Insert some nodes into the tree
    root = insert(root, 10);
    insert(root, 12);
    insert(root, 6);
    insert(root, 7);
    insert(root, 22);

    // Print the tree using inorder traversal
    printf("The Binary Search Tree contains the following nodes in ascending order:\n");
    inorder_traversal(root);

    printf("\nThank you for using our Binary Search Tree program! Have a great day!\n");

    return 0;
}