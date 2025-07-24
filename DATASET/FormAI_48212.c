//FormAI DATASET v1.0 Category: Binary search trees ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

//Structure definition for Binary Search Tree Node
struct bstnode{
    int data; //Data to be stored in the BST Node
    struct bstnode *left; //Pointer to the left child node
    struct bstnode *right; //Pointer to the right child node
};

//Function to create a new BST Node
struct bstnode *createNode(int x){
    struct bstnode *newNode = (struct bstnode *)malloc(sizeof(struct bstnode)); //Allocate memory for a new BST Node
    newNode->data = x; //Assign a value to the data field of the new node
    newNode->left = NULL; //Initialize left child pointer to NULL
    newNode->right = NULL; //Initialize right child pointer to NULL 
    return newNode; //Return the newly created BST Node
}

//Function to insert a new node in the Binary Search Tree
struct bstnode *insertNode(struct bstnode *root, int x){
    if(root == NULL){ //Check if the root is NULL
        root = createNode(x); //If the root is NULL, create a new BST Node and assign it to the root
    }
    else if(x <= root->data){ //If the data value to be inserted is less than or equal to the data value of the current node
        root->left = insertNode(root->left, x); //Recursively insert the new node in the left subtree of the current node
    }
    else{ //If the data value to be inserted is greater than the data value of the current node
        root->right = insertNode(root->right, x); //Recursively insert the new node in the right subtree of the current node
    }
    return root; //Return the pointer to the root node of the modified BST
}

//Function to perform inorder traversal of the Binary Search Tree
void inorderTraversal(struct bstnode *root){
    if(root != NULL){
        inorderTraversal(root->left); //Recursively traverse the left subtree of the current node
        printf("%d ", root->data); //Print the data value of the current node
        inorderTraversal(root->right); //Recursively traverse the right subtree of the current node
    }
}

//Main function to test the Binary Search Tree implementation
int main(){
    struct bstnode *root = NULL; //Initialize the root pointer to NULL
    int n, x;
    printf("Enter the number of nodes you want to insert: ");
    scanf("%d", &n); //Read the number of new nodes to be inserted
    printf("Enter the data values you want to insert: ");
    for(int i = 0; i < n; i++){
        scanf("%d", &x); //Read the data value of the new node to be inserted
        root = insertNode(root, x); //Insert the new node in the BST
    }
    printf("Inorder Traversal of the Binary Search Tree: ");
    inorderTraversal(root); //Perform inorder traversal of the BST
    printf("\n");
    return 0; //Exit the program
}