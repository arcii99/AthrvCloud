//FormAI DATASET v1.0 Category: Database Indexing System ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define T 4 // Define the degree of B-tree

typedef struct node {
    int n; // Number of keys in the node
    int keys[2*T-1]; // Array of keys
    struct node *children[2*T]; // Array of child pointers
    int leaf; // 1 if node is leaf, 0 otherwise
} node;

node *root = NULL; // Pointer to the root node

// Function to create a new node
node *create_node() {
    node *new_node = (node*)malloc(sizeof(node));
    new_node->n = 0;
    new_node->leaf = 1;
    return new_node;
}

// Function to split a child node
void split_child(node *parent, int i) {
    node *left_child = parent->children[i];
    node *right_child = create_node();

    right_child->n = T - 1;
    right_child->leaf = left_child->leaf;
    for (int j = 0; j < T - 1; j++) {
        right_child->keys[j] = left_child->keys[j+T];
    }
    if (!left_child->leaf) {
        for (int j = 0; j < T; j++) {
            right_child->children[j] = left_child->children[j+T];
        }
    }

    left_child->n = T - 1;
    for (int j = parent->n - 1; j >= i; j--) {
        parent->children[j+1] = parent->children[j];
    }
    parent->children[i+1] = right_child;
    for (int j = parent->n - 2; j >= i; j--) {
        parent->keys[j+1] = parent->keys[j];
    }
    parent->keys[i] = left_child->keys[T-1];
    parent->n++;
}

// Function to insert a key into a non-full node
void insert_nonfull(node *n, int key) {
    int i = n->n - 1;
    if (n->leaf) {
        while (i >= 0 && key < n->keys[i]) {
            n->keys[i+1] = n->keys[i];
            i--;
        }
        n->keys[i+1] = key;
        n->n++;
    } else {
        while (i >= 0 && key < n->keys[i]) {
            i--;
        }
        i++;
        if (n->children[i]->n == 2*T - 1) {
            split_child(n, i);
            if (key > n->keys[i]) {
                i++;
            }
        }
        insert_nonfull(n->children[i], key);
    }
}

// Function to insert a key into the B-tree
void insert(int key) {
    if (!root) {
        root = create_node();
        root->keys[0] = key;
        root->n = 1;
    } else {
        if (root->n == 2*T - 1) {
            node *new_root = create_node();
            new_root->leaf = 0;
            new_root->children[0] = root;
            split_child(new_root, 0);
            int i = 0;
            if (new_root->keys[0] < key) {
                i++;
            }
            insert_nonfull(new_root->children[i], key);
            root = new_root;
        } else {
            insert_nonfull(root, key);
        }
    }
}

// Function to print the B-tree
void print(node *n, int level) {
    if (n) {
        printf("Level %d: ", level);
        for (int i = 0; i < n->n; i++) {
            printf("%d ", n->keys[i]);
        }
        printf("\n");
        if (!n->leaf) {
            for (int i = 0; i <= n->n; i++) {
                print(n->children[i], level+1);
            }
        }
    }
}

int main() {
    insert(10);
    insert(20);
    insert(5);
    insert(6);
    insert(12);
    insert(30);
    print(root, 0);
    return 0;
}