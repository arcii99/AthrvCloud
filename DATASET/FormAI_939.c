//FormAI DATASET v1.0 Category: Data structures visualization ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node_t {
    int value;
    struct node_t* left;
    struct node_t* right;
} node;

node* create_node(int value) {
    node* new_node = (node*)malloc(sizeof(node));
    new_node->value = value;
    new_node->left = NULL;
    new_node->right = NULL;
    return new_node;
}

void insert_node(node* root, int value) {
    if (root == NULL) {
        return;
    }

    if (value > root->value) {
        if (root->right == NULL) {
            root->right = create_node(value);
        } else {
            insert_node(root->right, value);
        }
    } else {
        if (root->left == NULL) {
            root->left = create_node(value);
        } else {
            insert_node(root->left, value);
        }
    }
}

int max(int a, int b) {
    return a > b ? a : b;
}

int get_height(node* root) {
    if (root == NULL) {
        return 0;
    }

    return max(get_height(root->left), get_height(root->right)) + 1;
}

void print_level(node* root, int level) {
    if (root == NULL || level < 1) {
        printf(" ");
        return;
    }

    if (level == 1) {
        printf("%d", root->value);
    } else {
        print_level(root->left, level - 1);
        print_level(root->right, level - 1);
    }
}

void print_tree(node* root) {
    int height = get_height(root);
    for (int i = 1; i <= height; i++) {
        int spaces = (1 << (height - i)) - 1;
        for (int j = 0; j < spaces; j++) {
            printf(" ");
        }
        print_level(root, i);
        printf("\n");
    }
}

int main() {
    node* root = create_node(8);
    insert_node(root, 4);
    insert_node(root, 12);
    insert_node(root, 2);
    insert_node(root, 6);
    insert_node(root, 10);
    insert_node(root, 14);
    insert_node(root, 1);
    insert_node(root, 3);
    insert_node(root, 5);
    insert_node(root, 7);
    insert_node(root, 9);
    insert_node(root, 11);
    insert_node(root, 13);
    insert_node(root, 15);

    print_tree(root);

    return 0;
}