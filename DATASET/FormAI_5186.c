//FormAI DATASET v1.0 Category: Binary search trees ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

/* A binary tree node */
struct node {
    int data;
    struct node *left;
    struct node *right;
};

/* Create a new Node in Binary Tree */
struct node* newNode(int data) {
    struct node* node = (struct node*)malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

/* Insert a new Node in Binary Tree */
struct node* insert(struct node* node, int data) {
    /* If the tree is empty, return a new Node */
    if (node == NULL)
        return(newNode(data));
    
    /* Otherwise, recurse down the tree */
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    /* Return the unchanged node pointer */
    return node;
}

/* Search a Node in Binary Tree */
struct node* search(struct node* root, int data) {
    /* Base Cases: root is null or data is present at root */
    if (root == NULL || root->data == data)
       return root;
    
    /* Key is greater than root's key */
    if (root->data < data)
       return search(root->right, data);
 
    /* Key is smaller than root's key */
    return search(root->left, data);
}

/* Preorder Traversal of Binary Tree */
void preorder(struct node* root) {
    if(root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

int main() {
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
 
    printf("Preorder traversal of binary tree is: ");
    preorder(root);
    
    /* Search for a Node */
    struct node* found_node = search(root, 40);
    if(found_node == NULL)
        printf("\nNode is not present in the Binary Tree");
    else
        printf("\nNode found in the Binary Tree with value : %d", found_node->data);
 
    return 0;
}