//FormAI DATASET v1.0 Category: Binary search trees ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

// Binary Search Tree Node Definition
typedef struct BST_Node {
    int data;
    struct BST_Node* left;
    struct BST_Node* right;
} BST_Node;

// Function to create a new node
BST_Node* create_new_node(int data) {
    BST_Node* new_node = (BST_Node*) malloc(sizeof(BST_Node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

// Function to insert a node in the BST
BST_Node* insert_node(BST_Node* root, int data) {
    if (root == NULL) {
        return create_new_node(data);
    } else if (data < root->data) {
        root->left = insert_node(root->left, data);
    } else if (data > root->data) {
        root->right = insert_node(root->right, data);
    }
    return root;
}

// Function to traverse the BST in inorder
void inorder_traversal(BST_Node* root) {
    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d\n", root->data);
        inorder_traversal(root->right);
    }
}

int main() {
    int n, data;
    BST_Node* root = NULL;

    printf("Welcome to the Binary Search Tree Program\n");

    // Insert nodes in the BST
    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the values of the nodes: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &data);
        root = insert_node(root, data);
    }

    // Traverse the BST in inorder
    printf("\nInorder Traversal of the Binary Search Tree:\n");
    inorder_traversal(root);

    return 0;
}