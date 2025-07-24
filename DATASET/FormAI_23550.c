//FormAI DATASET v1.0 Category: Binary search trees ; Style: brave
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* insert(struct Node* node, int key) {
    if (node == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = key;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    
    if (key < node->data) {
        node->left = insert(node->left, key);
    }
    else if (key > node->data) {
        node->right = insert(node->right, key);
    }
    
    return node;
}

void printInorder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
 
    printf("The inorder traversal of the binary search tree is:\n");
    printInorder(root);
 
    return 0;
}