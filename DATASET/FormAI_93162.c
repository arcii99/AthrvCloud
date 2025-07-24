//FormAI DATASET v1.0 Category: Data mining ; Style: recursive
#include<stdio.h>

struct node { //Creating a structure to define a node in binary tree
    int data;
    struct node *left, *right;
};

struct node* newNode(int data){ // function to create a new node
    struct node* node = (struct node*)
        malloc(sizeof(struct node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;

    return(node);
}

void postorder(struct node* root){ //Function for postorder traversal of binary tree
    if(root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main(){
    struct node *root = newNode(1); //creating a binary tree
    root->left  = newNode(2);
    root->right  = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->right->left = newNode(6);
    root->left->right->right = newNode(7);
    root->left->left->left = newNode(8);

    printf("\nPostorder traversal of binary tree is: ");
    postorder(root); //calling postorder function to traverse the binary tree
    return 0;
}