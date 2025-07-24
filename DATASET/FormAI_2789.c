//FormAI DATASET v1.0 Category: Data structures visualization ; Style: Linus Torvalds
#include<stdio.h>
#include<stdlib.h>

struct Node {
    int key;
    struct Node *left, *right;
};

struct Node* newNode(int item) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

struct Node* insert(struct Node* node, int key) {
    if (node == NULL) return newNode(key);

    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    return node;
}

int main() {
    struct Node* root = NULL;
    int values[5] = {6, 4, 8, 2, 5};

    for (int i = 0; i < 5; i++) {
        root = insert(root, values[i]);
        printf("Node %d inserted. Inorder traversal: ", values[i]);
        inorder(root);
        printf("\n");
    }

    return 0;
}