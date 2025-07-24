//FormAI DATASET v1.0 Category: Binary search trees ; Style: lively
#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

void insert(struct node** root, int value) {
    if (*root == NULL) {
        *root = (struct node*)malloc(sizeof(struct node));
        (*root)->data = value;
        (*root)->left = NULL;
        (*root)->right = NULL;
    } else {
        if (value <= (*root)->data) {
            insert(&((*root)->left), value);
        } else {
            insert(&((*root)->right), value);
        }
    }
}

void print_in_order(struct node* root) {
    if (root != NULL) {
        print_in_order(root->left);
        printf("%d ", root->data);
        print_in_order(root->right);
    }
}

int main() {
    struct node* root = NULL;

    insert(&root, 5);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 1);
    insert(&root, 9);

    printf("In-order traversal of binary search tree: ");
    print_in_order(root);

    return 0;
}