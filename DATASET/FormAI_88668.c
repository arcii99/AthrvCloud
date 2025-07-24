//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

// Huffman tree node
struct MinHeapNode 
{
    char data; 
    unsigned freq;
    struct MinHeapNode *left, *right;
};

// Huffman min-heap
struct MinHeap 
{
    unsigned size; 
    unsigned capacity;
    struct MinHeapNode **array; 
};

// Create a new Huffman tree node
struct MinHeapNode* newNode(char data, unsigned freq) 
{
    struct MinHeapNode* node = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

// Create a min heap
struct MinHeap* createMinHeap(unsigned capacity) 
{
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0; 
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

// Swap two nodes of min-heap
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) 
{
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Establish heap property for min-heap node tree
void minHeapify(struct MinHeap* minHeap, int idx) 
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    
    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq) 
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq) 
        smallest = right;

    if (smallest != idx) 
    {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Check if the size of heap is 1, returns true if size is 1
int isSizeOne(struct MinHeap* minHeap) 
{
    return (minHeap->size == 1);
}

// Extract minimum value node from heap 
struct MinHeapNode* extractMin(struct MinHeap* minHeap) 
{
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    return temp;
}

// Insert a new node into the heap
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) 
{
    minHeap->size++;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) 
    {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

// Build a Huffman tree based on characters frequency
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) 
{
    struct MinHeapNode *left, *right, *top;
    struct MinHeap* minHeap = createMinHeap(size);

    // Create min heap containing all nodes
    for (int i = 0; i < size; ++i) 
        minHeap->array[i] = newNode(data[i], freq[i]);

    minHeap->size = size;
    // Establish heap order property
    for (int i = (minHeap->size - 1) / 2; i >= 0; --i) 
        minHeapify(minHeap, i);

    // Build Huffman tree
    while (!isSizeOne(minHeap)) 
    {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    // Root is the Huffman tree
    return extractMin(minHeap);
}

// Print Huffman codes from the root of the Huffman tree
void printCodes(struct MinHeapNode* root, int arr[], int top) 
{  
    if (root->left) 
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) 
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (!root->left && !root->right) 
    {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// Huffman encoding function
void HuffmanCodes(char data[], int freq[], int size) 
{
    struct MinHeapNode* root = buildHuffmanTree(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    printCodes(root, arr, top);
}

// Test main function
int main() 
{
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);
    HuffmanCodes(data, freq, size);
    return 0;
}