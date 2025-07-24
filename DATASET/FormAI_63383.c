//FormAI DATASET v1.0 Category: Data structures visualization ; Style: automated
#include<stdio.h>
#include<stdlib.h>

struct node{               
    int data;                    //Data of the node
    struct node *left, *right;  //Left and right pointers for the node
};

typedef struct node Node;

Node *createNode(int data){    //Function to create a new node with the given data
    Node *temp = (Node *)malloc(sizeof(Node));   //Dynamically allocate memory for the node
    temp->data = data;          //Assign the data to the data part of the node
    temp->left = temp->right = NULL;      //Initialize the left and right pointers to NULL
    return temp;               //Return the newly created node
}

void inorder(Node *root){       //Function to do an inorder traversal of the tree
    if(root == NULL)           //If the root node is NULL, return
        return;
    inorder(root->left);       //Traverse the left subtree
    printf("%d ", root->data);  //Print the node value
    inorder(root->right);      //Traverse the right subtree
}

int main(){
    Node *root = createNode(1);           //Create the root node with value 1
    root->left = createNode(2);           //Create a left child with value 2
    root->right = createNode(3);          //Create a right child with value 3
    root->left->left = createNode(4);     //Create a left child of the left child with value 4
    root->left->right = createNode(5);    //Create a right child of the left child with value 5

    printf("Inorder traversal of the binary tree is: ");
    inorder(root);    //Print the inorder traversal of the tree
    printf("\n");
    return 0;
}