//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

// A Huffman tree node
struct Node {
    char data;
    unsigned frequency;
    struct Node *left, *right;
};

// A Huffman min heap node
struct MinHeapNode {
    char data;
    unsigned frequency;
    struct MinHeapNode *left, *right;
};

// A Min Heap: Collection of min-heap (or Huffman tree node) pointers
struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode **array;
};

// Create a new Huffman tree node
struct Node* newNode(char data, unsigned frequency) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    node->frequency = frequency;

    return node;
}

// Create a new Huffman tree node from a min heap node
struct Node* newNodeFromMinHeapNode(struct MinHeapNode* minHeapNode) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->left = minHeapNode->left;
    node->right = minHeapNode->right;
    node->data = minHeapNode->data;
    node->frequency = minHeapNode->frequency;

    return node;
}

// Create a new min heap node 
struct MinHeapNode* newMinHeapNode(char data, unsigned frequency) {
    struct MinHeapNode* minHeapNode =
        (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    minHeapNode->left = NULL;
    minHeapNode->right = NULL;
    minHeapNode->data = data;
    minHeapNode->frequency = frequency;

    return minHeapNode;
}

// Swap two min heap nodes
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode *t = *a;
    *a = *b;
    *b = t;
}

// Heapify a min heap
void minHeapify(struct MinHeap* minHeap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency)
        smallest = right;

    if (smallest != index) {
        swapMinHeapNode(&minHeap->array[index], &minHeap->array[smallest]);
        minHeapify(minHeap, smallest);
    }
}

// Check if size of heap is 1
int isSizeOne(struct MinHeap* minHeap) {
    return (minHeap->size == 1);
}

// Extract the min value node from the min heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);

    return temp;
}

// Insert a min heap node to the min heap
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && minHeapNode->frequency < minHeap->array[(i - 1) / 2]->frequency) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = minHeapNode;
}

// Build a min heap
void buildMinHeap(struct MinHeap* minHeap) {
    int n = minHeap->size - 1;

    for (int i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

// Check if the node is a leaf node
int isLeaf(struct Node* root) {
    return !(root->left) && !(root->right);
}

// Create a min heap using the characters in the given string
struct MinHeap* createAndBuildMinHeap(char* data, int* frequency, int size) {
    struct MinHeap* minHeap =
        (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = size;
    minHeap->array =
        (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));

    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newMinHeapNode(data[i], frequency[i]);

    minHeap->size = size;
    buildMinHeap(minHeap);

    return minHeap;
}

// Build a Huffman tree
struct Node* buildHuffmanTree(char* data, int* frequency, int size) {
    struct Node *left, *right, *top;
    struct MinHeap* minHeap = createAndBuildMinHeap(data, frequency, size);

    while (!isSizeOne(minHeap)) {
        left = newNodeFromMinHeapNode(extractMin(minHeap));
        right = newNodeFromMinHeapNode(extractMin(minHeap));
        top = newNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, newMinHeapNode(top->data, top->frequency));
    }

    return newNodeFromMinHeapNode(extractMin(minHeap));
}

// Traverse the Huffman tree and store the Huffman codes in an array
void traverseHuffmanTree(struct Node* root, int arr[], int top, int* code_table[]) {
    if (root->left) {
        arr[top] = 0;
        traverseHuffmanTree(root->left, arr, top + 1, code_table);
    }

    if (root->right) {
        arr[top] = 1;
        traverseHuffmanTree(root->right, arr, top + 1, code_table);
    }

    if (isLeaf(root)) {
        code_table[(int)root->data] = (int*)malloc(sizeof(int) * top);

        for (int i = 0; i < top; ++i) {
            code_table[(int)root->data][i] = arr[i];
        }
    }
}

// Print Huffman codes for each character in the given string
void printHuffmanCodes(char* data, int* frequency, int size) {
    int *arr = (int*)malloc(MAX_TREE_HT * sizeof(int));
    int* code_table[256] = { NULL };
    struct Node* root = buildHuffmanTree(data, frequency, size);

    traverseHuffmanTree(root, arr, 0, code_table);

    for (int i = 0; i < 256; i++) {
        if (code_table[i]) {
            printf("%c: ", i);
            for (int j = 0; j < size; j++) {
                printf("%d", code_table[i][j]);
            }
            printf("\n");
        }
    }
}

// Driver program to test above functions
int main() {
    char text[] = "Huffman coding is a compression algorithm that can be used to compress text files.";
    int* frequency = (int*)calloc(256, sizeof(int));

    for (int i = 0; i < strlen(text); i++) {
        frequency[(int)text[i]]++;
    }

    printHuffmanCodes(text, frequency, strlen(text));
    return 0;
}