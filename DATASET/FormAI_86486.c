//FormAI DATASET v1.0 Category: Binary search trees ; Style: calm
#include<stdio.h>
#include<stdlib.h>

struct node {
    int key;
    struct node *left, *right;
};

struct node *createNode(int item)
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->key = item;
    newNode->left = newNode->right = NULL;
    return newNode;
}

struct node *insert(struct node *node, int key)
{
    if (node == NULL) return createNode(key);

    if (key < node->key)
        node->left  = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

void inorderTraversal(struct node *root)
{
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d \n", root->key);
        inorderTraversal(root->right);
    }
}

int main()
{
    struct node *root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    inorderTraversal(root);
    return 0;
}