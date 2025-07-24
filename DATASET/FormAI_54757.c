//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 50

// Huffman tree node
struct MinHeapNode
{
    char data;
    unsigned frequency;
    struct MinHeapNode *left, *right;
};

// Min Heap
struct MinHeap
{
    unsigned size;
    unsigned capacity;
    struct MinHeapNode **nodes;
};

// Create a new MinHeap node
struct MinHeapNode* newMinHeapNode(char data, unsigned frequency)
{
    struct MinHeapNode* node = (struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
    node->left = node->right = NULL;
    node->data = data;
    node->frequency = frequency;
    return node;
}

// Create a new MinHeap
struct MinHeap* createMinHeap(unsigned capacity)
{
    struct MinHeap* minHeap = (struct MinHeap*) malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->nodes = (struct MinHeapNode**) malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

// Swap two MinHeap nodes
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b)
{
    struct MinHeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Min Heapify function
void minHeapify(struct MinHeap* minHeap, int index)
{
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < minHeap->size && minHeap->nodes[left]->frequency < minHeap->nodes[smallest]->frequency)
        smallest = left;

    if (right < minHeap->size && minHeap->nodes[right]->frequency < minHeap->nodes[smallest]->frequency)
        smallest = right;

    if (smallest != index) {
        swapMinHeapNode(&minHeap->nodes[smallest], &minHeap->nodes[index]);
        minHeapify(minHeap, smallest);
    }
}

// Check if MinHeap contains only one node
int isSizeOne(struct MinHeap* minHeap)
{
    return (minHeap->size == 1);
}

// Extract the minimum value node from min heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap)
{
    struct MinHeapNode* temp = minHeap->nodes[0];
    minHeap->nodes[0] = minHeap->nodes[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Insert new node into MinHeap
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode)
{
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->frequency < minHeap->nodes[(i - 1) / 2]->frequency) {
        minHeap->nodes[i] = minHeap->nodes[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->nodes[i] = minHeapNode;
}

// Build a MinHeap
void buildMinHeap(struct MinHeap* minHeap)
{
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

// Check if node is a leaf node
int isLeaf(struct MinHeapNode* root)
{
    return !(root->left) && !(root->right);
}

// Create a MinHeap and build it
struct MinHeap* createAndBuildMinHeap(char data[], int frequency[], int size)
{
    struct MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->nodes[i] = newMinHeapNode(data[i], frequency[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

// Build Huffman Tree
struct MinHeapNode* buildHuffmanTree(char data[], int frequency[], int size)
{
    struct MinHeapNode *left, *right, *top;
    struct MinHeap* minHeap = createAndBuildMinHeap(data, frequency, size);
    while (!isSizeOne(minHeap))
    {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newMinHeapNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

// Print Huffman codes from root of a Huffman Tree
void printCodes(struct MinHeapNode* root, int arr[], int top)
{
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (isLeaf(root)) {
        printf("  %c ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// Main function
int main()
{
    char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int frequency[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(data) / sizeof(data[0]);
    struct MinHeapNode* root = buildHuffmanTree(data, frequency, size);
    int arr[MAX_TREE_HT], top = 0;
    printf("Huffman Codes\n");
    printCodes(root, arr, top);
    return 0;
}