//FormAI DATASET v1.0 Category: Binary search trees ; Style: invasive
#include<stdio.h>
#include<stdlib.h>

struct node{
    int key;
    struct node *left, *right;
};

struct node *newNode(int item){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

struct node* insert(struct node* node, int key){
    if (node == NULL) 
        return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);
    return node;
}

void printInorder(struct node* node){
    if (node == NULL) 
        return;
    printInorder(node->left);
    printf("%d ", node->key);
    printInorder(node->right);
}

struct node* search(struct node* root, int key){
    if (root == NULL || root->key == key)
        return root;
    if (root->key < key)
        return search(root->right, key);
    return search(root->left, key);
}

int main(){
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);
    printf("Inorder traversal of the binary search tree is: ");
    printInorder(root);
    printf("\n");
    int key = 60;
    struct node *temp = search(root, key);
    printf("Searching for %d in the binary search tree: ", key);
    if (temp != NULL)
        printf("Found!");
    else
        printf("Not found!");
    return 0;
}