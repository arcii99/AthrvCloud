//FormAI DATASET v1.0 Category: Binary search trees ; Style: complete
#include <stdio.h>
#include <stdlib.h>

/* BST node structure */
struct node {
    int key;
    struct node *left, *right;
};

/* Function to create a new node */
struct node* newNode(int item)
{
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

/* Insert function to insert a new node in the BST */
struct node* insert(struct node* node, int key)
{
    /* If the tree is empty, return a new node */
    if (node == NULL) return newNode(key);

    /* Recur down the tree */
    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    /* Return the (unchanged) node pointer */
    return node;
}

/* Inorder traversal of the BST to print the elements in ascending order */
void inorder(struct node* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

/* Main Program */
int main()
{
    /* Initialize the BST by inserting a few nodes */
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    /* Print the elements of the BST in ascending order */
    printf("Inorder traversal of binary search tree: ");
    inorder(root);

    return 0;
}