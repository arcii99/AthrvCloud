//FormAI DATASET v1.0 Category: Binary search trees ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
struct node {
    int data;
    struct node *left;
    struct node *right;
};

// Create a new node with the given data
struct node *createNode(int data) {
    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a node with the given data into the BST
struct node *insert(struct node *root, int data) {
    if (root == NULL) {
        return createNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

// Search for a node with the given data in the BST
struct node *search(struct node *root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

// Traverse the BST in-order and print its elements
void printInOrder(struct node *root) {
    if (root != NULL) {
        printInOrder(root->left);
        printf("%d ", root->data);
        printInOrder(root->right);
    }
}

// Main function to test the BST
int main() {
    struct node *root = NULL;
    int n, data;
    printf("Enter the number of elements to insert into the BST: ");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    while (n--) {
        scanf("%d", &data);
        root = insert(root, data);
    }
    printf("The elements in the BST are:\n");
    printInOrder(root);
    printf("\n");
    printf("Enter an element to search in the BST: ");
    scanf("%d", &data);
    struct node *result = search(root, data);
    if (result == NULL) {
        printf("Element not found in the BST\n");
    } else {
        printf("Element found in the BST\n");
    }
    return 0;
}