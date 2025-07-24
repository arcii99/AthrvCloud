//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define NUM_CHARACTERS 256
#define MAX_BIT_LENGTH 20

// A node in the Huffman tree
struct Node {
    int frequency;
    int character;
    struct Node *leftChild;
    struct Node *rightChild;
};

// Structure to hold the Huffman code for a single character
struct Code {
    int bitLength;
    int bits[MAX_BIT_LENGTH];
};

// Utility function to create a new node for the Huffman tree
struct Node* newNode(int frequency, int character) {
    struct Node *node = (struct Node*) malloc(sizeof(struct Node));
    node->frequency = frequency;
    node->character = character;
    node->leftChild = NULL;
    node->rightChild = NULL;
    return node;
}

// Utility function to swap two nodes
void swap(struct Node **a, struct Node **b) {
    struct Node *temp = *a;
    *a = *b;
    *b = temp;
}

// Heapify down for the Huffman tree
void heapifyDown(struct Node **heap, int size, int index) {
    int leftChildIndex = 2 * index + 1;
    int rightChildIndex = 2 * index + 2;
    int smallestIndex = index;
    if (leftChildIndex < size && heap[leftChildIndex]->frequency < heap[smallestIndex]->frequency) {
        smallestIndex = leftChildIndex;
    }
    if (rightChildIndex < size && heap[rightChildIndex]->frequency < heap[smallestIndex]->frequency) {
        smallestIndex = rightChildIndex;
    }
    if (smallestIndex != index) {
        swap(&heap[index], &heap[smallestIndex]);
        heapifyDown(heap, size, smallestIndex);
    }
}

// Heapify up for the Huffman tree
void heapifyUp(struct Node **heap, int size, int index) {
    int parentIndex = (index - 1) / 2;
    if (parentIndex >= 0 && heap[index]->frequency < heap[parentIndex]->frequency) {
        swap(&heap[index], &heap[parentIndex]);
        heapifyUp(heap, size, parentIndex);
    }
}

// Utility function to build the Huffman tree
struct Node* buildHuffTree(int *frequencies) {
    // Create a min heap of nodes from the character frequencies
    struct Node **heap = (struct Node**) malloc(sizeof(struct Node*) * NUM_CHARACTERS);
    int heapSize = 0;
    for (int i = 0; i < NUM_CHARACTERS; i++) {
        if (frequencies[i] > 0) {
            heap[heapSize] = newNode(frequencies[i], i);
            heapifyUp(heap, heapSize + 1, heapSize);
            heapSize++;
        }
    }

    // Build the Huffman tree from the min heap
    while (heapSize > 1) {
        struct Node* leftChild = heap[0];
        swap(&heap[0], &heap[heapSize - 1]);
        heapSize--;
        heapifyDown(heap, heapSize, 0);
        struct Node* rightChild = heap[0];
        swap(&heap[0], &heap[heapSize - 1]);
        heapSize--;
        heapifyDown(heap, heapSize, 0);
        struct Node* parent = newNode(leftChild->frequency + rightChild->frequency, -1);
        parent->leftChild = leftChild;
        parent->rightChild = rightChild;
        heap[heapSize] = parent;
        heapifyUp(heap, heapSize + 1, heapSize);
        heapSize++;
    }

    struct Node* root = heap[0];
    free(heap);
    return root;
}

// Utility function to traverse the Huffman tree to generate codes
void generateCodes(struct Node *node, struct Code **codes, int bitLength, int *bits) {
    if (node == NULL) {
        return;
    }

    if (node->character != -1) {
        struct Code *code = (struct Code*) malloc(sizeof(struct Code));
        code->bitLength = bitLength;
        for (int i = 0; i < bitLength; i++) {
            code->bits[i] = bits[i];
        }
        codes[node->character] = code;
    }
    else {
        bits[bitLength] = 0;
        generateCodes(node->leftChild, codes, bitLength + 1, bits);
        bits[bitLength] = 1;
        generateCodes(node->rightChild, codes, bitLength + 1, bits);
    }
}

// Utility function to print the Huffman codes for a given message
void printCodes(char *message, struct Code **codes, int messageLength) {
    for (int i = 0; i < messageLength; i++) {
        struct Code *code = codes[message[i]];
        if (code != NULL) {
            printf("Character '%c': ", message[i]);
            for (int j = 0; j < code->bitLength; j++) {
                printf("%d", code->bits[j]);
            }
            printf("\n");
        }
    }
}

int main() {
    // Example message
    char *message = "abbcccddddeeeeeffffff";
    int messageLength = strlen(message);

    // Calculate the character frequencies
    int *frequencies = (int*) calloc(NUM_CHARACTERS, sizeof(int));
    for (int i = 0; i < messageLength; i++) {
        frequencies[message[i]]++;
    }

    // Build the Huffman tree
    struct Node *root = buildHuffTree(frequencies);

    // Generate the Huffman codes
    int bits[MAX_BIT_LENGTH];
    struct Code **codes = (struct Code**) calloc(NUM_CHARACTERS, sizeof(struct Code*));
    generateCodes(root, codes, 0, bits);

    // Print the Huffman codes
    printCodes(message, codes, messageLength);

    // Clean up memory
    free(frequencies);
    free(codes);

    return 0;
}