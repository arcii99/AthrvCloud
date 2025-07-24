//FormAI DATASET v1.0 Category: Binary search trees ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// Binary Search Tree structure
struct node {
    int key;
    struct node *left, *right;
};

// Create a new node with given key
struct node *newNode(int item) {
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

// Insert a key into BST
struct node* insert(struct node* node, int key) {
    // If the tree is empty, return a new node
    if (node == NULL) return newNode(key);
 
    // Otherwise, recur down the tree
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);   
 
    return node;
}

// Inorder traversal of BST, used for printing nodes in ascending order
void inorder(struct node* node) {
    if (node != NULL) {
        inorder(node->left);
        printf("%d ", node->key);
        inorder(node->right);
    }
}

// Main function
int main() {
    // Initialize empty tree
    struct node *root = NULL;
 
    // Insert nodes into tree
    root = insert(root, 8);
    insert(root, 3);
    insert(root, 10);
    insert(root, 1);
    insert(root, 6);
    insert(root, 14);
    insert(root, 4);
    insert(root, 7);
    insert(root, 13);
 
    // Print BST nodes in ascending order
    printf("Inorder traversal of BST: ");
    inorder(root);
 
    return 0;
}