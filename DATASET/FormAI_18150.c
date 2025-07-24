//FormAI DATASET v1.0 Category: Binary search trees ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>

typedef struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
} TreeNode;

TreeNode* createNode(int data) {
    TreeNode* newNode = malloc(sizeof(TreeNode));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

TreeNode* insert(TreeNode* root, int data) {
    if(root == NULL) {
        return createNode(data);
    } else if(data <= root->data) {
        root->left = insert(root->left, data);
    } else {
        root->right = insert(root->right, data);
    }
    return root;
}

TreeNode* search(TreeNode* root, int data) {
    if(root == NULL || root->data == data) {
        return root;
    }
    else if(data < root->data) {
        return search(root->left, data);
    }
    else {
        return search(root->right, data);
    }
}

void traverseInOrder(TreeNode* root) {
    if(root != NULL) {
        traverseInOrder(root->left);
        printf("%d ", root->data);
        traverseInOrder(root->right);
    }
}

int main() {
    TreeNode* root = NULL;
    root = insert(root, 10);
    insert(root, 20);
    insert(root, 5);
    insert(root, 1);
    insert(root, 7);

    printf("In-order traversal of binary search tree: ");
    traverseInOrder(root);
    printf("\n");

    int searchData = 7;
    TreeNode* result = search(root, searchData);
    if(result == NULL) {
        printf("%d not found in the tree\n", searchData);
    }
    else {
        printf("%d found in the tree\n", searchData);
    }
    
    return 0;
}