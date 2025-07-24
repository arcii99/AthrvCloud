//FormAI DATASET v1.0 Category: Database Indexing System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define N 4 // Max number of keys in a node

// Struct for a B-tree node
typedef struct BTreeNode {
    int key[N];
    struct BTreeNode *child[N+1];
    int num_keys;
    int is_leaf;
} BTreeNode;

// Search for a key in the B-tree
BTreeNode *search(BTreeNode *root, int key) {
    int i = 0;
    while (i < root->num_keys && key > root->key[i]) {
        i++;
    }
    if (root->key[i] == key) {
        return root;
    }
    if (root->is_leaf) {
        return NULL;
    }
    return search(root->child[i], key);
}

// Insert a key into the B-tree
void insert(BTreeNode **root_ptr, int key) {
    BTreeNode *root = *root_ptr;
    if (root == NULL) {
        root = malloc(sizeof(BTreeNode));
        root->key[0] = key;
        root->num_keys = 1;
        root->is_leaf = 1;
        *root_ptr = root;
        return;
    }
    if (root->num_keys == N) {
        BTreeNode *new_root = malloc(sizeof(BTreeNode));
        new_root->is_leaf = 0;
        new_root->child[0] = root;
        *root_ptr = new_root;
        split(new_root, 0, root);
        insert_nonfull(new_root, key);
    } else {
        insert_nonfull(root, key);
    }
}

// Split a full B-tree node into two
void split(BTreeNode *parent, int i, BTreeNode *child) {
    BTreeNode *new_child = malloc(sizeof(BTreeNode));
    new_child->is_leaf = child->is_leaf;
    new_child->num_keys = N/2;
    for (int j = 0; j < N/2; j++) {
        new_child->key[j] = child->key[j + N/2];
    }
    if (!child->is_leaf) {
        for (int j = 0; j < N/2+1; j++) {
            new_child->child[j] = child->child[j + N/2];
        }
    }
    child->num_keys = N/2;
    for (int j = parent->num_keys; j >= i+1; j--) {
        parent->child[j+1] = parent->child[j];
    }
    parent->child[i+1] = new_child;
    for (int j = parent->num_keys-1; j >= i; j--) {
        parent->key[j+1] = parent->key[j];
    }
    parent->key[i] = child->key[N/2];
    parent->num_keys++;
}

// Insert a key into a non-full B-tree node
void insert_nonfull(BTreeNode *node, int key) {
    int i = node->num_keys - 1;
    if (node->is_leaf) {
        while (i >= 0 && key < node->key[i]) {
            node->key[i+1] = node->key[i];
            i--;
        }
        node->key[i+1] = key;
        node->num_keys++;
    } else {
        while (i >= 0 && key < node->key[i]) {
            i--;
        }
        i++;
        if (node->child[i]->num_keys == N) {
            split(node, i, node->child[i]);
            if (key > node->key[i]) {
                i++;
            }
        }
        insert_nonfull(node->child[i], key);
    }
}

// Print the B-tree
void print_tree(BTreeNode *root) {
    if (root == NULL) {
        return;
    }
    for (int i = 0; i < root->num_keys; i++) {
        printf("%d ", root->key[i]);
    }
    printf("\n");
    if (!root->is_leaf) {
        for (int i = 0; i <= root->num_keys; i++) {
            print_tree(root->child[i]);
        }
    }
}

int main() {
    BTreeNode *root = NULL;
    insert(&root, 3);
    insert(&root, 1);
    insert(&root, 5);
    insert(&root, 2);
    insert(&root, 4);
    printf("B-tree:\n");
    print_tree(root);
    return 0;
}