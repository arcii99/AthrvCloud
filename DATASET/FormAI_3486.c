//FormAI DATASET v1.0 Category: Binary search trees ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

// Define structure for a node in the binary search tree
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node and initialize its values
struct TreeNode* newNode(int data) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Function to insert a new node into the binary search tree
struct TreeNode* insert(struct TreeNode* node, int data) {
    // If the tree is empty, return a new node
    if (node == NULL) {
        return newNode(data);
    }

    // Otherwise, recur down the tree
    if (data < node->data) {
        node->left = insert(node->left, data);
    }
    else if (data > node->data) {
        node->right = insert(node->right, data);
    }

    // Return the (unchanged) node pointer
    return node;
}

// Function to traverse the binary search tree in order
void inorderTraversal(struct TreeNode* node) {
    if (node != NULL) {
        inorderTraversal(node->left);
        printf("%d ", node->data);
        inorderTraversal(node->right);
    }
}

int main() {
    struct TreeNode* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal of binary search tree: ");
    inorderTraversal(root);

    return 0;
}