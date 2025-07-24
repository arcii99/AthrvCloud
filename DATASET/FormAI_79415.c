//FormAI DATASET v1.0 Category: Binary search trees ; Style: complete
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
} Node;

// Create a new node
Node* createNode(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Insert a value into the binary search tree
Node* insert(Node* root, int val) {
    if (root == NULL) {
        return createNode(val);
    }
    
    if (val < root->data) {
        root->left = insert(root->left, val);
    } else {
        root->right = insert(root->right, val);
    }
    
    return root;
}

// Search for a value in the binary search tree
Node* search(Node* root, int val) {
    if (root == NULL || root->data == val) {
        return root;
    }
    
    if (val < root->data) {
        return search(root->left, val);
    } else {
        return search(root->right, val);
    }
}

// Delete a node from the binary search tree
Node* delete(Node* root, int val) {
    if (root == NULL) {
        return root;
    }
    
    if (val < root->data) {
        root->left = delete(root->left, val);
    } else if (val > root->data) {
        root->right = delete(root->right, val);
    } else {
        if (root->left == NULL) {
            Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Node* temp = root->left;
            free(root);
            return temp;
        }
        
        Node* temp = root->right;
        while (temp->left != NULL) {
            temp = temp->left;
        }
        
        root->data = temp->data;
        root->right = delete(root->right, temp->data);
    }
    
    return root;
}

// Print out the binary search tree in order
void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    root = insert(root, 5);
    root = insert(root, 3);
    root = insert(root, 7);
    root = insert(root, 1);
    root = insert(root, 9);
    root = insert(root, 6);
    
    printf("Original tree:\n");
    inorder(root);
    
    printf("\n\nDeleting node 5:\n");
    root = delete(root, 5);
    inorder(root);
    
    printf("\n\nAdding node 10:\n");
    root = insert(root, 10);
    inorder(root);
    
    printf("\n");
    
    return 0;
}