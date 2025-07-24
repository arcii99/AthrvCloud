//FormAI DATASET v1.0 Category: Binary search trees ; Style: curious
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

// Function to create new node
struct node* createNode(int data){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert node in BST
struct node* insertNode(struct node* root, int data){
    if(root == NULL){
        return createNode(data);
    }
    else if(data < root->data){
        root->left = insertNode(root->left, data);
    }
    else{
        root->right = insertNode(root->right, data);
    }
    return root;
}

// Function to search for a node in BST
struct node* searchNode(struct node* root, int data){
    if(root == NULL || root->data == data){
        return root;
    }
    else if(data < root->data){
        return searchNode(root->left, data);
    }
    else{
        return searchNode(root->right, data);
    }
}

// Function to find minimum value node in a BST
struct node* minValueNode(struct node* node){
    struct node* current = node;
    while(current && current->left != NULL){
        current = current->left;
    }
    return current;
}

// Function to delete a node from BST
struct node* deleteNode(struct node* root, int data){
    if(root == NULL){
        return root;
    }
    else if(data < root->data){
        root->left = deleteNode(root->left, data);
    }
    else if(data > root->data){
        root->right = deleteNode(root->right, data);
    }
    else{
        if(root->left == NULL){
            struct node* temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL){
            struct node* temp = root->left;
            free(root);
            return temp;
        }
        struct node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

// Function to traverse BST in inorder
void inorderTraversal(struct node* root){
    if(root != NULL){
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main(){
    struct node* root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);
    printf("Inorder traversal of the tree: ");
    inorderTraversal(root);
    printf("\n");
    printf("Deleting node 70\n");
    root = deleteNode(root, 70);
    printf("Inorder traversal of the modified tree: ");
    inorderTraversal(root);
    printf("\n");
    return 0;
}