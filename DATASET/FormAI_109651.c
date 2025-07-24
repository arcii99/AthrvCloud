//FormAI DATASET v1.0 Category: Binary search trees ; Style: distributed
#include<stdio.h>
#include<stdlib.h>

// Define the structure for Binary Search Tree
struct binarySearchTree{
    int data;
    struct binarySearchTree* left;
    struct binarySearchTree* right;
};

// Function to create a new node with given data
struct binarySearchTree* createNewNode(int data){
    struct binarySearchTree* node = (struct binarySearchTree*)malloc(sizeof(struct binarySearchTree));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to insert a new node in the Binary Search Tree
struct binarySearchTree* insertNode(struct binarySearchTree* root, int data){
    // If root is null, create a new node with the given data
    if(root == NULL){
        return createNewNode(data);
    }
    // Else, traverse the tree and insert the new node at appropriate position
    if(data < root->data){
        root->left = insertNode(root->left, data);
    }
    else if(data > root->data){
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to search for a node in the Binary Search Tree
int searchNode(struct binarySearchTree* root, int key){
    // If root is null or key is present at root, return true
    if(root == NULL || root->data == key){
        return 1;
    }
    // If key is greater than root's key, search in right subtree
    if(root->data < key){
        return searchNode(root->right, key);
    }
    // Else search in left subtree
    return searchNode(root->left, key);
}

// Function to print the inorder traversal of Binary Search Tree
void inorderTraversal(struct binarySearchTree* root){
    if(root != NULL){
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main(){
    struct binarySearchTree* root = NULL;
    // Inserting nodes in the Binary Search Tree
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    // Printing the inorder traversal of Binary Search Tree
    printf("Inorder Traversal:\n");
    inorderTraversal(root);

    // Searching for a node in the Binary Search Tree
    int key = 20;
    if(searchNode(root, key)){
        printf("\n%d is present in the Binary Search Tree.\n", key);
    }
    else{
        printf("\n%d is not present in the Binary Search Tree.\n", key);
    }

    return 0;
}