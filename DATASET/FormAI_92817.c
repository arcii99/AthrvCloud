//FormAI DATASET v1.0 Category: Binary search trees ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int value) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->key = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void insert(struct Node** root, int value) {
    if (*root == NULL) {
        *root = createNode(value);
        return;
    }

    if (value < (*root)->key) {
        insert(&((*root)->left), value);
    } else if (value > (*root)->key) {
        insert(&((*root)->right), value);
    }
}

void inOrderTraversal(struct Node* root) {
    if (root == NULL) {
        return;
    }
    inOrderTraversal(root->left);
    printf("%d ", root->key);
    inOrderTraversal(root->right);
}

int main() {
    struct Node* root = NULL;
    insert(&root, 50);
    insert(&root, 25);
    insert(&root, 75);
    insert(&root, 12);
    insert(&root, 37);
    insert(&root, 62);
    insert(&root, 87);

    printf("Inorder traversal of BST: ");
    inOrderTraversal(root);

    return 0;
}