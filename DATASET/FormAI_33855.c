//FormAI DATASET v1.0 Category: Data structures visualization ; Style: protected
#include <stdio.h>
#include <stdlib.h>

// A structure representing a node in a binary tree
typedef struct Node {
    int value;
    struct Node *left;
    struct Node *right;
} Node;

// A function to create a new node
Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// A function to insert a node into the binary tree
void insert(Node** root, int value) {
    if(*root == NULL) {
        *root = createNode(value);
    }
    else if(value < (*root)->value) {
        insert(&(*root)->left, value);
    }
    else {
        insert(&(*root)->right, value);
    }
}

// A function to print all the nodes in the binary tree using in-order traversal
void printInOrder(Node* root) {
    if(root == NULL) {
        return;
    }
    printInOrder(root->left);
    printf("%d ", root->value);
    printInOrder(root->right);
}

// A function to delete all the nodes in the binary tree
void deleteAllNodes(Node* root) {
    if(root == NULL) {
        return;
    }
    deleteAllNodes(root->left);
    deleteAllNodes(root->right);
    free(root);
}

int main() {
    Node* root = NULL;
    
    // Insert some nodes into the binary tree
    insert(&root, 50);
    insert(&root, 30);
    insert(&root, 20);
    insert(&root, 40);
    insert(&root, 70);
    insert(&root, 60);
    insert(&root, 80);
    
    // Print all the nodes in the binary tree
    printf("In-order traversal of the binary tree: ");
    printInOrder(root);
    printf("\n");
    
    // Delete all the nodes in the binary tree
    deleteAllNodes(root);
    root = NULL;
    
    return 0;
}