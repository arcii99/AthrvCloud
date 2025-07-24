//FormAI DATASET v1.0 Category: Recursive ; Style: decentralized
#include <stdlib.h>
#include <stdio.h>

// Define the struct for the decentralized node
typedef struct node {
    int value;
    struct node* left;
    struct node* right;
} Node;

// Recursive function to insert a new value into the tree
void insert(Node** root, int value) {
    if (*root == NULL) {
        *root = (Node*) malloc(sizeof(Node));
        (*root)->value = value;
        (*root)->left = NULL;
        (*root)->right = NULL;
    } else if (value < (*root)->value) {
        insert(&(*root)->left, value);
    } else {
        insert(&(*root)->right, value);
    }
}

// Recursive function to print the tree in-order
void printInOrder(Node* root) {
    if (root != NULL) {
        printInOrder(root->left);
        printf("%d ", root->value);
        printInOrder(root->right);
    }
}

// Main function
int main() {
    Node* root = NULL;
    printf("Enter 10 integers to insert into the tree:\n");
    for (int i = 0; i < 10; i++) {
        int value;
        scanf("%d", &value);
        insert(&root, value);
    }
    printf("The in-order traversal of the tree is:\n");
    printInOrder(root);
    return 0;
}