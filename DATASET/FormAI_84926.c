//FormAI DATASET v1.0 Category: Binary search trees ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

// define the structure of a node in the binary search tree
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// function to create a new node with a given data value
struct node* create_node(int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// function to insert a new node into the binary search tree
struct node* insert_node(struct node* root, int data) {
    // base case: if the tree is empty, return a new node
    if (root == NULL)
        return create_node(data);
    
    // recursive case: traverse the tree to find the appropriate place to insert the new node
    if (data < root->data)
        root->left = insert_node(root->left, data);
    else if (data > root->data)
        root->right = insert_node(root->right, data);
    
    // return the root of the tree after the new node has been inserted
    return root;
}

// function to traverse the binary search tree in order
void inorder_traversal(struct node* root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d -> ", root->data);
        inorder_traversal(root->right);
    }
}

// main function to test the binary search tree
int main() {
    // initialize an empty binary search tree
    struct node* root = NULL;
    
    // insert some data values into the binary search tree
    root = insert_node(root, 50);
    insert_node(root, 30);
    insert_node(root, 20);
    insert_node(root, 40);
    insert_node(root, 70);
    insert_node(root, 60);
    insert_node(root, 80);
    
    // traverse the binary search tree in order
    printf("Inorder Traversal: ");
    inorder_traversal(root);
    printf("\n");
    
    // exit the program
    return 0;
}