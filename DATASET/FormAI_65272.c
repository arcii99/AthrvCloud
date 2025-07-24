//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

struct Node {
    char val;
    unsigned freq;
    struct Node *left, *right;
};

struct Heap {
    unsigned size;
    unsigned capacity;
    struct Node **array;
};

struct Node *newNode(char val, unsigned freq) {
    struct Node *node = (struct Node*) malloc(sizeof(struct Node));
    node->left = node->right = NULL;
    node->val = val;
    node->freq = freq;
    return node;
}

struct Heap *createHeap(unsigned capacity) {
    struct Heap* heap = (struct Heap*) malloc(sizeof(struct Heap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (struct Node**) malloc(heap->capacity * sizeof(struct Node*));
    return heap;
}

void swapNodes(struct Node** a, struct Node** b) {
    struct Node* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct Heap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < heap->size && heap->array[left]->freq < heap->array[smallest]->freq) {
        smallest = left;
    }
    if (right < heap->size && heap->array[right]->freq < heap->array[smallest]->freq) {
        smallest = right;
    }
    if (smallest != idx) {
        swapNodes(&heap->array[smallest], &heap->array[idx]);
        minHeapify(heap, smallest);
    }
}

int isSizeOne(struct Heap* heap) {
    return heap->size == 1;
}

struct Node *extractMin(struct Heap* heap) {
    struct Node* temp = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    --heap->size;
    minHeapify(heap, 0);
    return temp;
}

void insertMinHeap(struct Heap* heap, struct Node* node) {
    ++heap->size;
    int i = heap->size - 1;
    while (i && node->freq < heap->array[(i - 1) / 2]->freq) {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->array[i] = node;
}

void buildHeap(struct Heap* heap) {
    int n = heap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i) {
        minHeapify(heap, i);
    }
}

void printArr(int arr[], int n) {
    int i;
    for (i = 0; i < n; ++i) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

int isLeaf(struct Node* root) {
    return !(root->left) && !(root->right);
}

struct Heap* createAndBuildHeap(char val[], int freq[], int size) {
    struct Heap* heap = createHeap(size);
    for (int i = 0; i < size; ++i) {
        heap->array[i] = newNode(val[i], freq[i]);
    }
    heap->size = size;
    buildHeap(heap);
    return heap;
}

struct Node* buildHuffmanTree(char val[], int freq[], int size) {
    struct Node *left, *right, *top;
    struct Heap* heap = createAndBuildHeap(val, freq, size);
    while (!isSizeOne(heap)) {
        left = extractMin(heap);
        right = extractMin(heap);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(heap, top);
    }
    return extractMin(heap);
}

void printCodes(struct Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (isLeaf(root)) {
        printf("%c: ", root->val);
        printArr(arr, top);
    }
}

void HuffmanCodes(char val[], int freq[], int size) {
    struct Node* root = buildHuffmanTree(val, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    printCodes(root, arr, top);
}

int main() {
    char val[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {15, 9, 12, 23, 3, 5};
    int size = sizeof(val) / sizeof(val[0]);
    HuffmanCodes(val, freq, size);
    return 0;
}