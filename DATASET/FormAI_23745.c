//FormAI DATASET v1.0 Category: Binary search trees ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* left;
    struct node* right;
} Node;

Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insertNode(Node* root, int data)
{
    if (root == NULL)
        return createNode(data);
    else if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);
    return root;
}

void inorderTraversal(Node* root) 
{ 
    if (root != NULL) { 
        inorderTraversal(root->left); 
        printf("%d ", root->data); 
        inorderTraversal(root->right); 
    } 
}

Node* searchNode(Node* root, int data)
{
    if (root == NULL || root->data == data)
        return root;
    if (root->data < data)
        return searchNode(root->right, data);
    return searchNode(root->left, data);
}

int main()
{
    Node* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);
    printf("Inorder Traversal: ");
    inorderTraversal(root);

    int searchData = 40;
    Node* searched = searchNode(root, searchData);
    if (searched != NULL)
        printf("\n%d is found!\n", searchData);
    else
        printf("\n%d is not found!\n", searchData);

    searchData = 100;
    searched = searchNode(root, searchData);
    if (searched != NULL)
        printf("\n%d is found!\n", searchData);
    else
        printf("\n%d is not found!\n", searchData);

    return 0;
}