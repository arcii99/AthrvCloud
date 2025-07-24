//FormAI DATASET v1.0 Category: Syntax parsing ; Style: unmistakable
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node *create_node(int data) {

    struct node *newnode = (struct node*) malloc(sizeof(struct node));
    newnode->left = NULL;
    newnode->right = NULL;
    newnode->data = data;
    return newnode;
}

void insert_node(struct node **root, int data) {

    if (*root == NULL) {
        *root = create_node(data);
    }
    else if (data < (*root)->data) {
        insert_node(&((*root)->left), data);
    }
    else {
        insert_node(&((*root)->right), data);
    }
}

void inorder_traversal(struct node *root) {

    if (root != NULL) {
        inorder_traversal(root->left);
        printf("%d \n", root->data);
        inorder_traversal(root->right);
    }
}

int main() {

    struct node *root = NULL;

    insert_node(&root, 5);
    insert_node(&root, 1);
    insert_node(&root, 8);
    insert_node(&root, 6);
    insert_node(&root, 3);
    insert_node(&root, 7);
    insert_node(&root, 2);

    printf("Inorder traversal: \n");
    inorder_traversal(root);

    return 0;
}