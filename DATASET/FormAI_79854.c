//FormAI DATASET v1.0 Category: Binary search trees ; Style: genious
#include <stdio.h>
#include <stdlib.h>

// The node structure of our binary search tree
typedef struct Node {
    int value;
    struct Node *left_child;
    struct Node *right_child;
} Node;

// Function to create a new node with the given value
Node* create_node(int value) {
    Node *node = (Node*) malloc(sizeof(Node));
    node->value = value;
    node->left_child = NULL;
    node->right_child = NULL;
    return node;
}

// Function to insert a new node into the binary search tree
Node* insert_node(Node *root, int value) {
    if (root == NULL)
        return create_node(value);
    if (value < root->value)
        root->left_child = insert_node(root->left_child, value);
    else if (value > root->value)
        root->right_child = insert_node(root->right_child, value);
    return root;
}

// Function to search for a node with the given value in the binary search tree
Node* search_node(Node *root, int value) {
    if (root == NULL || root->value == value)
        return root;
    if (value < root->value)
        return search_node(root->left_child, value);
    return search_node(root->right_child, value);
}

// Function to print the binary search tree in a pre-order traversal
void print_preorder(Node *root) {
    if (root == NULL)
        return;
    printf("%d ", root->value);
    print_preorder(root->left_child);
    print_preorder(root->right_child);
}

// The main function
int main() {
    Node *root = NULL;
    root = insert_node(root, 50);
    insert_node(root, 30);
    insert_node(root, 20);
    insert_node(root, 40);
    insert_node(root, 70);
    insert_node(root, 60);
    insert_node(root, 80);

    printf("The binary search tree in pre-order traversal:\n");
    print_preorder(root);

    int value = 20;

    Node *result = search_node(root, value);

    if (result)
        printf("\nFound node with value %d in the binary search tree!", value);
    else
        printf("\nCould not find node with value %d in the binary search tree!", value);

    return 0;
}