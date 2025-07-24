//FormAI DATASET v1.0 Category: Binary search trees ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

// Define the structure for the binary search tree node
typedef struct node
{
    int data;
    struct node* left;
    struct node* right;
} Node;

// Function to create a new node with a given key
Node* createNode(int key)
{
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node with a given key to a binary search tree
Node* insertNode(Node* root, int key)
{
    // If the tree is empty, return a new node
    if (root == NULL) return createNode(key);
 
    // Otherwise, recur down the tree
    if (key < root->data)
        root->left  = insertNode(root->left, key);
    else if (key > root->data)
        root->right = insertNode(root->right, key);   
 
    // Return the (unchanged) node pointer
    return root;
}

// Function to perform inorder traversal of a binary search tree
void inorderTraversal(Node* root)
{
    if (root != NULL)
    {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

// Driver program to test above functions
int main()
{
    Node* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);
 
    // Print inorder traversal of the BST
    inorderTraversal(root);
 
    return 0;
}