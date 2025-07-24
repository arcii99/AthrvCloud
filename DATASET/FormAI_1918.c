//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#define MAX_TREE_HT 100

// a Huffman tree node
struct minHeapNode {
    char data;
    unsigned freq;
    struct minHeapNode *left, *right;
};

// a min heap of nodes
struct minHeap {
    unsigned size;
    unsigned capacity;
    struct minHeapNode** array;
};

// helper function to create a new min heap node
struct minHeapNode* newMinHeapNode(char data, unsigned freq) {
    struct minHeapNode* temp = (struct minHeapNode*)malloc(sizeof(struct minHeapNode));

    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;

    return temp;
}

// helper function to create a new min heap
struct minHeap* createMinHeap(unsigned capacity) {
    struct minHeap* minHeap = (struct minHeap*)malloc(sizeof(struct minHeap));

    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct minHeapNode**)malloc(minHeap->capacity * sizeof(struct minHeapNode*));

    return minHeap;
}

// swap two min heap nodes
void swapMinHeapNode(struct minHeapNode** a, struct minHeapNode** b) {
    struct minHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// min heapify function
void minHeapify(struct minHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// check if size of heap is 1 or not
int isSizeOne(struct minHeap* minHeap) {
    return (minHeap->size == 1);
}

// function to extract the minimum value node from min heap
struct minHeapNode* extractMin(struct minHeap* minHeap) {
    struct minHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];

    --minHeap->size;
    minHeapify(minHeap, 0);

    return temp;
}

// insert a new node to a min heap
void insertMinHeap(struct minHeap* minHeap, struct minHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = minHeapNode;
}

// build a min heap
void buildMinHeap(struct minHeap* minHeap) {
    int n = minHeap->size - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

// function to check if the given node is a leaf node
int isLeaf(struct minHeapNode* root) {
    return !(root->left) && !(root->right);
}

// creating a min heap of capacity equal to size and inserting all character frequencies
struct minHeap* createAndBuildMinHeap(char* data, int* freq, int size) {
    struct minHeap* minHeap = createMinHeap(size);

    for (int i = 0; i < size; i++) {
        minHeap->array[i] = newMinHeapNode(data[i], freq[i]);
    }

    minHeap->size = size;
    buildMinHeap(minHeap);

    return minHeap;
}

// function to build Huffman Tree
struct minHeapNode* buildHuffmanTree(char* data, int* freq, int size) {
    struct minHeapNode *left, *right, *top;

    // create a min heap of capacity equal to size and insert all the character frequencies
    struct minHeap* minHeap = createAndBuildMinHeap(data, freq, size);

    // iterate until there is only one node left in the heap
    while (!isSizeOne(minHeap)) {
        // extract two minimum frequency items from the heap
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        // create a new internal node with frequency equal to the sum of the two nodes' frequencies
        // make the two extracted node as its left and right children
        top = newMinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    // there is only one node left in the heap which is the root node of the Huffman Tree
    return extractMin(minHeap);
}

// function to print Huffman Codes from the root of the Huffman Tree
void printCodes(struct minHeapNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    // if the node is a leaf node, print the character and its code
    if (isLeaf(root)) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// Huffman Coding Implementation in C
int main() {
    char data[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    int freq[] = { 5, 9, 12, 13, 16, 45 };
    int size = sizeof(data) / sizeof(data[0]);

    struct minHeapNode* root = buildHuffmanTree(data, freq, size);

    int arr[MAX_TREE_HT], top = 0;

    printf("Huffman Codes for the given characters are:\n");
    printCodes(root, arr, top);

    return 0;
}