//FormAI DATASET v1.0 Category: Binary search trees ; Style: inquisitive
#include<stdio.h>
#include<stdlib.h>

// defining a structure for each node in the BST
struct node {
    int data;
    struct node* left;
    struct node* right;
};

// function to create a new node in the BST
struct node* createNode(int value) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// function to insert a new node into the BST
struct node* insert(struct node* root, int value) {
    if(root == NULL) {
        return createNode(value);
    }
    if(value < root->data) {
        root->left = insert(root->left, value);
    }
    else if(value > root->data) {
        root->right = insert(root->right, value);
    }
    return root;
}

// function to search for a node in the BST
struct node* search(struct node* root, int value) {
    if(root == NULL || root->data == value) {
        return root;
    }
    else if(value < root->data) {
        return search(root->left, value);
    }
    else{
        return search(root->right, value);
    }
}

// function to traverse the BST in preorder
void preOrderTraversal(struct node* root) {
    if(root != NULL) {
        printf("%d ", root->data);
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

int main() {
    struct node* root = NULL;
    int n, value;
    printf("Enter the number of nodes you want to insert in the BST: ");
    scanf("%d", &n);
    printf("Enter the values you want to insert in the BST: ");
    for(int i=0; i<n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }
    printf("The preorder traversal of the BST is: ");
    preOrderTraversal(root);
    printf("\n");
    printf("Enter the value you want to search in the BST: ");
    scanf("%d", &value);
    struct node* result = search(root, value);
    if(result != NULL) {
        printf("The value is found in the BST.\n");
    }
    else {
        printf("The value is not found in the BST.\n");
    }
    return 0;
}