//FormAI DATASET v1.0 Category: Data structures visualization ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

typedef struct Node Node;

Node* newNode(int data) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

void printTree(Node* node, char* prefix, char* direction) {
    printf("%s", prefix);
    printf("%s", direction);
    printf(" Node %d\n", node->data);
    if (node->left != NULL) {
        printTree(node->left, strcat(strcat(prefix, "    "), "  |"), "L:");
    }
    if (node->right != NULL) {
        char new_prefix[strlen(prefix) + 4];
        strcat(strcat(new_prefix, prefix), "    ");
        printTree(node->right, strcat(new_prefix, "  |"), "R:");
    }
}

int main() {
    Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);
    printTree(root, "", "");
    return 0;
}