//FormAI DATASET v1.0 Category: Database Indexing System ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the B-tree
typedef struct node {
    int *keys;
    int t;      // Minimum degree
    struct node **children;
    int n;
    int leaf;   // 1 if node is leaf, 0 otherwise
} Node;

// Function to create a new node with minimum degree t and setting
// all keys to 0 and all children to NULL
Node *create_node(int t, int leaf) {
    Node *node = malloc(sizeof(Node));
    node->keys = malloc(sizeof(int) * (2 * t - 1));
    node->children = malloc(sizeof(Node *) * (2 * t));
    node->t = t;
    node->n = 0;
    node->leaf = leaf;
    for (int i = 0; i < 2 * t - 1; i++) {
        node->keys[i] = 0;
    }
    for (int i = 0; i < 2 * t; i++) {
        node->children[i] = NULL;
    }
    return node;
}

// Function to search a key in a B-tree rooted with the given node
Node *search(Node *node, int key) {
    int i = 0;
    while (i < node->n && key > node->keys[i]) {
        i++;
    }
    if (node->keys[i] == key) {
        printf("Key found!\n");
        return node;
    }
    if (node->leaf == 1) {
        printf("Key not found :(\n");
        return NULL;
    }
    return search(node->children[i], key);
}

// Function to split the child y of the given node
void split_child(Node *node, int i, Node *y) {
    Node *z = create_node(y->t, y->leaf);
    z->n = y->t - 1;
    for (int j = 0; j < y->t - 1; j++) {
        z->keys[j] = y->keys[j + y->t];
    }
    if (y->leaf == 0) {
        for (int j = 0; j < y->t; j++) {
            z->children[j] = y->children[j + y->t];
        }
    }
    y->n = y->t - 1;
    for (int j = node->n; j >= i + 1; j--) {
        node->children[j + 1] = node->children[j];
    }
    node->children[i + 1] = z;
    for (int j = node->n - 1; j >= i; j--) {
        node->keys[j + 1] = node->keys[j];
    }
    node->keys[i] = y->keys[y->t - 1];
    node->n++;
}

// Function to insert a key into a B-tree
void insert(Node **root, int key) {
    Node *node = *root;
    if (root == NULL) {
        *root = create_node(3, 1);
        node = *root;
    }
    if (node->n == 2 * node->t - 1) {
        Node *s = create_node(node->t, 0);
        *root = s;
        s->n = 0;
        s->children[0] = node;
        split_child(s, 0, node);
        int i = 0;
        if (s->keys[0] < key) {
            i++;
        }
        insert(&(s->children[i]), key);
    } else {
        int i = node->n - 1;
        if (node->leaf == 1) {
            while (i >= 0 && node->keys[i] > key) {
                node->keys[i + 1] = node->keys[i];
                i--;
            }
            node->keys[i + 1] = key;
            node->n++;
        } else {
            while (i >= 0 && node->keys[i] > key) {
                i--;
            }
            i++;
            if (node->children[i]->n == 2 * node->t - 1) {
                split_child(node, i, node->children[i]);
                if (node->keys[i] < key) {
                    i++;
                }
            }
            insert(&(node->children[i]), key);
        }
    }
}

// Function to print a B-tree in inorder traversal
void traverse(Node *node) {
    if (node != NULL) {
        int i;
        for (i = 0; i < node->n; i++) {
            if (node->leaf == 0) {
                traverse(node->children[i]);
            }
            printf("%d ", node->keys[i]);
            if (node->leaf == 1 && i == node->n - 1) {
                printf("\n");
            }
        }
        if (node->leaf == 0) {
            traverse(node->children[i]);
        }
    }
}

// Main function to test the B-tree implementation
int main() {
    Node *root = NULL;
    insert(&root, 1);
    insert(&root, 5);
    insert(&root, 3);
    insert(&root, 7);
    insert(&root, 2);
    insert(&root, 9);
    printf("Inorder traversal:\n");
    traverse(root);
    search(root, 5);
    search(root, 4);
    return 0;
}