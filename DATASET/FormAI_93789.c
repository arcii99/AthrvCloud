//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

// Huffman tree node
struct MinHeapNode 
{
    char data; // Character
    unsigned freq; // Frequency
    struct MinHeapNode *left, *right;
};

// Min heap 
struct MinHeap 
{
    unsigned size;
    unsigned capacity;
    struct MinHeapNode** arr;
};

// Create new Huffman node
struct MinHeapNode* createNode(char data, unsigned freq)
{
    struct MinHeapNode* node = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;

    return node;
}

// Create min heap
struct MinHeap* createMinHeap(unsigned capacity)
{
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->arr = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));

    return minHeap;
}

// Swap two nodes of min heap
void swapNodes(struct MinHeapNode** a, struct MinHeapNode** b) 
{
    struct MinHeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify min heap
void heapify(struct MinHeap* minHeap, int index) 
{
    int smallest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;

    if (left < minHeap->size && minHeap->arr[left]->freq < minHeap->arr[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->arr[right]->freq < minHeap->arr[smallest]->freq)
        smallest = right;

    if (smallest != index) 
    {
        swapNodes(&minHeap->arr[smallest], &minHeap->arr[index]);
        heapify(minHeap, smallest);
    }
}

// Check if size of heap is 1
int isSizeOne(struct MinHeap* minHeap) 
{
    return (minHeap->size == 1);
}

// Extract minimum value node from heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap) 
{
    struct MinHeapNode* temp = minHeap->arr[0];
    minHeap->arr[0] = minHeap->arr[minHeap->size - 1];
    --minHeap->size;
    heapify(minHeap, 0);
    return temp;
}

// Insert new node into min heap
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) 
{
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->arr[(i - 1)/2]->freq) 
    {
        minHeap->arr[i] = minHeap->arr[(i - 1)/2];
        i = (i - 1)/2;
    }
    minHeap->arr[i] = minHeapNode;
}

// Builds Huffman tree
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) 
{
    struct MinHeapNode *left, *right, *top;
    struct MinHeap* minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i)
        insertMinHeap(minHeap, createNode(data[i], freq[i]));

    while (!isSizeOne(minHeap)) 
    {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = createNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

// Print Huffman codes
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

// Huffman coding implementation
void huffmanCoding(char data[], int freq[], int size) 
{
    struct MinHeapNode* root = buildHuffmanTree(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;

    printCodes(root, arr, top);
}

int main() 
{
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data)/sizeof(data[0]);

    huffmanCoding(data, freq, size);

    return 0;
}