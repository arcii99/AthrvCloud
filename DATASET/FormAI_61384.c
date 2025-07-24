//FormAI DATASET v1.0 Category: Binary search trees ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>

// Node structure of Binary Search Tree
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// Async function to create a new node
struct node* createNode(int item) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = item;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Async function to insert a new node
struct node* insert(struct node* root, int item) {
    if (root == NULL) {
        return createNode(item);
    }

    if (item < root->data) {
        root->left = insert(root->left, item);
    } else {
        root->right = insert(root->right, item);
    }

    return root;
}

// Async function to search for a node
struct node* search(struct node* root, int item) {
    if (root == NULL || root->data == item) {
        return root;
    }

    if (item < root->data) {
        return search(root->left, item);
    } else {
        return search(root->right, item);
    }
}

// Async function to find minimum value node in a tree/subtree
struct node* minValueNode(struct node* node) {
    struct node* current = node;

    while (current && current->left != NULL) {
        current = current->left;
    }

    return current;
}

// Async function to delete a node from the tree
struct node* deleteNode(struct node* root, int item) {
    if (root == NULL) {
        return root;
    }

    if (item < root->data) {
        root->left = deleteNode(root->left, item);
    } else if (item > root->data) {
        root->right = deleteNode(root->right, item);
    } else {
        if (root->left == NULL) {
            struct node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node* temp = root->left;
            free(root);
            return temp;
        }

        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }

    return root;
}

// Async function to traverse the tree in-order
void inorder(struct node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// Main function to test the above BST functions
int main() {
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal of the BST: ");
    inorder(root);
    printf("\n");

    printf("Deleting node 20 from the BST\n");
    root = deleteNode(root, 20);

    printf("Inorder traversal of the modified BST: ");
    inorder(root);
    printf("\n");

    printf("Searching for node with value 60 in the BST\n");
    struct node* searchedNode = search(root, 60);
    printf("Node with value 60 was %sfound in the BST\n", searchedNode ? "" : "not ");

    return 0;
}