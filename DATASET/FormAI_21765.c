//FormAI DATASET v1.0 Category: Binary search trees ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* createNode(int data) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct node* insert(struct node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    } else {
        if (data <= root->data) {
            root->left = insert(root->left, data);
        } else {
            root->right = insert(root->right, data);
        }
        return root;
    }
}

struct node* search(struct node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    } else if (data < root->data) {
        return search(root->left, data);
    } else {
        return search(root->right, data);
    }
}

void printInorder(struct node* node) {
    if (node == NULL) {
        return;
    }
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

int main() {
    struct node* root = NULL;
    root = insert(root, 6);
    insert(root, 2);
    insert(root, 8);
    insert(root, 1);
    insert(root, 5);
    insert(root, 3);
    insert(root, 7);
    printf("Inorder traversal of the binary search tree is: ");
    printInorder(root);
    printf("\n");

    int searchFor = 5;
    struct node* result = search(root, searchFor);
    if (result == NULL) {
        printf("Element not found\n");
    } else {
        printf("Element %d found in binary search tree\n", result->data);
    }
    return 0;
}