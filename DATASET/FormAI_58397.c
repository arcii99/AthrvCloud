//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TREE_HT 100

// Huffman tree node
struct minHeapNode {
    char data;
    unsigned freq;
    struct minHeapNode *left, *right;
};

// Min heap
struct minHeap {
    unsigned size;
    unsigned capacity;
    struct minHeapNode **array;
};

// Node creator
struct minHeapNode* newNode(char data, unsigned freq) {
    struct minHeapNode* temp =
          (struct minHeapNode*) malloc(sizeof(struct minHeapNode));

    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;

    return temp;
}

// heap creator
struct minHeap* createMinHeap(unsigned capacity) {
    struct minHeap* minHeap =
         (struct minHeap*) malloc(sizeof(struct minHeap));

    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array =
         (struct minHeapNode**) malloc(minHeap->capacity * sizeof(struct minHeapNode*));

    return minHeap;
}

// Swap function for the heap
void swapMinHeapNode(struct minHeapNode** a, struct minHeapNode** b) {
    struct minHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Heapify function to put node in the correct position
void minHeapify(struct minHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size &&
        minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size &&
        minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Function to check if the heap is of size 1
bool isSizeOne(struct minHeap* minHeap) {
    return (minHeap->size == 1);
}

// Check if the left or right node of the heap is a leaf node.
bool isLeaf(struct minHeapNode* root) {
    return !(root->left) && !(root->right);
}

// Extract minimum from the heap and reposition it 
struct minHeapNode* extractMin(struct minHeap* minHeap) {
    struct minHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Insert node into the heap
void insertMinHeap(struct minHeap* minHeap, struct minHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1)/2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1)/2];
        i = (i - 1)/2;
    }
    minHeap->array[i] = minHeapNode;
}

// Build huffman tree using the character frequencies to decide tree structure
struct minHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
    struct minHeapNode *left, *right, *top;
    struct minHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        insertMinHeap(minHeap, newNode(data[i], freq[i]));
    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

// Function to print huffman codes from the root of the huffman tree
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
       printf("  %c   | ", root->data);
       for (int i = 0; i < top; ++i)
           printf("%d", arr[i]);
       printf("\n");
   }
}

// Encode the data using the huffman tree built from the character frequency 
void huffmanCodes(char data[], int freq[], int size) {
   struct minHeapNode* root = buildHuffmanTree(data, freq, size);
   int arr[MAX_TREE_HT], top = 0;
   printf("Char | Huffman code\n");
   printf("---- | ------------\n");
   printCodes(root, arr, top);
}

// Main function where the character frequency is manually entered 
int main() {
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {8, 4, 3, 5, 2, 1};
    int size = sizeof(arr)/sizeof(arr[0]);
    huffmanCodes(arr, freq, size);
    return 0;
}