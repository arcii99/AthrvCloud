//FormAI DATASET v1.0 Category: Binary search trees ; Style: invasive
#include<stdio.h>
#include<stdlib.h>

//Defining a node structure:
struct node{
    int data;
    struct node *left;
    struct node *right;
};

//Function to create a new node 
struct node* create_node(int data){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

//Function to insert a node into the tree
struct node* insert_node(struct node* root, int data){
    if(root == NULL){
        return create_node(data);
    }
    else if(data < root->data){
        root->left = insert_node(root->left, data);
    }
    else if(data > root->data){
        root->right = insert_node(root->right, data);
    }
    return root;
}

//Function for Inorder traversal
void inorder(struct node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d -> ", root->data);
        inorder(root->right);
    }
}

int main(){
    //Creating a root node
    struct node* root = NULL;

    //Inserting nodes
    root = insert_node(root, 50);
    insert_node(root, 30);
    insert_node(root, 70);
    insert_node(root, 20);
    insert_node(root, 40);
    insert_node(root, 60);
    insert_node(root, 80);

    //Printing Inorder traversal
    printf("Inorder traversal: \n");
    inorder(root);
    return 0;
}