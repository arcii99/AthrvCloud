//FormAI DATASET v1.0 Category: Binary search trees ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Creating the binary search tree node structure
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

// Function to insert a new node
struct node* insert(struct node* node, int data) {
    if (node == NULL) return newNode(data);
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);
    return node;
}

// Function to search for a node
struct node* search(struct node* root, int data) {
    if (root == NULL || root->data == data)
       return root;
    if (root->data < data)
       return search(root->right, data);
    return search(root->left, data);
}

// Function to print the inorder traversal of the binary search tree
void inorderTraversal(struct node* node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d ", node->data);
        inorderTraversal(node->right);
    }
}

int main() {
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("Inorder traversal of the binary search tree: ");
    inorderTraversal(root);
    int toFind = 60;
    struct node* result = search(root, toFind);
    if (result == NULL) {
        printf("\n%d not found in BST.\n", toFind);
    } else {
        printf("\n%d found in BST.\n", toFind);
    }
    return 0;
}