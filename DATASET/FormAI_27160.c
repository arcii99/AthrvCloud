//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: Linus Torvalds
// Huffman coding implementation in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

// structure for Huffman tree node
struct MinHeapNode {
    char data;             // character stored in the node
    unsigned freq;         // frequency of the character
    struct MinHeapNode *left, *right;   // left and right children of the node
};

// structure for the Min Heap
struct MinHeap {
    unsigned size;         // current size of the heap
    unsigned capacity;     // capacity of the heap
    struct MinHeapNode **array;   // array to store the heap nodes
};

// function to create a new Min Heap node
struct MinHeapNode *getMinHeapNode(char data, unsigned freq) {
    struct MinHeapNode *temp = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

// function to create a Min Heap of given capacity
struct MinHeap *createMinHeap(unsigned capacity) {
    struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode **)malloc(minHeap->capacity * sizeof(struct MinHeapNode *));
    return minHeap;
}

// function to swap two Min Heap nodes
void swapMinHeapNode(struct MinHeapNode **a, struct MinHeapNode **b) {
    struct MinHeapNode *t = *a;
    *a = *b;
    *b = t;
}

// minHeapify function
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

// function to check if the given node is a leaf node
int isLeaf(struct MinHeapNode *root) {
    return !(root->left) && !(root->right);
}

// function to create a Min Heap from the given array of frequency
struct MinHeap *buildMinHeap(char data[], unsigned freq[], int size) {
    int i;
    struct MinHeap *minHeap = createMinHeap(size);
    for (i = 0; i < size; ++i)
        minHeap->array[i] = getMinHeapNode(data[i], freq[i]);
    minHeap->size = size;
    for (i = (minHeap->size - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
    return minHeap;
}

// function to extract the minimum node from the heap
struct MinHeapNode *extractMin(struct MinHeap *minHeap) {
    struct MinHeapNode *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// function to insert a node into the heap
void insertMinHeap(struct MinHeap *minHeap, struct MinHeapNode *node) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && node->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = node;
}

// function to build the Huffman tree
struct MinHeapNode *buildHuffmanTree(char data[], unsigned freq[], int size) {
    struct MinHeapNode *left, *right, *top;
    struct MinHeap *minHeap = buildMinHeap(data, freq, size);
    while (minHeap->size != 1) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = getMinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

// function to print the codes of the characters in the Huffman tree
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

// Huffman Coding function
void HuffmanCoding(char data[], unsigned freq[], int size) {
    struct MinHeapNode *root = buildHuffmanTree(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    printCodes(root, arr, top);
}

// driver function
int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    unsigned freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);
    HuffmanCoding(data, freq, size);
    return 0;
}