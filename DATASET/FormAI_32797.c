//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: peaceful
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

// A Min Heap: Collection of min-heap (or Huffman tree) nodes
struct MinHeap {
  unsigned size;
  unsigned capacity;
  struct MinHeapNode** array;
};

// Create a new Huffman Tree node
struct MinHeapNode* newNode(char data, unsigned freq) {
  struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
  temp->left = temp->right = NULL;
  temp->data = data;
  temp->freq = freq;
  return temp;
}

// Create a new Min Heap node
struct MinHeap* createMinHeap(unsigned capacity) {
  struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
  minHeap->size = 0;
  minHeap->capacity = capacity;
  minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
  return minHeap;
}

// Swap the nodes
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
  struct MinHeapNode* t = *a;
  *a = *b;
  *b = t;
}

// Heapify the given subtree
void minHeapify(struct MinHeap* minHeap, int idx) {
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

// Check the size of the Min Heap (should be 1)
int isSizeOne(struct MinHeap* minHeap) {
  return (minHeap->size == 1);
}

// Extract the node with the smallest frequency
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
  struct MinHeapNode* temp = minHeap->array[0];
  minHeap->array[0] = minHeap->array[minHeap->size - 1];
  --minHeap->size;
  minHeapify(minHeap, 0);
  return temp;
}

// Insert a node
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
  ++minHeap->size;
  int i = minHeap->size - 1;
  
  while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
    minHeap->array[i] = minHeap->array[(i - 1) / 2];
    i = (i - 1) / 2;
  }
  
  minHeap->array[i] = minHeapNode;
}

// Generate Huffman Tree
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
  struct MinHeapNode *left, *right, *top;
  struct MinHeap *minHeap = createMinHeap(size);
  
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

// Print Huffman Codes
void printCodes(struct MinHeapNode* root, int arr[], int top) {
  if (root->left) {
    arr[top] = 0;
    printCodes(root->left, arr, top + 1);
  }

  if (root->right) {
    arr[top] = 1;
    printCodes(root->right, arr, top + 1);
  }

  if (!root->left && !root->right) {
    printf("%c: ", root->data);
    for (int i = 0; i < top; ++i)
      printf("%d", arr[i]);
    printf("\n");
  }
}

// Huffman Code Driver Function
void HuffmanCode(char data[], int freq[], int size) {
  struct MinHeapNode* root = buildHuffmanTree(data, freq, size);
  int arr[MAX_TREE_HT], top = 0;
  printCodes(root, arr, top);
}

int main() {
  char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
  int freq[] = {5, 9, 12, 13, 16, 45};
  int size = sizeof(data) / sizeof(data[0]);
  HuffmanCode(data, freq, size);
  return 0;
}