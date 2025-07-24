//FormAI DATASET v1.0 Category: Binary search trees ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Define a structure for the nodes in the tree
typedef struct node {
    char data;
    struct node* left;
    struct node* right;
} Node;

// Function to create a new node
Node* createNode(char data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node into the tree
Node* insert(Node* root, char data) {
    // If the root is empty, insert new node as root
    if (root == NULL) {
        return createNode(data);
    }

    // If the new data is less than the current node, insert it to the left
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    // If the new data is greater than or equal to the current node, insert it to the right
    else {
        root->right = insert(root->right, data);
    }

    return root;
}

// Function to print the tree in order
void printInOrder(Node* root) {
    // If the root is not empty, print the data of each node in order
    if (root != NULL) {
        printInOrder(root->left);
        printf("%c ", root->data);
        printInOrder(root->right);
    }
}

int main() {
    // Create a root node of the tree
    Node* root = NULL;

    // Insert some happy emojis into the tree
    root = insert(root, '😊');
    insert(root, '😂');
    insert(root, '🥳');
    insert(root, '🎉');
    insert(root, '🌈');
    insert(root, '🍕');

    // Print the tree in order
    printf("Here's a happy binary search tree with emojis: \n");
    printInOrder(root);

    return 0;
}