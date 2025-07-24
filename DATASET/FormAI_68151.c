//FormAI DATASET v1.0 Category: Binary search trees ; Style: complete
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *newNode(int item){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct Node *insertNode(struct Node *root, int data){
    if (root == NULL) return newNode(data);
    if (data < root->data)
        root->left = insertNode(root->left, data);
    else if (data > root->data)
        root->right = insertNode(root->right, data);
    return root;
}

void inorderTraversal(struct Node *root){
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d \n", root->data);
        inorderTraversal(root->right);
    }
}

struct Node *findMinimumValue(struct Node *node){
    struct Node *current = node;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Node *deleteNode(struct Node *root, int data){
    if (root == NULL) return root;
    if (data < root->data)
        root->left = deleteNode(root->left, data);
    else if (data > root->data)
        root->right = deleteNode(root->right, data);
    else {
        if (root->left == NULL){
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL){
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        struct Node *temp = findMinimumValue(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main(){
    struct Node *root = NULL;
    root = insertNode(root, 50);
    insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 40);
    insertNode(root, 70);
    insertNode(root, 60);
    insertNode(root, 80);

    printf("Binary Search Tree (Inorder Traversal): \n");
    inorderTraversal(root);

    printf("\nDelete 20\n");
    root = deleteNode(root, 20);
    printf("Binary Search Tree (Inorder Traversal) after deletion: \n");
    inorderTraversal(root);

    printf("\nDelete 30\n");
    root = deleteNode(root, 30);
    printf("Binary Search Tree (Inorder Traversal) after deletion: \n"); 
    inorderTraversal(root);

    printf("\nDelete 50\n");
    root = deleteNode(root, 50);
    printf("Binary Search Tree (Inorder Traversal) after deletion: \n"); 
    inorderTraversal(root);

    return 0;
}