//FormAI DATASET v1.0 Category: Binary search trees ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

/* Defining the structure for the Binary Search Tree */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

/* Function to create a new Node with given data */
struct Node* newNode(int data) {
    /* Allocating memory for new node */
    struct Node* node = (struct Node*)
                        malloc(sizeof(struct Node));
    /* Assigning data to the new node */
    node->data = data;
    /* Setting left and right children as NULL */
    node->left = NULL;
    node->right = NULL;
    return node;
}

/* Function to insert a new node in the Binary Search Tree */
struct Node* insert(struct Node* node, int data) {
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(data);
    /* Otherwise, recur down the tree */
    if (data < node->data)
        node->left  = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);   
    /* Return the (unchanged) node pointer */
    return node;
}

/* Function to traverse the Binary Search Tree in Inorder fashion */
void inorder(struct Node* node) {
    if (node == NULL) return;
    inorder(node->left); /* Left */
    printf("%d ", node->data); /* Print current node */
    inorder(node->right); /* Right */
}

/* Main function for the program */
int main() {
    /* Starting with an empty tree */
    struct Node* root = NULL;
    /* Inserting nodes in the Binary Search Tree */
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);   
    /* Displaying the nodes in the Binary Search Tree in Inorder fashion */
    printf("Inorder traversal of the Binary Search Tree: \n");
    inorder(root);
    return 0;
}