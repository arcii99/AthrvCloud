//FormAI DATASET v1.0 Category: Graph representation ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *left, *right;
};

struct node* newNode(int item) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void printGraph(struct node* root, int space) {
    if (root == NULL)
        return;
    space += 10;
    printGraph(root->right, space);
    printf("\n");
    for (int i = 10; i < space; i++)
        printf(" ");
    printf("%d\n", root->key);
    printGraph(root->left, space);
}

int main() {
    struct node* root = newNode(10);
    root->left = newNode(5);
    root->right = newNode(15);
    root->left->left = newNode(2);
    root->left->right = newNode(6);
    root->right->left = newNode(12);
    root->right->right = newNode(20);
    printf("Graphical representation of a binary tree:\n\n");
    printGraph(root, 0);
    return 0;
}