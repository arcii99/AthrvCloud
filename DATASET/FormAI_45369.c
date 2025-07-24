//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 50

struct tNode {
    char ch;
    int freq;
    struct tNode *left;
    struct tNode *right;
};

struct minHeap {
    int size;
    int capacity;
    struct tNode **array;
};

struct tNode *createNode(char ch, int freq) {
    struct tNode *node = (struct tNode *)malloc(sizeof(struct tNode));
    node->ch = ch;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct minHeap *createMinHeap(int capacity) {
    struct minHeap *heap = (struct minHeap *)malloc(sizeof(struct minHeap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (struct tNode **)malloc(heap->capacity * sizeof(struct tNode *));
    return heap;
}

void swap(struct tNode **a, struct tNode **b) {
    struct tNode *t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct minHeap *heap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < heap->size && heap->array[left]->freq < heap->array[smallest]->freq)
        smallest = left;
    if (right < heap->size && heap->array[right]->freq < heap->array[smallest]->freq)
        smallest = right;
    if (smallest != idx) {
        swap(&heap->array[smallest], &heap->array[idx]);
        minHeapify(heap, smallest);
    }
}

int isSizeOne(struct minHeap *heap) {
    return heap->size == 1;
}

struct tNode *extractMin(struct minHeap *heap) {
    struct tNode *temp = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    --heap->size;
    minHeapify(heap, 0);
    return temp;
}

void insertMinHeap(struct minHeap *heap, struct tNode *node) {
    ++heap->size;
    int i = heap->size - 1;
    while (i && node->freq < heap->array[(i - 1) / 2]->freq) {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->array[i] = node;
}

void buildMinHeap(struct minHeap *heap) {
    int n = heap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(heap, i);
}

void printArr(int arr[], int n) {
    int i;
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);
    printf("\n");
}

int isLeaf(struct tNode *root) {
    return !(root->left) && !(root->right);
}

struct minHeap *createAndBuildMinHeap(char ch[], int freq[], int size) {
    struct minHeap *heap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        heap->array[i] = createNode(ch[i], freq[i]);
    heap->size = size;
    buildMinHeap(heap);
    return heap;
}

struct tNode *buildHuffmanTree(char ch[], int freq[], int size) {
    struct tNode *left, *right, *top;
    struct minHeap *heap = createAndBuildMinHeap(ch, freq, size);
    while (!isSizeOne(heap)) {
        left = extractMin(heap);
        right = extractMin(heap);
        top = createNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(heap, top);
    }
    return extractMin(heap);
}

void printCodes(struct tNode *root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (isLeaf(root)) {
        printf("%c: ", root->ch);
        printArr(arr, top);
    }
}

void HuffmanCoding(char ch[], int freq[], int size) {
    struct tNode *root = buildHuffmanTree(ch, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    printCodes(root, arr, top);
}

int main() {
    char ch[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(ch) / sizeof(ch[0]);
    HuffmanCoding(ch, freq, size);
    return 0;
}