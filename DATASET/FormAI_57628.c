//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

// Structure to store a node in Huffman Tree
struct MinHeapNode {
  char data;
  unsigned freq;
  struct MinHeapNode *left, *right;
};

// Structure to create a min heap
struct MinHeap {
  unsigned size;
  unsigned capacity;
  struct MinHeapNode **array;
};

// Function to create a new node
struct MinHeapNode* newNode(char data, unsigned freq) {
  struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
  temp->left = temp->right = NULL;
  temp->data = data;
  temp->freq = freq;
  return temp;
}

// Function to create a min heap
struct MinHeap* createMinHeap(unsigned capacity) {
  struct MinHeap* heap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
  heap->size = 0;
  heap->capacity = capacity;
  heap->array = (struct MinHeapNode**)malloc(heap->capacity * sizeof(struct MinHeapNode*));
  return heap;
}

// Function to swap two nodes in a min heap
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
  struct MinHeapNode* temp = *a;
  *a = *b;
  *b = temp;
}

// Function to heapify a min heap
void minHeapify(struct MinHeap* minHeap, int index) {
  int smallest = index;
  int left = 2 * index + 1;
  int right = 2 * index + 2;
  if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq) smallest = left;
  if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq) smallest = right;
  if (smallest != index) {
    swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[index]);
    minHeapify(minHeap, smallest);
  }
}

// Function to check if a node is leaf node
int isLeaf(struct MinHeapNode* node) {
  return !(node->left) && !(node->right);
}

// Function to create a min heap of given capacity, and populate it
struct MinHeap* populateMinHeap(char* data, unsigned* freq, unsigned size) {
  struct MinHeap* minHeap = createMinHeap(size);
  for (int i = 0; i < size; ++i) minHeap->array[i] = newNode(data[i], freq[i]);
  minHeap->size = size;
  for (int i = (minHeap->size - 1) / 2; i >= 0; --i) minHeapify(minHeap, i);
  return minHeap;
}

// Function to extract minimum node in min heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
  struct MinHeapNode* temp = minHeap->array[0];
  minHeap->array[0] = minHeap->array[minHeap->size - 1];
  --minHeap->size;
  minHeapify(minHeap, 0);
  return temp;
}

// Function to insert new node to the min heap
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
  ++minHeap->size;
  int i = minHeap->size - 1;
  while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
    minHeap->array[i] = minHeap->array[(i - 1) / 2];
    i = (i - 1) / 2;
  }
  minHeap->array[i] = minHeapNode;
}

// Function to build Huffman Tree from min heap
struct MinHeapNode* buildHuffmanTree(char* data, unsigned* freq, unsigned size) {
  struct MinHeapNode *left, *right, *top;
  struct MinHeap* minHeap = populateMinHeap(data, freq, size);
  while (minHeap->size != 1) {
    left = extractMin(minHeap);
    right = extractMin(minHeap);
    top = newNode('$', left->freq + right->freq);
    top->left = left;
    top->right = right;
    insertMinHeap(minHeap, top);
  }
  return extractMin(minHeap);
}

// Function to print Huffman Codes for each character in Huffman Tree
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
    for (int i = 0; i < top; ++i) printf("%d", arr[i]);
    printf("\n");
  }
}

// Main function
int main()
{
  char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
  unsigned freq[] = {5, 9, 12, 13, 16, 45};
  int size = sizeof(data)/sizeof(data[0]);
  struct MinHeapNode* root = buildHuffmanTree(data, freq, size);
  int arr[MAX_TREE_HT], top = 0;
  printCodes(root, arr, top);
  return 0;
}