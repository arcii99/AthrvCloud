//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

// Node of Huffman Tree
struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
};

// Priority Queue
struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode **array;
};

// Create a new Huffman Tree Node
struct MinHeapNode *newNode(char data, unsigned freq) {
    struct MinHeapNode *newNode = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));
    newNode->left = newNode->right = NULL;
    newNode->data = data;
    newNode->freq = freq;
    return newNode;
}

// Create Priority Queue of given capacity
struct MinHeap *createMinHeap(unsigned capacity) {
    struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode **)malloc(minHeap->capacity * sizeof(struct MinHeapNode *));
    return minHeap;
}

// Swap Two MinHeap Nodes
void swapMinHeapNode(struct MinHeapNode **a, struct MinHeapNode **b) {
    struct MinHeapNode *t = *a;
    *a = *b;
    *b = t;
}

// Heapify Function of PriorityQueue
void minHeapify(struct MinHeap *minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Check if size of heap 1 is 1
int isSizeOne(struct MinHeap *minHeap) {
    return (minHeap->size == 1);
}

// Extract the Minimum Node from Heap
struct MinHeapNode *extractMin(struct MinHeap *minHeap) {
    struct MinHeapNode *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Push new node to PriorityQueue
void insertMinHeap(struct MinHeap *minHeap, struct MinHeapNode *minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

// Check if given node is a leaf node
int isLeaf(struct MinHeapNode *root) {
    return !(root->left) && !(root->right);
}

// Create Priority Queue and Insert Given Characters into PriorityQueue
struct MinHeap *createAndBuildMinHeap(char data[], int freq[], int size) {
    struct MinHeap *minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);

    minHeap->size = size;
    for (int i = (minHeap->size - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);

    return minHeap;
}

// Build Huffman Tree and store Huffman codes in the Node of Huffman Tree.
void buildHuffmanTree(char data[], int freq[], int size) {
    struct MinHeapNode *left, *right, *top;
    struct MinHeap *minHeap = createAndBuildMinHeap(data, freq, size);

    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
}

// Print Huffman Codes of each character stored in the Huffman Tree
void printCodes(struct MinHeapNode *root, int arr[], int top) {
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
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// Huffman Coding Implementation
void HuffmanCoding(char data[], int freq[], int size) {
    buildHuffmanTree(data, freq, size);

    struct MinHeapNode *root = extractMin(createAndBuildMinHeap(data, freq, size));

    int arr[MAX_TREE_HT], top = 0;
    printCodes(root, arr, top);
}

// Driver Function
int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e'};
    int freq[] = {3, 6, 9, 12, 15};
    int size = sizeof(data) / sizeof(data[0]);
    printf("Huffman Codes of given characters:\n");
    HuffmanCoding(data, freq, size);
    return 0;
}