//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: visionary
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_TREE_HT 100

struct MinHeapNode {
    int frequency;
    char value;
    struct MinHeapNode* left, * right;
};

struct MinHeap {
    int size;
    int capacity;
    struct MinHeapNode** array;
};

struct MinHeapNode* newNode(char value, int frequency) {
    struct MinHeapNode* node = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    node->left = node->right = NULL;
    node->value = value;
    node->frequency = frequency;
    return node;
}

struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (struct MinHeapNode**)malloc(capacity * sizeof(struct MinHeapNode*));
    return heap;
}

void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < heap->size && heap->array[left]->frequency < heap->array[smallest]->frequency)
        smallest = left;
    if (right < heap->size && heap->array[right]->frequency < heap->array[smallest]->frequency)
        smallest = right;
    if (smallest != idx) {
        swapMinHeapNode(&heap->array[smallest], &heap->array[idx]);
        minHeapify(heap, smallest);
    }
}

int isSizeOne(struct MinHeap* heap) {
    return heap->size == 1;
}

struct MinHeapNode* extractMin(struct MinHeap* heap) {
    struct MinHeapNode* temp = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    --heap->size;
    minHeapify(heap, 0);

    return temp;
}

void insertMinHeap(struct MinHeap* heap, struct MinHeapNode* node) {
    ++heap->size;
    int i = heap->size - 1;
    while (i && node->frequency < heap->array[(i - 1) / 2]->frequency) {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->array[i] = node;
}

int isLeaf(struct MinHeapNode* root) {
    return !(root->left) && !(root->right);
}

struct MinHeap* createAndBuildMinHeap(char* value, int* frequency, int size) {
    struct MinHeap* heap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        heap->array[i] = newNode(value[i], frequency[i]);
    heap->size = size;
    for (int i = size / 2 - 1; i >= 0; --i)
        minHeapify(heap, i);
    return heap;
}

struct MinHeapNode* buildHuffmanTree(char* value, int* frequency, int size) {
    struct MinHeapNode* left, * right, * top;
    struct MinHeap* heap = createAndBuildMinHeap(value, frequency, size);
    while (!isSizeOne(heap)) {
        left = extractMin(heap);
        right = extractMin(heap);
        top = newNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insertMinHeap(heap, top);
    }
    return extractMin(heap);
}

void printCodes(struct MinHeapNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (isLeaf(root)) {
        printf("%c ", root->value);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

void HuffmanCodes(char* value, int* frequency, int size) {
    struct MinHeapNode* root = buildHuffmanTree(value, frequency, size);
    int arr[MAX_TREE_HT], top = 0;
    printCodes(root, arr, top);
}

int main() {
    char value[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int frequency[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(value) / sizeof(value[0]);
    HuffmanCodes(value, frequency, size);
    return 0;
}