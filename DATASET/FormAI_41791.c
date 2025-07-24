//FormAI DATASET v1.0 Category: Binary search trees ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

struct node {
    int value;
    struct node* left;
    struct node* right;
};

struct node* create_node(int value){
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

struct node* insert_node(struct node* root, int value){
    if(root == NULL){
        root = create_node(value);
        return root;
    }
    if(value < root->value){
        root->left = insert_node(root->left, value);
    } 
    else if(value > root->value){
        root->right = insert_node(root->right, value);
    }
    return root;
}

void inorder_traversal(struct node* root){
    if(root != NULL){
        inorder_traversal(root->left);
        printf("%d ", root->value);
        inorder_traversal(root->right);
    }
}

int main(){
    struct node* root = NULL;
    root = insert_node(root, 50);
    insert_node(root, 30);
    insert_node(root, 20);
    insert_node(root, 40);
    insert_node(root, 70);
    insert_node(root, 60);
    insert_node(root, 80);
    printf("Inorder Traversal: ");
    inorder_traversal(root);
    return 0;
}