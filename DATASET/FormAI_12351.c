//FormAI DATASET v1.0 Category: Data structures visualization ; Style: realistic
#include <stdio.h>
#include <stdlib.h>

// define a node structure for the tree
typedef struct node
{
    int data;
    struct node *left;
    struct node *right;
} node;

// function to create a new node for the tree
node* create_node(int data)
{
    node* new_node = (node*) malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// function to insert a node into the tree
node* insert_node(node* root, int data)
{
    if (root == NULL)
    {
        root = create_node(data);
    }
    else if (data < root->data)
    {
        root->left = insert_node(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert_node(root->right, data);
    }
    return root;
}

// function to print the tree in inorder traversal
void inorder_traversal(node* root)
{
    if (root == NULL)
    {
        return;
    }
    inorder_traversal(root->left);
    printf("%d ", root->data);
    inorder_traversal(root->right);
}

int main()
{
    // create a new tree and insert some nodes
    node* root = NULL;
    root = insert_node(root, 10);
    insert_node(root, 8);
    insert_node(root, 12);
    insert_node(root, 6);
    insert_node(root, 9);
    insert_node(root, 11);
    insert_node(root, 13);

    // print the tree in inorder traversal
    printf("Inorder traversal of the binary search tree:\n");
    inorder_traversal(root);
    printf("\n");

    return 0;
}