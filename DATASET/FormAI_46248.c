//FormAI DATASET v1.0 Category: Binary search trees ; Style: energetic
#include <stdio.h> 
#include <stdlib.h> 

struct TreeNode { 
    int data; 
    struct TreeNode* left; 
    struct TreeNode* right; 
}; 

struct TreeNode* createNode(int value) 
{ 
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode)); 

    newNode->data = value; 

    newNode->left = NULL; 
    newNode->right = NULL; 

    return newNode; 
} 

struct TreeNode* insert(struct TreeNode* node, int value) 
{ 
    if (node == NULL) 
        return createNode(value); 

    if (value < node->data) 
        node->left = insert(node->left, value); 
    else if (value > node->data) 
        node->right = insert(node->right, value); 

    return node; 
} 

void printInorder(struct TreeNode* node) 
{ 
    if (node == NULL) 
        return; 

    printInorder(node->left); 

    printf("%d ", node->data); 

    printInorder(node->right); 
} 

int main() 
{ 
    struct TreeNode* root = NULL; 

    root = insert(root, 10); 
    insert(root, 30); 
    insert(root, 20); 
    insert(root, 25); 
    insert(root, 55); 
    insert(root, 45); 

    printf("Binary Search Tree: \n"); 

    printInorder(root); 

    return 0; 
}