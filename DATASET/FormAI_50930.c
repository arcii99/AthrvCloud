//FormAI DATASET v1.0 Category: Binary search trees ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(int value) { // Create new node
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = value;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node, int value) { // insert function
    if (node == NULL) 
        return newNode(value);

    if (value < node->data)
        node->left = insert(node->left, value);
    else if (value > node->data)
        node->right = insert(node->right, value);

    return node;
}

struct node* search(struct node* root, int value) { // search function
    if (root == NULL || root->data == value)
        return root;

    if (root->data < value)
        return search(root->right, value);

    return search(root->left, value);
}

void inorder(struct node* node) { //inorder traversing function
    if (node != NULL) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

int main() {
    struct node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal of the given BST: ");
    inorder(root);

    int value = 70;
    struct node* searched_node = search(root, value);
    if(searched_node == NULL)
        printf("\nElement not found");
    else
        printf("\nElement found");

    return 0;
}