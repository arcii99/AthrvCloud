//FormAI DATASET v1.0 Category: Data mining ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

// function to create a new node with given data
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return(node);
}

// recursive function to traverse through the binary tree
void traverseTree(struct node *root) {
    if (root) {
        traverseTree(root->left);
        printf("%d ", root->data);
        traverseTree(root->right);
    }
}

int main() {
    struct node* root = newNode(4);
    root->left = newNode(10);
    root->right = newNode(20);
    root->left->left = newNode(5);
    root->right->right = newNode(13);
    
    printf("The nodes in the binary tree: ");
    traverseTree(root);
    
    return 0;
}