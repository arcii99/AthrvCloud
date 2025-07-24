//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: retro
// Retro Huffman Coding Implementation in C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

// Structure for Huffman tree node
struct HuffmanNode {
    char data;
    unsigned freq;
    struct HuffmanNode *left, *right;
};

// Structure for Huffman tree node heap min priority queue
struct MinHeap {
    unsigned heapSize;
    unsigned capacity;
    struct HuffmanNode** nodes;
};

// Create a Huffman tree node
struct HuffmanNode* newHuffmanNode(char data, unsigned freq) {
    struct HuffmanNode* node = (struct HuffmanNode*) malloc(sizeof(struct HuffmanNode));
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

// Create a min heap of capacity
struct MinHeap* createMinHeap(unsigned capacity) {
    struct MinHeap* minHeap = (struct MinHeap*) malloc(sizeof(struct MinHeap));
    minHeap->heapSize = 0;
    minHeap->capacity = capacity;
    minHeap->nodes = (struct HuffmanNode**) malloc(minHeap->capacity * sizeof(struct HuffmanNode*));
    return minHeap;
}

// Swap two nodes
void swapNodes(struct HuffmanNode** a, struct HuffmanNode** b) {
    struct HuffmanNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Min heapify
void minHeapify(struct MinHeap* minHeap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < minHeap->heapSize && minHeap->nodes[left]->freq < minHeap->nodes[smallest]->freq)
        smallest = left;
    if (right < minHeap->heapSize && minHeap->nodes[right]->freq < minHeap->nodes[smallest]->freq)
        smallest = right;
    if (smallest != index) 
    {
        swapNodes(&minHeap->nodes[smallest], &minHeap->nodes[index]);
        minHeapify(minHeap, smallest);
    }
}

// Check size of heap
int isSizeOne(struct MinHeap* minHeap) {
    return minHeap->heapSize == 1;
}

// Retrieve minimum node from heap
struct HuffmanNode* getMinNode(struct MinHeap* minHeap) {
    struct HuffmanNode* minNode = minHeap->nodes[0];
    minHeap->nodes[0] = minHeap->nodes[minHeap->heapSize - 1];
    --minHeap->heapSize;
    minHeapify(minHeap, 0);
    return minNode;
}

// Insertion of a new Node to MinHeap
void insertMinHeap(struct MinHeap* minHeap, struct HuffmanNode* node) {
    ++minHeap->heapSize;
    int i = minHeap->heapSize - 1;
    while (i && node->freq < minHeap->nodes[(i - 1) / 2]->freq) 
    {
        minHeap->nodes[i] = minHeap->nodes[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->nodes[i] = node;
}

// Check if node's a leaf node
int isLeafNode(struct HuffmanNode* root) {
    return !(root->left) && !(root->right);
}

// Create and build a Huffman tree
struct HuffmanNode* buildHuffmanTree(char data[], int freq[], int size) {
    struct HuffmanNode *node, *leftChild, *rightChild;
    struct MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        insertMinHeap(minHeap, newHuffmanNode(data[i], freq[i]));

    while (!isSizeOne(minHeap)) 
    {
        leftChild = getMinNode(minHeap);
        rightChild = getMinNode(minHeap);

        node = newHuffmanNode('$', leftChild->freq + rightChild->freq);
        node->left = leftChild;
        node->right = rightChild;

        insertMinHeap(minHeap, node);
    }
    return getMinNode(minHeap);
}

// Encode the given Huffman Tree 
void encodeHuffmanTree(struct HuffmanNode* root, int arr[], int top) {
    if (root->left) 
    {
        arr[top] = 0;
        encodeHuffmanTree(root->left, arr, top + 1);
    }

    if (root->right) 
    {
        arr[top] = 1;
        encodeHuffmanTree(root->right, arr, top + 1);
    }

    if (isLeafNode(root)) 
    {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i) 
            printf("%d", arr[i]);
        printf("\n");
    }
}

// Wrapper function for encoding
void HuffmanEncoding(char data[], int freq[], int size) {
    struct HuffmanNode* root = buildHuffmanTree(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    encodeHuffmanTree(root, arr, top);
}

// Main function
int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);
    printf("Character Encoding using Huffman Coding:\n");
    HuffmanEncoding(data, freq, size);
    return 0;
}