//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_TREE_HT 100

// Huffman tree node
struct MinHeapNode {
    char data;              // Character
    unsigned freq;          // Frequency
    struct MinHeapNode* left;
    struct MinHeapNode* right;
};

// Min heap
struct MinHeap {
    unsigned size; 
    unsigned capacity; 
    struct MinHeapNode** array;
};

// Create new Huffman tree node 
struct MinHeapNode* newNode(char data, unsigned freq)
{
    struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}
   
// Create empty min heap 
struct MinHeap* createMinHeap(unsigned capacity)
{
    struct MinHeap* heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (struct MinHeapNode**)malloc(heap->capacity * sizeof(struct MinHeapNode*));
    return heap;
}

// Swap heap nodes
void swapNodes(struct MinHeapNode** a, struct MinHeapNode** b)
{
    struct MinHeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify subtree
void minHeapify(struct MinHeap* heap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < heap->size && heap->array[left]->freq < heap->array[smallest]->freq)
        smallest = left;
    if (right < heap->size && heap->array[right]->freq < heap->array[smallest]->freq)
        smallest = right;
    if (smallest != idx) {
        swapNodes(&heap->array[smallest], &heap->array[idx]);
        minHeapify(heap, smallest);
    }
}

// Check if size is 1
int isSizeOne(struct MinHeap* heap)
{
    return (heap->size == 1);
}

// Extract minimum from heap
struct MinHeapNode* extractMin(struct MinHeap* heap)
{
    struct MinHeapNode* temp = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    --heap->size;
    minHeapify(heap, 0);
    return temp;
}

// Insert in heap
void insertMinHeap(struct MinHeap* heap, struct MinHeapNode* node)
{
    ++heap->size;
    int i = heap->size - 1;
    while (i && node->freq < heap->array[(i - 1) / 2]->freq) {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->array[i] = node;
}

// Build the Huffman tree
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size)
{
    struct MinHeapNode* left, * right, * top;
    struct MinHeap* heap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        insertMinHeap(heap, newNode(data[i], freq[i]));
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

// Print Huffman codes
void printHuffmanCodes(struct MinHeapNode* root, int arr[], int top)
{
    if (root->left) {
        arr[top] = 0;
        printHuffmanCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printHuffmanCodes(root->right, arr, top + 1);
    }
    if (root->left == NULL && root->right == NULL) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// Huffman coding implementation
void HuffmanCoding(char data[], int freq[], int size)
{
    struct MinHeapNode* root = buildHuffmanTree(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    printHuffmanCodes(root, arr, top);
}

int main()
{
    char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(data) / sizeof(data[0]);
    HuffmanCoding(data, freq, size);
    return 0;
}