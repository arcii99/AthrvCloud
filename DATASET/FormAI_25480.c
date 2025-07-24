//FormAI DATASET v1.0 Category: Binary search trees ; Style: active
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
} BSTnode;

BSTnode* createNode(int data){
    BSTnode *newNode = (BSTnode *) malloc(sizeof(BSTnode));
    newNode -> data = data;
    newNode -> left = NULL;
    newNode -> right = NULL;
    return newNode;
}

BSTnode* insertNode(BSTnode *root, int data){
    if(root == NULL){
        root = createNode(data);
        return root;
    }
    if(root -> data > data){
        root -> left = insertNode(root -> left, data);
    }
    else{
        root -> right = insertNode(root -> right, data);
    }
    return root;
}

void preorder(BSTnode *root){
    if(root != NULL){
        printf("%d ", root -> data);
        preorder(root -> left);
        preorder(root -> right);
    }
}

void inorder(BSTnode *root){
    if(root != NULL){
        inorder(root -> left);
        printf("%d ", root -> data);
        inorder(root -> right);
    }
}

void postorder(BSTnode *root){
    if(root != NULL){
        postorder(root -> left);
        postorder(root -> right);
        printf("%d ", root -> data);
    }
}

int main(){
    BSTnode *root = NULL;
    root = insertNode(root, 5);
    insertNode(root, 1);
    insertNode(root, 9);
    insertNode(root, 4);
    insertNode(root, 7);
    insertNode(root, 6);
    insertNode(root, 8);

    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");

    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");

    printf("Postorder Traversal: ");
    postorder(root);
    printf("\n");

    return 0;
}