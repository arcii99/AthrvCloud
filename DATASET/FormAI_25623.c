//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_TREE_HT 100

// Struct for Huffman Tree
struct MinHeapNode {
  char data;
  unsigned freq;
  struct MinHeapNode *left, *right;
};

// Struct for Min Heap
struct MinHeap {
  unsigned size;
  unsigned capacity;
  struct MinHeapNode **array;
};

// Create a New Min Heap Node
struct MinHeapNode* newNode(char data, unsigned freq) {
  struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));

  temp->left = temp->right = NULL;
  temp->data = data;
  temp->freq = freq;

  return temp;
}

// Create a new Min Heap
struct MinHeap* createMinHeap(unsigned capacity) {
  struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
  minHeap->size = 0;
  minHeap->capacity = capacity;
  minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));

  return minHeap;
}

// Swap function for Heapify
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
  struct MinHeapNode* t = *a;
  *a = *b;
  *b = t;
}

// Heapify Function to Maintain the Heap Property
void minHeapify(struct MinHeap* minHeap, int idx) {
  int smallest = idx;
  int left = 2 * idx + 1;
  int right = 2 * idx + 2;

  if(left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq) {
    smallest = left;
  }

  if(right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq) {
    smallest = right;
  }

  if(smallest != idx) {
    swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
    minHeapify(minHeap, smallest);
  }
}

// Function to check if size of Heap is 1
int isSizeOne(struct MinHeap* minHeap) {
  return (minHeap->size == 1);
}

// Extract the Min Node from the Heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
  struct MinHeapNode* temp = minHeap->array[0];
  minHeap->array[0] = minHeap->array[minHeap->size - 1];

  --minHeap->size;
  minHeapify(minHeap, 0);

  return temp;
}

// Insert a new Node in Heap
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
  ++minHeap->size;
  int i = minHeap->size - 1;
  
  while(i && minHeapNode->freq < minHeap->array[(i-1)/2]->freq) {
    minHeap->array[i] = minHeap->array[(i-1)/2];
    i = (i-1)/2;
  }

  minHeap->array[i] = minHeapNode;
}

// Check if it is a leaf node
int isLeaf(struct MinHeapNode* root) {
  return !(root->left) && !(root->right);
}

// Print the Array with Codes
void printArr(int arr[], int n) {
  for(int i = 0; i < n; ++i) {
    printf("%d", arr[i]);
  }
  printf("\n");
}

// Build Huffman Tree with Frequency and Size of Min Heap
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
  struct MinHeapNode *left, *right, *top;

  // Create Min Heap with Capacity Number of Size
  struct MinHeap* minHeap = createMinHeap(size);

  // Add Nodes to Min Heap by Looping Through Size
  for(int i = 0; i < size; ++i) {
    minHeap->array[i] = newNode(data[i], freq[i]);
  }

  // Set Size of Min Heap to Capacity
  minHeap->size = size;

  // Heapify it to Build the New Heap
  // Continue until Size is 1
  while(!isSizeOne(minHeap)) {
    left = extractMin(minHeap);
    right = extractMin(minHeap);

    top = newNode('$', left->freq + right->freq);
    top->left = left;
    top->right = right;

    insertMinHeap(minHeap, top);
  }

  return extractMin(minHeap);
}

// Print Codes in Huffman Tree
void printCodes(struct MinHeapNode* root, int arr[], int top) {
  // If left side of tree, append 0
  if(root->left) {
    arr[top] = 0;
    printCodes(root->left, arr, top + 1);
  }

  // If right side of tree, append 1
  if(root->right) {
    arr[top] = 1;
    printCodes(root->right, arr, top + 1);
  }

  // When you reach leaf node, print the code
  if(isLeaf(root)) {
    printf("%c: ", root->data);
    printArr(arr, top);
  }
}

// Huffman Encoding Function
void HuffmanCodes(char data[], int freq[], int size) {
  struct MinHeapNode* root = buildHuffmanTree(data, freq, size);

  // Creating an Array to Store Huffman Code
  int arr[MAX_TREE_HT], top = 0;

  printCodes(root, arr, top);
}

int main() {
  char arr[] = {'A', 'B', 'C', 'D', 'E', 'F'};
  int freq[] = {5, 9, 12, 13, 16, 45};
  int size = sizeof(arr)/sizeof(arr[0]);

  HuffmanCodes(arr, freq, size);

  return 0;
}