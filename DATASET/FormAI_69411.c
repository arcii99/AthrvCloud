//FormAI DATASET v1.0 Category: Binary search trees ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} Node;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a node in the BST
Node* insertNode(Node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to traverse the BST in inorder and print the node data
void inorderTraversal(Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    int n, data;
    Node* root = NULL;

    // Read number of nodes to insert in the BST
    printf("Enter number of nodes to insert in the BST: ");
    scanf("%d", &n);

    // Read and insert each node in the BST
    for (int i = 0; i < n; i++) {
        printf("Enter node data: ");
        scanf("%d", &data);
        root = insertNode(root, data);
    }

    // Traverse the BST in inorder and print the node data
    printf("\nInorder traversal of the BST:\n");
    inorderTraversal(root);

    return 0;
}