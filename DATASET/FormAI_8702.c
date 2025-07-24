//FormAI DATASET v1.0 Category: Binary search trees ; Style: immersive
#include <stdio.h>
#include <stdlib.h>

// Define the structure to hold a node in the binary search tree
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Function to create a new node and initialize its values
struct node* newNode(int data) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Function to insert a new node into the binary search tree
struct node* insertNode(struct node* node, int data) {
    // If the tree is empty, return a new node
    if (node == NULL) {
        return newNode(data);
    }
    // Otherwise, recur down the tree
    if (data < node->data) {
        node->left = insertNode(node->left, data);
    }
    else if (data > node->data) {
        node->right = insertNode(node->right, data);
    }
    // Return the (unchanged) node pointer
    return node;
}

// Function to search for a specific node in the binary search tree
struct node* searchNode(struct node* root, int data) {
    // If the tree is empty or the data is found, return the node
    if (root == NULL || root->data == data) {
        return root;
    }
    // If the data is greater than root's data, recurse right
    if (root->data < data) {
        return searchNode(root->right, data);
    }
    // If the data is less than root's data, recurse left
    return searchNode(root->left, data); 
}

// Function to traverse the binary search tree in order
void inorderTraversal(struct node* node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d ", node->data);
        inorderTraversal(node->right);
    }
}

int main() {
    struct node* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);
    printf("Binary Search tree in order:\n");
    inorderTraversal(root);

    int searchData = 60;
    struct node* searchResult = searchNode(root, searchData);
    if (searchResult == NULL) {
        printf("\n%d not found in the Binary search tree\n", searchData);
    }
    else {
        printf("\n%d found in the Binary search tree\n", searchResult->data);
    }

    return 0;
}