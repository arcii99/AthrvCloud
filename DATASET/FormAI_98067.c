//FormAI DATASET v1.0 Category: Binary search trees ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return node;
}

Node* insert(Node* root, int data) {
    // If the tree is empty, return a new node
    if (root == NULL) {
        return newNode(data);
    }

    // Otherwise, recur down the tree
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }

    // return the (unchanged) node pointer
    return root;
}

Node* search(Node* root, int data) {
    // Base Cases: root is null or data is present at root
    if (root == NULL || root->data == data) {
        return root;
    }

    // Key is greater than root's key
    if (root->data < data) {
        return search(root->right, data);
    }

    // Key is smaller than root's key
    return search(root->left, data);
}

void inOrder(Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    inOrder(root);

    int key = 60;
    Node* resultNode = search(root, key);
    if (resultNode != NULL) {
        printf("\n%d is found in the tree!", key);
    } else {
        printf("\n%d is not found in the tree.", key);
    }

    return 0;
}