//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to hold our tree
typedef struct node {
    char c;
    int freq;
    struct node *left, *right;
} Node;

// Structure to hold our code table
typedef struct code {
    char c;
    char *encoding;
} Code;

// Function to create a new node
Node *newNode(char c, int freq) {
    Node *new = (Node*)malloc(sizeof(Node));
    new->c = c;
    new->freq = freq;
    new->left = new->right = NULL;
    return new;
}

// Function to create a code table entry
Code newCode(char c, char *encoding) {
    Code new;
    new.c = c;
    new.encoding = encoding;
    return new;
}

// Function to free dynamically allocated memory
void freeMemory(Node *root, Code *table, int size) {
    if (root) {
        freeMemory(root->left, table, size);
        freeMemory(root->right, table, size);
        free(root);
    }
    for (int i = 0; i < size; i++) {
        free(table[i].encoding);
    }
}

// Function to swap two nodes
void swapNodes(Node **a, Node **b) {
    Node *temp = *a;
    *a = *b;
    *b = temp;
}

// Function to perform heapify
void heapify(Node **arr, int n, int i) {
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;

    if (l < n && arr[l]->freq > arr[largest]->freq)
        largest = l;

    if (r < n && arr[r]->freq > arr[largest]->freq)
        largest = r;

    if (largest != i) {
        swapNodes(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// Function to create a min heap
void buildHeap(Node **arr, int n) {
    for (int i = n/2 - 1; i >= 0; i--)
        heapify(arr, n, i);
}

// Function to extract the minimum element from the heap
Node *extractMin(Node **arr, int *n) {
    Node *root = arr[0];
    arr[0] = arr[*n-1];
    (*n)--;
    heapify(arr, *n, 0);
    return root;
}

// Function to insert a node into the heap
void insertNode(Node **arr, int *n, Node *new) {
    (*n)++;
    arr[*n-1] = new;

    int i = *n-1;
    while (i > 0 && arr[(i-1)/2]->freq < arr[i]->freq) {
        swapNodes(&arr[(i-1)/2], &arr[i]);
        i = (i-1)/2;
    }
}

// Function to create the Huffman tree
Node *createHuffmanTree(Node **arr, int n) {
    while (n > 1) {
        Node *x = extractMin(arr, &n);
        Node *y = extractMin(arr, &n);

        Node *new = newNode('$', x->freq + y->freq);
        new->left = x;
        new->right = y;

        insertNode(arr, &n, new);
    }

    return extractMin(arr, &n);
}

// Recursive function to build code table
void buildCodeTable(Node *root, Code *table, char *encoding, int len) {
    if (root->left) {
        encoding[len] = '0';
        buildCodeTable(root->left, table, encoding, len+1);
    }
    if (root->right) {
        encoding[len] = '1';
        buildCodeTable(root->right, table, encoding, len+1);
    }
    if (!root->left && !root->right) {
        char c = root->c;
        char *newEncoding = (char*)malloc(len*sizeof(char));
        memcpy(newEncoding, encoding, len*sizeof(char));
        table[c] = newCode(c, newEncoding);
    }
}

// Function to print the code table
void printCodeTable(Code *table, int size) {
    printf("Code Table:\n");
    for (int i = 0; i < size; i++) {
        if (table[i].c) {
            printf("%c: %s\n", table[i].c, table[i].encoding);
        }
    }
}

int main() {
    char str[] = "this is a test string";
    int n = strlen(str);

    Node **arr = (Node**)malloc(n*sizeof(Node*));
    for (int i = 0; i < n; i++)
        arr[i] = newNode(str[i], 1);

    buildHeap(arr, n);
    Node *root = createHuffmanTree(arr, n);

    Code *table = (Code*)malloc(256*sizeof(Code));
    char encoding[n];
    buildCodeTable(root, table, encoding, 0);

    printCodeTable(table, 256);
    freeMemory(root, table, 256);

    return 0;
}