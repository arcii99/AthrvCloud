//FormAI DATASET v1.0 Category: Binary search trees ; Style: multivariable
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

// function to create a new node
struct node* createNode(int data){
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// function to insert a node in BST
struct node* insert(struct node* root, int data){
    if(root == NULL){
        return createNode(data);
    }
    if(data < root->data){
        root->left = insert(root->left, data);
    }
    else if(data > root->data){
        root->right = insert(root->right, data);
    }
    return root;
}

// function to search a node in BST
struct node* search(struct node* root, int data){
    if(root == NULL || root->data == data){
        return root;
    }
    if(data < root->data){
        return search(root->left, data);
    }
    else{
        return search(root->right, data);
    }
}

// function to traverse BST in inorder
void inorder(struct node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main(){
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("Inorder traversal of BST: ");
    inorder(root);
    printf("\n");
    int searchElement = 40;
    struct node* searchResult = search(root, searchElement);
    if(searchResult == NULL){
        printf("%d not found in BST\n", searchElement);
    }
    else{
        printf("%d found in BST\n", searchElement);
    }
    return 0;
}