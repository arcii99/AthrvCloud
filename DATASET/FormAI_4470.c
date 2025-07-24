//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data;
    unsigned freq;
    struct node *left, *right;
} node;

typedef struct heap {
    unsigned size;
    unsigned capacity;
    node **array;
} heap;

node* newnode(char c, unsigned freq) {
    node* temp = (node*) malloc(sizeof(node));
    temp->left = temp->right = NULL;
    temp->data = c;
    temp->freq = freq;
    return temp;
}

heap* createheap(unsigned capacity) {
    heap* h = (heap*) malloc(sizeof(heap));
    h->size = 0;
    h->capacity = capacity;
    h->array = (node**) malloc(h->capacity * sizeof(node*));
    return h;
}

void swapnode(node** n1, node** n2) {
    node* temp = *n1;
    *n1 = *n2;
    *n2 = temp;
}

void minheapify(heap* h, int idx) {
    int smallest = idx, left = 2*idx + 1, right = 2*idx + 2;

    if (left < h->size && h->array[left]->freq < h->array[smallest]->freq)
        smallest = left;
    if (right < h->size && h->array[right]->freq < h->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapnode(&h->array[smallest], &h->array[idx]);
        minheapify(h, smallest);
    }
}

int isheapsizeone(heap* h) {
    return (h->size == 1);
}

node* extractmin(heap* h) {
    node* temp = h->array[0];
    h->array[0] = h->array[h->size - 1];
    --h->size;
    minheapify(h, 0);
    return temp;
}

void minheapinsert(heap* h, node* nod) {
    ++h->size;
    int i = h->size - 1;

    while (i && nod->freq < h->array[(i - 1)/2]->freq) {
        h->array[i] = h->array[(i-1)/2];
        i = (i - 1) / 2;
    }
    h->array[i] = nod;
}

void buildminheap(heap* h) {
    int n = h->size - 1, i;
    for (i = (n - 1) / 2; i >= 0; --i)
        minheapify(h, i);
}

void printarr(int arr[], int n) {
    int i;
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);
    printf("\n");
}

int isleaf(node* n) {
    return !(n->left) && !(n->right);
}

heap* createheapandbuild(unsigned* freq, char* data, int size) {
    heap* h = createheap(size);
    for (int i = 0; i < size; ++i)
        h->array[i] = newnode(data[i], freq[i]);
    h->size = size;
    buildminheap(h);
    return h;
}

node* buildhuffmantree(unsigned* freq, char* data, int size) {
    node *left, *right, *top;
    heap* h = createheapandbuild(freq, data, size);

    while (!isheapsizeone(h)) {
        left = extractmin(h);
        right = extractmin(h);
        top = newnode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;
        minheapinsert(h, top);
    }
    return extractmin(h);
}

void encodehuffmantree(node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        encodehuffmantree(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        encodehuffmantree(root->right, arr, top + 1);
    }
    if (isleaf(root)) {
        printf("%c: ", root->data);
        printarr(arr, top);
    }
}

void getcodes(unsigned* freq, char* data, int size) {
    node* root = buildhuffmantree(freq, data, size);
    int arr[100], top = 0;
    encodehuffmantree(root, arr, top);
}

int main() {
    char data[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);
    getcodes(freq, data, size);
    return 0;
}