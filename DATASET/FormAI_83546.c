//FormAI DATASET v1.0 Category: Binary search trees ; Style: portable
#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int key;
    struct node *left;
    struct node *right;
}node;

node* newNode(int key){
    node* n = (node*) malloc(sizeof(node));
    n->key = key;
    n->left = NULL;
    n->right = NULL;
    return n;
}

node* insert(node *root, int key){
    if(root == NULL){
        return newNode(key);        
    }else if(key < root->key){
        root->left = insert(root->left, key);
    }else{
        root->right = insert(root->right, key);
    }
    return root;
}

void inorderTraversal(node *root){
    if(root == NULL){
        return;
    }
    inorderTraversal(root->left);
    printf("%d ", root->key);
    inorderTraversal(root->right);
}

int main(){
    int arr[7] = {5, 1, 7, 4, 2, 6, 3};
    node *root = NULL;
    int i;
    for(i=0; i<7; i++){
        root = insert(root, arr[i]);
    }
    printf("Inorder traversal: ");
    inorderTraversal(root);
    return 0;
}