//FormAI DATASET v1.0 Category: Binary search trees ; Style: standalone
#include <stdio.h>
#include <stdlib.h>

// Define our binary search tree structure
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Function to create a new Node
struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

// Function to insert a Node into our binary search tree
struct Node* insert(struct Node* node, int data) {
    // If the tree is empty, create a new Node and return it
    if (node == NULL) return newNode(data);

    // Otherwise, recur down the tree to find where to insert the new Node
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data > node->data)
        node->right = insert(node->right, data);

    // Return the (unchanged) Node pointer
    return node;
}

// Function to search for a Node in our binary search tree
struct Node* search(struct Node* root, int data) {
    // If the tree is empty or we found the Node, return the Node
    if (root == NULL || root->data == data)
        return root;

    // Otherwise, recur down the tree
    if (root->data < data)
        return search(root->right, data);

    return search(root->left, data);
}

// Function to display the contents of our binary search tree in-order
void inOrder(struct Node* node) {
    if (node != NULL) {
        inOrder(node->left);
        printf("%d ", node->data);
        inOrder(node->right);
    }
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

    // Display the binary search tree in-order
    inOrder(root);

    // Search for a Node in the binary search tree
    struct Node* temp = search(root, 20);
    if (temp != NULL) printf("\nFound: %d\n", temp->data);
    else printf("\nNot Found\n");

    return 0;
}