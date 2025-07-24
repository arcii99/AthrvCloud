//FormAI DATASET v1.0 Category: Binary search trees ; Style: imaginative
#include<stdio.h>
#include<stdlib.h>

// Define the structure of the binary tree node
struct node
{
    int data;
    struct node *left;
    struct node *right;
};

// Function to create a binary tree node
struct node * createNode(int x)
{
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

// Function to insert a node in the binary search tree
struct node * insert(struct node *root, int x)
{
    if(root == NULL)
    {
        root = createNode(x);
        return root;
    }
    else if(root->data > x)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
    return root;
}

// Function to perform inorder traversal of the binary tree
void inorder(struct node *root)
{
    if(root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Main function
int main()
{
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("Inorder traversal of the binary search tree is : ");
    inorder(root);
    return 0;
}