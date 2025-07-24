//FormAI DATASET v1.0 Category: Binary search trees ; Style: surprised
#include<stdio.h>
#include<stdlib.h>

struct node { // defining the structure of the node
    int data;
    struct node *left;
    struct node *right;
};

struct node *newNode(int item) // creating a new node with the given data
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct node *root) // inorder traversal of binary search tree
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d \n", root->data);
        inorder(root->right);
    }
}

struct node* insert(struct node* node, int data) // inserting a new node in the BST
{
    if (node == NULL) return newNode(data);

    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    return node;
}

int main() // main function starts here
{
    printf("Surprise! You are about to create a Binary Search Tree!\n\n");

    struct node *root = NULL;

    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("\nInorder traversal of the binary search tree is: \n");
    inorder(root);

    printf("\n\nCongratulations! You have successfully created a Binary Search Tree!\n");

    return 0;
}