//FormAI DATASET v1.0 Category: Binary search trees ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Creating a struct for creating the binary tree
struct node {
    int data;               // Store integer data
    struct node *left;      // Pointer to the left node
    struct node *right;     // Pointer to the right node
};

// Function that creates a new node of the binary tree
struct node* create_node(int data) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a new node in the binary tree
struct node* insert_node(struct node* root, int data) {
    if (root == NULL) {
        return create_node(data);
    }
    if (data < root->data) {
        root->left = insert_node(root->left, data);
    }
    else if(data > root->data) {
        root->right = insert_node(root->right, data);
    }
    return root;
}

// Function to search a node in the binary tree
struct node* search_node(struct node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (root->data < data) {
        return search_node(root->right, data);
    }
    return search_node(root->left, data);
}

// Function to print the binary tree in Inorder traversal
void inorder_print(struct node* root) {
    if (root != NULL) {
        inorder_print(root->left);
        printf("%d ", root->data);
        inorder_print(root->right);
    }
}

int main() {
    struct node* root = NULL;
    int search_value = 30;

    // Inserting nodes in the binary tree
    root = insert_node(root, 50);
    insert_node(root, 30);
    insert_node(root, 20);
    insert_node(root, 40);
    insert_node(root, 70);
    insert_node(root, 60);
    insert_node(root, 80);

    // Printing the binary tree in Inorder traversal
    printf("Printing the binary tree in Inorder traversal:\n");
    inorder_print(root);

    // Searching a node in the binary tree
    struct node* search_result = search_node(root, search_value);
    if (search_result == NULL) {
        printf("\n%d does not exist in the binary tree.", search_value);
    }
    else {
        printf("\n%d is present in the binary tree.", search_value);
    }

    // Deallocating the memory of the binary tree
    free(root);

    return 0;
}