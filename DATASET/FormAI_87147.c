//FormAI DATASET v1.0 Category: Database Indexing System ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

struct BTreeNode {
    int *keys;  
    int t;     
    struct BTreeNode **C;
    int n;     
    int leaf;  
};

struct BTreeNode* createNode(int t, int leaf) {
    struct BTreeNode* newNode = (struct BTreeNode*) malloc(sizeof(struct BTreeNode));
    newNode->t = t;
    newNode->leaf = leaf;
    newNode->keys = (int*) malloc(sizeof(int) * (2 * t - 1));
    newNode->C = (struct BTreeNode**) malloc(sizeof(struct BTreeNode*) * (2 * t));
    newNode->n = 0;
    return newNode;
}

void traverse(struct BTreeNode *root) {
    int i;
    for (i = 0; i < root->n; i++) {
        if (!root->leaf) {
            traverse(root->C[i]);
        }
        printf("%d ", root->keys[i]);
    }
    if (!root->leaf) {
        traverse(root->C[i]);
    }
}

void insertNonFull(struct BTreeNode *root, int k) {
    int i = root->n - 1;
    if (root->leaf) {
        while (i >= 0 && root->keys[i] > k) {
            root->keys[i + 1] = root->keys[i];
            i--;
        }
        root->keys[i + 1] = k;
        root->n = root->n + 1;
    } else {
        while (i >= 0 && root->keys[i] > k) {
            i--;
        }
        if (root->C[i + 1]->n == 2 * root->t - 1) {
            splitChild(root, i + 1, root->C[i + 1]);
            if (root->keys[i + 1] < k) {
                i++;
            }
        }
        insertNonFull(root->C[i + 1], k);
    }
}

void splitChild(struct BTreeNode *root, int i, struct BTreeNode *y) {
    struct BTreeNode* z = createNode(y->t, y->leaf);
    z->n = root->t - 1;
    for (int j = 0; j < root->t - 1; j++) {
        z->keys[j] = y->keys[j + root->t];
    }
    if (!y->leaf) {
        for (int j = 0; j < root->t; j++) {
            z->C[j] = y->C[j + root->t];
        }
    }
    y->n = root->t - 1;
    for (int j = root->n; j >= i + 1; j--) {
        root->C[j + 1] = root->C[j];
    }
    root->C[i + 1] = z;
    for (int j = root->n - 1; j >= i; j--) {
        root->keys[j + 1] = root->keys[j];
    }
    root->keys[i] = y->keys[root->t - 1];
    root->n = root->n + 1;
}

void insert(struct BTreeNode **root, int k) {
    if ((*root)->n == 2 * (*root)->t - 1) { 
        struct BTreeNode *s = createNode((*root)->t, 0);
        s->C[0] = *root;
        splitChild(s, 0, *root);
        int i = 0;
        if (s->keys[0] < k) {
            i++;
        }
        insertNonFull(s->C[i], k);
        *root = s;
    } else {
        insertNonFull(*root, k);
    }
}

int main() {
    struct BTreeNode *root = NULL;
    int t, n, temp;
    printf("Enter the order of B-Tree: ");
    scanf("%d", &t);
    root = createNode(t, 1);
    printf("Enter the number of elements to be inserted: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &temp);
        insert(&root, temp);
    }
    printf("The B-Tree is: ");
    traverse(root);
    return 0;
}