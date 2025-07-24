//FormAI DATASET v1.0 Category: Binary search trees ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *left;
    struct node *right;
};

struct node* createNode(int value){
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}

struct node* insert(struct node* node, int value){
    if(node == NULL){
        return createNode(value);
    }

    if(value < node->value){
        node->left = insert(node->left, value);
    }
    else{
        node->right = insert(node->right, value);
    }

    return node;
}

struct node* search(struct node* node, int value){
    if(node == NULL || node->value == value){
        return node;
    }

    if(value < node->value){
        return search(node->left, value);
    }
    else{
        return search(node->right, value);
    }
}

void inorder(struct node* node){
    if(node != NULL){
        inorder(node->left);
        printf("%d ", node->value);
        inorder(node->right);
    }
}

int main(){
    printf("Welcome to the Binary Search Tree Program!\n");

    struct node* root = NULL;
    root = insert(root, 10);
    insert(root, 20);
    insert(root, 5);
    insert(root, 15);
    insert(root, 12);
    insert(root, 30);

    printf("The inorder traversal of the tree is: ");
    inorder(root);

    int searchValue = 5;
    struct node* searchResult = search(root, searchValue);

    if(searchResult == NULL){
        printf("\n%d was not found in the tree.\n", searchValue);
    }
    else{
        printf("\n%d was found in the tree.\n", searchValue);
    }

    printf("\nGoodbye!\n");

    return 0;
}