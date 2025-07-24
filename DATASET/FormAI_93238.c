//FormAI DATASET v1.0 Category: Binary search trees ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node* left;
    struct node* right;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node* insert(Node* root, int value) {
    if(root == NULL) {
        return createNode(value);
    }
    if(value < root->value) {
        root->left = insert(root->left, value);
    }
    else if(value > root->value) {
        root->right = insert(root->right, value);
    }
    return root;
}
void preorder(Node* root) {
    if(root == NULL) {
        return;
    }
    printf("%d ", root->value);
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root) {
    if(root == NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->value);
    inorder(root->right);
}

void postorder(Node* root) {
    if(root == NULL) {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->value);
}

Node* search(Node* root, int value) {
    if(root == NULL || root->value == value) {
        return root;
    }
    if(root->value < value) {
        return search(root->right, value);
    }
    return search(root->left, value);
}

int main() {
    Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal: ");
    inorder(root);

    Node* temp = search(root, 40);
    if(temp == NULL) {
        printf("\n40 not found in the tree");
    }
    else {
        printf("\n40 found in the tree");
    }

    return 0;
}