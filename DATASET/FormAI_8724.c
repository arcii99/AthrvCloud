//FormAI DATASET v1.0 Category: Binary search trees ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

// define the structure of the binary tree
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// function to create a new node
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// function to insert a new node into the tree
struct Node* insert(struct Node* node, int data) {
    // if the tree is empty, create a new node
    if (node == NULL) return newNode(data);
    
    // otherwise, recursively insert the new node into the appropriate subtree
    if (data < node->data)
        node->left = insert(node->left, data);
    else if (data >= node->data)
        node->right = insert(node->right, data);
        
    return node;
}

// function to perform a binary search for a specific node
struct Node* search(struct Node* node, int target) {
    // if the tree is empty or we have found the target node, return it
    if (node == NULL || node->data == target)
        return node;
        
    // if the target is less than the current node's data, search the left subtree
    if (target < node->data)
        return search(node->left, target);
        
    // otherwise, search the right subtree
    return search(node->right, target);
}

// function to print the nodes of the tree in-order
void inOrderTraversal(struct Node* node) {
    if (node != NULL) {
        inOrderTraversal(node->left);
        printf("%d ", node->data);
        inOrderTraversal(node->right);
    }
}

int main() {
    // create an empty tree
    struct Node* root = NULL;
    
    // insert some nodes into the tree
     root = insert(root, 8);
     insert(root, 3);
     insert(root, 10);
     insert(root, 1);
     insert(root, 6);
     insert(root, 14);
     insert(root, 4);
     insert(root, 7);
     insert(root, 13);
     
    // print the tree in order
    printf("The nodes of the tree, displayed in order:\n");
    inOrderTraversal(root);
    
    // search for a specific node
    int target = 7;
    struct Node* result = search(root, target);
    if (result == NULL)
        printf("\n%d was not found in the tree.\n", target);
    else
        printf("\n%d was found in the tree!\n", target);
    
    return 0;
}