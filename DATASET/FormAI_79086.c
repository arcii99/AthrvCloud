//FormAI DATASET v1.0 Category: Binary search trees ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

// Define a node struct for the Binary Search Tree
struct node
{
    int data;
    struct node* left;
    struct node* right;
};

// Define a function to create a new node with the given data
struct node* newNode(int data)
{
    struct node* node = (struct node*)malloc(sizeof(struct node)); // Allocate memory for the new node
    node->data = data; // Set the data of the new node
    node->left = NULL; // Set the left child of the new node to NULL
    node->right = NULL; // Set the right child of the new node to NULL
    
    return node; // Return the new node
}

// Define a function to insert a new node into the Binary Search Tree
struct node* insertNode(struct node* node, int data)
{
    // Check if the tree is empty
    if (node == NULL)
    {
        return newNode(data); // Create a new node with the given data and return it
    }
    
    // Otherwise, insert the new node into the appropriate subtree
    if (data < node->data) // If the data is less than the data of the current node
    {
        node->left = insertNode(node->left, data); // Insert the new node into the left subtree
    }
    else // If the data is greater than or equal to the data of the current node
    {
        node->right = insertNode(node->right, data); // Insert the new node into the right subtree
    }
    
    return node; // Return the current node
}

// Define a function to print the Binary Search Tree in order
void printInOrder(struct node* node)
{
    if (node == NULL) { return; } // Base case
    
    printInOrder(node->left); // Print the left subtree
    printf("%d ", node->data); // Print the current node's data
    printInOrder(node->right); // Print the right subtree
}

int main()
{
    // Create a Binary Search Tree
    struct node* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);
    
    // Print the Binary Search Tree in order
    printf("In-order traversal of the Binary Search Tree:\n");
    printInOrder(root);
    
    return 0; // Exit the program
}