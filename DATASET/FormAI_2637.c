//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for a Huffman tree node
struct HuffmanNode {
    char data;        // Data to be stored in the node
    int frequency;    // Frequency of the character in the input string
    struct HuffmanNode *left, *right;   // Left and right child nodes
};

// Define a structure for a min-heap node
struct MinHeapNode {
    struct HuffmanNode* data;
    int frequency;
};

// Define a structure for a min-heap
struct MinHeap {
    int size;
    int capacity;
    struct MinHeapNode* array;
};

// Function to create a new Huffman tree node
struct HuffmanNode* newHuffmanNode(char data, int frequency) {
    struct HuffmanNode* node = (struct HuffmanNode*) malloc(sizeof(struct HuffmanNode));
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    node->frequency = frequency;
    return node;
}

// Function to create a new min-heap node
struct MinHeapNode* newMinHeapNode(struct HuffmanNode* node, int frequency) {
    struct MinHeapNode* minHeapNode = (struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
    minHeapNode->data = node;
    minHeapNode->frequency = frequency;
    return minHeapNode;
}

// Function to swap nodes in min-heap
void swapMinHeapNode(struct MinHeapNode** node1, struct MinHeapNode** node2) {
    struct MinHeapNode* temp = *node1;
    *node1 = *node2;
    *node2 = temp;
}

// Build min-heap from the given array of nodes
void buildMinHeap(struct MinHeap* minHeap) {
    int i = (minHeap->size - 1) / 2;
    while (i >= 0) {
        minHeapify(minHeap, i);
        i--;
    }
}

// Function to find the parent node of a given node
int parent(int i) {
    return (i - 1) / 2;
}

// Function to find the left child node of a given node
int leftChild(int i) {
    return (2 * i) + 1;
}

// Function to find the right child node of a given node
int rightChild(int i) {
    return (2 * i) + 2;
}

// Function to min-heapify the heap rooted at i
void minHeapify(struct MinHeap* minHeap, int i) {
    int smallest = i;
    int left = leftChild(i);
    int right = rightChild(i);
    if (left < minHeap->size && minHeap->array[left].frequency < minHeap->array[smallest].frequency) {
        smallest = left;
    }
    if (right < minHeap->size && minHeap->array[right].frequency < minHeap->array[smallest].frequency) {
        smallest = right;
    }
    if (smallest != i) {
        swapMinHeapNode(&minHeap->array[i], &minHeap->array[smallest]);
        minHeapify(minHeap, smallest);
    }
}

// Function to determine if the given node is a leaf node
int isLeaf(struct HuffmanNode* node) {
    return !(node->left) && !(node->right);
}

// Function to create a min-heap for the given array of nodes
struct MinHeap* createMinHeap(struct HuffmanNode** nodes, int size) {
    struct MinHeap* minHeap = (struct MinHeap*) malloc(sizeof(struct MinHeap));
    minHeap->size = size;
    minHeap->capacity = size;
    minHeap->array = (struct MinHeapNode*) malloc(minHeap->capacity * sizeof(struct MinHeapNode));
    for (int i = 0; i < size; i++) {
        minHeap->array[i] = *newMinHeapNode(nodes[i], nodes[i]->frequency);
    }
    buildMinHeap(minHeap);
    return minHeap;
}

// Function to extract the node with minimum frequency from the min-heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    struct MinHeapNode* minNode = (struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
    minNode = &minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return minNode;
}

// Function to insert a node into the given min-heap
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->frequency < minHeap->array[parent(i)].frequency) {
        minHeap->array[i] = minHeap->array[parent(i)];
        i = parent(i);
    }
    minHeap->array[i] = *minHeapNode;
}

// Function to build the Huffman tree
struct HuffmanNode* buildHuffmanTree(char data[], int frequency[], int size) {
    struct HuffmanNode *left, *right, *top;
    struct HuffmanNode* nodes[size];
    for (int i = 0; i < size; i++) {
        nodes[i] = newHuffmanNode(data[i], frequency[i]);
    }
    struct MinHeap* minHeap = createMinHeap(nodes, size);
    while (minHeap->size != 1) {
        // Extract the two nodes with minimum frequency
        left = extractMin(minHeap)->data;
        right = extractMin(minHeap)->data;

        // Create a new internal node with sum of the two nodes' frequencies
        top = newHuffmanNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;

        // Insert the new internal node into the min-heap
        insertMinHeap(minHeap, newMinHeapNode(top, top->frequency));
    }
    return extractMin(minHeap)->data;
}

// Function to print the codes for the characters in the Huffman tree
void printCodes(struct HuffmanNode* root, int arr[], int top) {
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
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frequency[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);

    struct HuffmanNode* root = buildHuffmanTree(data, frequency, size);
    int arr[100], top = 0;
    printf("Huffman Codes: \n");
    printCodes(root, arr, top);

    return 0;
}