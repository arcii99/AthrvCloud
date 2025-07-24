//FormAI DATASET v1.0 Category: Binary search trees ; Style: intelligent
#include<stdio.h>
#include<stdlib.h>

struct node{
    int val;
    struct node* left;
    struct node* right;
};

struct node* newNode(int val){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->val = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node* insert(struct node* root, int val){
    if(root == NULL){
        return newNode(val);
    }
    if(val < root->val){
        root->left = insert(root->left, val);
    }
    else if(val > root->val){
        root->right = insert(root->right, val);
    }
    return root;
}

void inorder(struct node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d ", root->val);
        inorder(root->right);
    }
}

struct node* minValueNode(struct node* node){
    struct node* current = node;
    while(current->left != NULL){
        current = current->left;
    }
    return current;
}

struct node* deleteNode(struct node* root, int val){
    if(root == NULL){
        return root;
    }
    if(val < root->val){
        root->left = deleteNode(root->left, val);
    }
    else if(val > root->val){
        root->right = deleteNode(root->right, val);
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
        root->val = temp->val;
        root->right = deleteNode(root->right, temp->val);
    }
    return root;
}

int main(){
    struct node* root = NULL;
    root = insert(root, 5);
    insert(root, 7);
    insert(root, 3);
    insert(root, 1);
    insert(root, 9);
    printf("Inorder traversal: ");
    inorder(root);
    root = deleteNode(root, 3);
    printf("\nInorder traversal after deletion: ");
    inorder(root);
    return 0;
}