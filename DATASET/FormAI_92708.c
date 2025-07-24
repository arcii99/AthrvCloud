//FormAI DATASET v1.0 Category: Binary search trees ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

/* Structure definition for BST */
struct node {
    int data;           // Data of the node
    struct node* left;  // Pointer to the left child
    struct node* right; // Pointer to the right child
};

/* Function to create a new node with the given data */
struct node* create_node(int data) {
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

/* Function to insert a new node with the given data */
struct node* insert_node(struct node* node, int data) {

    if (node == NULL) {
        return create_node(data); // If the tree is empty, create a new node
    }

    // Otherwise, recur down the tree
    if (data < node->data) {
        node->left = insert_node(node->left, data);
    } 
    else if (data > node->data) {
        node->right = insert_node(node->right, data);
    }

    // Return the unchanged node pointer
    return node;
}

/* Function to perform inorder traversal of BST */
void inorder_traversal(struct node* node) {
    if (node == NULL) {
        return;
    }
    inorder_traversal(node->left);
    printf("%d ", node->data);
    inorder_traversal(node->right);
}

/* Main driver function */
int main() {
    struct node* root = NULL;
    printf("Please enter the number of nodes that you want to insert: ");
    int n;
    scanf("%d", &n);

    printf("Please enter the %d nodes:\n", n);
    int i;
    for (i = 0; i < n; i++) {
        int data;
        scanf("%d", &data);
        root = insert_node(root, data);
    }

    printf("Inorder traversal of the BST is:");
    inorder_traversal(root);
    printf("\n");

    return 0;
}