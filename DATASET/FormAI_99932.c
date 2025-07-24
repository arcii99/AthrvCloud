//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

// A Huffman tree node
struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
};

// A Min Heap
struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode** array;
};

// Creating a new Min Heap node
struct MinHeapNode* newMinHeapNode(char data, unsigned freq) {
    struct MinHeapNode* temp = (struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;

    return temp;
}

// Function to swap two nodes of a Min Heap
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Function to create a Min Heap
struct MinHeap* createMinHeap(unsigned capacity) {
    struct MinHeap* minHeap = (struct MinHeap*) malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**) malloc(minHeap->capacity * sizeof(struct MinHeapNode*));

    return minHeap;
}

// Function to bubble up a node
void bubbleUp(struct MinHeap* minHeap, int idx) {
    while (idx && minHeap->array[idx]->freq < minHeap->array[(idx - 1) / 2]->freq) {
        swapMinHeapNode(&minHeap->array[idx], &minHeap->array[(idx - 1) / 2]);
        idx = (idx - 1) / 2;
    }
}

// Function to insert a node into the Min Heap
void insertMinHeapNode(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i > 0 && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

// Function to extract the minimum value node from the Min Heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;

    recursiveBubbleDown(minHeap, 0);

    return temp;
}

// Function to recursively bubble down a node
void recursiveBubbleDown(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int l = 2 * idx + 1;
    int r = 2 * idx + 2;

    if (l < minHeap->size && minHeap->array[l]->freq < minHeap->array[smallest]->freq) {
        smallest = l;
    }

    if (r < minHeap->size && minHeap->array[r]->freq < minHeap->array[smallest]->freq) {
        smallest = r;
    }

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[idx], &minHeap->array[smallest]);
        recursiveBubbleDown(minHeap, smallest);
    }
}

// Function to check if a given node is a leaf node
int isLeaf(struct MinHeapNode* root) {
    return !(root->left) && !(root->right);
}

// Function to create a Min Heap and build a Huffman Tree
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
    struct MinHeapNode *left, *right, *top;
    struct MinHeap* minHeap = createMinHeap(size);

    for (int i = 0; i < size; i++) {
        insertMinHeapNode(minHeap, newMinHeapNode(data[i], freq[i]));
    }

    while (minHeap->size != 1) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = newMinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertMinHeapNode(minHeap, top);
    }

    return extractMin(minHeap);
}

// Function to print Huffman Tree in Preorder traversal
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
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// Huffman Coding implementation
void HuffmanCodes(char data[], int freq[], int size) {
    struct MinHeapNode* root = buildHuffmanTree(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    printCodes(root, arr, top);
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);

    HuffmanCodes(data, freq, size);

    return 0;
}