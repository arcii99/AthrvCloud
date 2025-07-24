//FormAI DATASET v1.0 Category: Binary search trees ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} node;

node* createNode(int data) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

node* insert(node* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }

    return root;
}

void inorderTraversal(node* root) {
    if (root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

node* findMin(node* root) {
    if (root == NULL) {
        return NULL;
    } else if (root->left == NULL) {
        return root;
    } else {
        return findMin(root->left);
    }
}

node* delete(node* root, int data) {
    if (root == NULL) {
        return NULL;
    }

    if (data < root->data) {
        root->left = delete(root->left, data);
    } else if (data > root->data) {
        root->right = delete(root->right, data);
    } else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        } else if (root->left == NULL || root->right == NULL) {
            node* temp = (root->left == NULL) ? root->right : root->left;
            free(root);
            return temp;
        } else {
            node* min_right = findMin(root->right);
            root->data = min_right->data;
            root->right = delete(root->right, min_right->data);
        }
    }

    return root;
}

int main() {
    node* root = NULL;

    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 1);
    root = insert(root, 7);
    root = insert(root, 6);
    root = insert(root, 9);

    printf("Inorder Traversal: ");
    inorderTraversal(root);
    printf("\n");

    root = delete(root, 6);

    printf("Inorder Traversal After Deletion: ");
    inorderTraversal(root);
    printf("\n");

    return 0;
}