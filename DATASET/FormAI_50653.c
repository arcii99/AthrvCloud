//FormAI DATASET v1.0 Category: Data structures visualization ; Style: complex
#include <stdio.h>

//define a struct for a binary tree node
typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

//function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//function to insert a node in binary tree
Node* insert(Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    }
    else if (data <= root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}

//function to print the binary tree in inorder traversal
void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}

int main() {
    //create an empty binary tree
    Node* root = NULL;

    //insert nodes in binary tree
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    //print the binary tree in inorder traversal
    printf("Inorder traversal of the binary tree:\n");
    inorder(root);

    return 0;
}