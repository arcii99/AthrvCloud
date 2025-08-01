//FormAI DATASET v1.0 Category: Binary search trees ; Style: synchronous
#include <stdio.h> 
#include <stdlib.h> 

struct node { 
    int key; 
    struct node *left, *right; 
}; 

// Create a new node 
struct node *newNode(int item) { 
    struct node *temp = (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

// Insert a new node in BST 
struct node *insert(struct node *node, int key) { 
    if (node == NULL) 
        return newNode(key); 
  
    if (key < node->key) 
        node->left = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key); 
    return node; 
} 

// Inorder traversal of BST 
void inorder(struct node *root) { 
    if (root != NULL) { 
        inorder(root->left); 
        printf("%d ", root->key); 
        inorder(root->right); 
    } 
} 
  
int main() { 
    struct node *root = NULL; 
    root = insert(root, 50); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 40); 
    insert(root, 70); 
    insert(root, 60); 
    insert(root, 80); 

    inorder(root); 
  
    return 0; 
}