//FormAI DATASET v1.0 Category: Binary search trees ; Style: mathematical
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert(struct Node* node, int data){
    if(node == NULL){
        return newNode(data);
    }
    if(data < node->data){
        node->left = insert(node->left, data);
    }
    else if(data > node->data){
        node->right = insert(node->right, data);
    }
    return node;
}

struct Node* search(struct Node* root, int data){
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

void inorder(struct Node* root){
    if(root != NULL){
        inorder(root->left);
        printf("%d -> ", root->data);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 20);
    insert(root, 70);
    insert(root, 10);
    insert(root, 30);
    insert(root, 60);
    
    printf("Inorder traversal of the BST: ");
    inorder(root);
    
    printf("\nEnter a number to search in the BST: ");
    int num;
    scanf("%d", &num);
    
    struct Node* result = search(root, num);
    if(result == NULL){
        printf("Number %d not found in the BST.\n", num);
    }
    else{
        printf("Number %d found in the BST.\n", num);
    }
    
    return 0;
}