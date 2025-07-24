//FormAI DATASET v1.0 Category: Binary search trees ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

//Define a node structure for binary search tree
struct TreeNode {
    int value;
    struct TreeNode* left;
    struct TreeNode* right;
};

//Function to create a new node
struct TreeNode* createNode(int value) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//Function to insert a node into binary search tree
struct TreeNode* insertNode(struct TreeNode* root, int value) {
    if(root == NULL) {
        return createNode(value);
    }
    if(value < root->value) {
        root->left = insertNode(root->left, value);
    }
    else if(value > root->value) {
        root->right = insertNode(root->right, value);
    }
    return root;
}

//Function to search for a node in binary search tree
struct TreeNode* searchNode(struct TreeNode* root, int value) {
    if(root == NULL || root->value == value) {
        return root;
    }
    if(value < root->value) {
        return searchNode(root->left, value);
    }
    return searchNode(root->right, value);
}

//Function to find the minimum value in binary search tree
struct TreeNode* findMin(struct TreeNode* root) {
    while(root->left != NULL) {
        root = root->left;
    }
    return root;
}

//Function to delete a node from binary serach tree
struct TreeNode* deleteNode(struct TreeNode* root, int value) {
    if(root == NULL) {
        return root;
    }
    if(value < root->value) {
        root->left = deleteNode(root->left, value);
    }
    else if(value > root->value) {
        root->right = deleteNode(root->right, value);
    }
    else {
        //Node with only one child or no child
        if(root->left == NULL) {
            struct TreeNode* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) {
            struct TreeNode* temp = root->left;
            free(root);
            return temp;
        }
        //Node with two children, get the inorder successor
        struct TreeNode* temp = findMin(root->right);
        root->value = temp->value;
        root->right = deleteNode(root->right, temp->value);
    }
    return root;
}

//Function to inorder traversal of binary search tree
void inorderTraversal(struct TreeNode* root) {
    if(root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->value);
        inorderTraversal(root->right);
    }
}

//Main function
int main() {
    struct TreeNode* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);
    printf("Inorder traversal of binary search tree: ");
    inorderTraversal(root);
    printf("\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal of binary search tree after deletion: ");
    inorderTraversal(root);
    printf("\n");
    return 0;
}