//FormAI DATASET v1.0 Category: Binary search trees ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

// Structure for each node in the BST.
struct Node 
{
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new node with the given key.
struct Node* createNode(int key) 
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = key;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node in the BST.
struct Node* insert(struct Node* root, int key) 
{
    // If the tree is empty, create a new node and return it.
    if (root == NULL) 
    {
        return createNode(key);
    }

    // If the key is already in the tree, return the root node.
    else if (root->data == key) 
    {
        return root;
    }

    // If the key is less than the root's key, insert it in the left subtree.
    else if (key < root->data) 
    {
        root->left = insert(root->left, key);
    }

    // If the key is greater than the root's key, insert it in the right subtree.
    else 
    {
        root->right = insert(root->right, key);
    }

    return root;
}

// Function to traverse the BST in-order and print its nodes.
void printInOrder(struct Node* root) 
{
    if (root != NULL) 
    {
        printInOrder(root->left);
        printf("%d ", root->data);
        printInOrder(root->right);
    }
}

// Function to traverse the BST and find the node with the given key.
struct Node* search(struct Node* root, int key) 
{
    // If the tree is empty or the key is found at the root, return the root node.
    if (root == NULL || root->data == key) 
    {
        return root;
    }

    // If the key is less than the root's key, search in the left subtree.
    else if (key < root->data) 
    {
        return search(root->left, key);
    }

    // If the key is greater than the root's key, search in the right subtree.
    else 
    {
        return search(root->right, key);
    }
}

int main() 
{
    struct Node* root = NULL;

    // Insert nodes into the BST.
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    // Print the nodes of the BST in-order.
    printf("In-order traversal of the BST:\n");
    printInOrder(root);

    // Search for a node in the BST.
    int key = 70;
    struct Node* node = search(root, key);
    if (node != NULL) 
    {
        printf("\n\nNode with key %d found in the BST!\n", key);
    }
    else 
    {
        printf("\n\nNode with key %d not found in the BST :(\n", key);
    }

    // Free the memory allocated for the BST.
    free(root);
    return 0;
}