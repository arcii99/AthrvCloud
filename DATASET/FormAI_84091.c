//FormAI DATASET v1.0 Category: Data structures visualization ; Style: active
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left;
    struct node *right;
}Node;

void addElement(Node **root, int data) {
    if(*root == NULL) {
        *root = (Node*)malloc(sizeof(Node));
        (*root)->data = data;
        (*root)->left = NULL;
        (*root)->right = NULL;
        printf("Added element: %d\n", data);
    }
    else if(data < (*root)->data) {
        addElement(&((*root)->left), data);
    }
    else {
        addElement(&((*root)->right), data);
    }
}

void printInorder(Node *root) {
    if(root == NULL) {
        return;
    }
    printInorder(root->left);
    printf("%d\n", root->data);
    printInorder(root->right);
}

int main() {
    Node *root = NULL;
    addElement(&root, 50);
    addElement(&root, 30);
    addElement(&root, 70);
    addElement(&root, 20);
    addElement(&root, 40);
    addElement(&root, 60);
    addElement(&root, 80);
    printf("\nInorder traversal of the tree:\n");
    printInorder(root);
    return 0;
}