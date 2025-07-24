//FormAI DATASET v1.0 Category: Image compression ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TREE_HT 100

struct minHeapNode {
    char data;
    unsigned frequency;
    struct minHeapNode *left, *right;
};

struct minHeap {
    unsigned size;
    unsigned capacity;
    struct minHeapNode** array;
};

struct minHeapNode* newNode(char data, unsigned frequency) {
    struct minHeapNode* temp = (struct minHeapNode*)malloc(sizeof(struct minHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->frequency = frequency;
    return temp;
}

struct minHeap* createMinHeap(unsigned capacity) {
    struct minHeap* heap = (struct minHeap*)malloc(sizeof(struct minHeap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (struct minHeapNode**)malloc(heap->capacity * sizeof(struct minHeapNode*));
    return heap;
}

void swapNodes(struct minHeapNode** a, struct minHeapNode** b) {
    struct minHeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(struct minHeap* heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < heap->size && heap->array[left]->frequency < heap->array[smallest]->frequency) {
        smallest = left;
    }
    if (right < heap->size && heap->array[right]->frequency < heap->array[smallest]->frequency) {
        smallest = right;
    }
    if (smallest != index) {
        swapNodes(&heap->array[index], &heap->array[smallest]);
        heapify(heap, smallest);
    }
}

int isSizeOne(struct minHeap* heap) {
    return heap->size == 1;
}

struct minHeapNode* extractMin(struct minHeap* heap) {
    struct minHeapNode* temp = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    --heap->size;
    heapify(heap, 0);
    return temp;
}

void insertMinHeap(struct minHeap* heap, struct minHeapNode* node) {
    ++heap->size;
    int i = heap->size - 1;
    while (i && node->frequency < heap->array[(i - 1) / 2]->frequency) {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->array[i] = node;
}

void buildMinHeap(struct minHeap* heap) {
    int n = heap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; --i) {
        heapify(heap, i);
    }
}

void printArr(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

int isLeaf(struct minHeapNode* root) {
    return !(root->left) && !(root->right);
}

struct minHeapNode* buildHuffmanTree(char data[], int frequency[], int size) {
    struct minHeapNode *left, *right, *top;
    struct minHeap* heap = createMinHeap(size);
    for (int i = 0; i < size; ++i) {
        insertMinHeap(heap, newNode(data[i], frequency[i]));
    }
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

void printCodes(struct minHeapNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (isLeaf(root)) {
        printf("%c: ", root->data);
        printArr(arr, top);
    }
}

void HuffmanCodes(char data[], int frequency[], int size) {
    struct minHeapNode* root = buildHuffmanTree(data, frequency, size);
    int arr[MAX_TREE_HT], top = 0;
    printCodes(root, arr, top);
}

int main() {
    char data[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data)/sizeof(data[0]);
    HuffmanCodes(data, freq, size);
    return 0;
}