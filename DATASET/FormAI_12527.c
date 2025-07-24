//FormAI DATASET v1.0 Category: Data structures visualization ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

// Define our unique data structure `Tree`
typedef struct Tree {
    int value;
    struct Tree* left;
    struct Tree* right;
} Tree;

// Function to create a new node on the `Tree`
Tree* createNode(int value) {
    Tree* node = (Tree*)malloc(sizeof(Tree));

    node->value = value;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Function to recursively print the `Tree` structure
void printTree(Tree* node, int level) {
    if (node == NULL) {
        return;
    }

    int i;
    for (i = 0; i < level; i++) {
        printf(" ");
    }

    printf("%d\n", node->value);
    printTree(node->left, level + 1);
    printTree(node->right, level + 1);
}

// The `main` program
int main() {
    // Create a `Tree` structure to represent our unique data structure
    Tree* root = createNode(10);
    root->left = createNode(5);
    root->right = createNode(15);
    root->left->left = createNode(3);
    root->left->right = createNode(7);
    root->right->left = createNode(13);
    root->right->right = createNode(17);

    // Use the `printTree` function to print our unique data structure
    printTree(root, 0);

    return 0;
}