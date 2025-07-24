//FormAI DATASET v1.0 Category: Binary search trees ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

struct Node {
        int data;
        struct Node* left;
        struct Node* right;
};

// Create function to make a new Node with provided data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Insert function to add a new Node to the tree
struct Node* insert(struct Node* node, int data) {
    // If the tree is empty, create a new Node with the provided data
    if (node == NULL)
        return newNode(data);

    // Otherwise, recur down the tree
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    // Return the (unchanged) Node pointer
    return node;
}

// Function to find the minimum value Node in the tree
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;

    // Loop down to the leftmost leaf
    while (current && current->left != NULL)
        current = current->left;

    return current;
}

// Function to delete a Node from the tree
struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL)
        return root;

    // Otherwise, recur down the tree
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        // Node with only one child or no child
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        // Node with two children: Get the inorder successor (smallest in the right subtree)
        struct Node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->data = temp->data;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to print the binary tree in preorder traversal
void preOrderTraversal(struct Node* node) {
    if (node == NULL) // base case
        return;

    // print the current node
    printf("%d ", node->data);

    // recur on left child
    preOrderTraversal(node->left);

    // recur on right child
    preOrderTraversal(node->right);
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Original Tree: ");
    preOrderTraversal(root);

    root = deleteNode(root, 20);

    printf("\nModified tree after deleting 20: ");
    preOrderTraversal(root);

    return 0;
}