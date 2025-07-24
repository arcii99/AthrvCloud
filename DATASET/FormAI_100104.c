//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

// Structure to store Huffman tree node
struct HuffmanNode {
    char data;
    unsigned int freq;
    struct HuffmanNode *left, *right;
};

// Structure to store Huffman codes
struct HuffmanCode {
    char data;
    char *code;
};

// Structure to store frequency of characters
struct Frequency {
    char data;
    unsigned int freq;
};

// Function to create a new Huffman tree node
struct HuffmanNode* createHuffmanNode(char data, unsigned int freq) {
    struct HuffmanNode* node = (struct HuffmanNode*) malloc(sizeof(struct HuffmanNode));
    node->data = data;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Function to create a priority queue with minimum heap property
struct PriorityQueue {
    unsigned int size;
    unsigned int capacity;
    struct HuffmanNode** heap;
};

// Function to create a new priority queue node
struct PriorityQueue* createPriorityQueue(unsigned int capacity) {
    struct PriorityQueue* priorityQueue = (struct PriorityQueue*) malloc(sizeof(struct PriorityQueue));
    priorityQueue->size = 0;
    priorityQueue->capacity = capacity;
    priorityQueue->heap = (struct HuffmanNode**) malloc(sizeof(struct HuffmanNode*) * capacity);
    return priorityQueue;
}

// Function to swap two Huffman nodes
void swapHuffmanNodes(struct HuffmanNode** a, struct HuffmanNode** b) {
    struct HuffmanNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Function to heapify a subtree of heap
void heapify(struct PriorityQueue* priorityQueue, int index) {
    int smallest = index;
    int leftChild = 2 * index + 1;
    int rightChild = 2 * index + 2;

    if (leftChild < priorityQueue->size && priorityQueue->heap[leftChild]->freq < priorityQueue->heap[smallest]->freq) smallest = leftChild;

    if (rightChild < priorityQueue->size && priorityQueue->heap[rightChild]->freq < priorityQueue->heap[smallest]->freq) smallest = rightChild;

    if (smallest != index) {
        swapHuffmanNodes(&priorityQueue->heap[smallest], &priorityQueue->heap[index]);
        heapify(priorityQueue, smallest);
    }
}

// Function to check if the priority queue has only one node
int isSizeOne(struct PriorityQueue* priorityQueue) {
    return priorityQueue->size == 1;
}

// Function to extract minimum value node from priority queue
struct HuffmanNode* extractMinimum(struct PriorityQueue* priorityQueue) {
    struct HuffmanNode* minimum = priorityQueue->heap[0];
    priorityQueue->heap[0] = priorityQueue->heap[priorityQueue->size - 1];
    --priorityQueue->size;
    heapify(priorityQueue, 0);
    return minimum;
}

// Function to insert a new node to priority queue
void insertToPriorityQueue(struct PriorityQueue* priorityQueue, struct HuffmanNode* node) {
    ++priorityQueue->size;
    int i = priorityQueue->size - 1;

    while (i && node->freq < priorityQueue->heap[(i - 1) / 2]->freq) {
        priorityQueue->heap[i] = priorityQueue->heap[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    priorityQueue->heap[i] = node;
}

// Function to build the Huffman tree
struct HuffmanNode* buildHuffmanTree(struct Frequency freq[], unsigned int size) {
    struct HuffmanNode *left, *right, *top;
    struct PriorityQueue* priorityQueue = createPriorityQueue(size);

    for (int i = 0; i < size; ++i) {
        insertToPriorityQueue(priorityQueue, createHuffmanNode(freq[i].data, freq[i].freq));
    }

    while (!isSizeOne(priorityQueue)) {
        left = extractMinimum(priorityQueue);
        right = extractMinimum(priorityQueue);

        top = createHuffmanNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertToPriorityQueue(priorityQueue, top);
    }

    return extractMinimum(priorityQueue);
}

// Function to get the frequency of characters
int getFrequency(char data, char* message) {
    int count = 0;
    for (int i = 0; message[i]; ++i) {
        if (message[i] == data) ++count;
    }
    return count;
}

// Function to print the Huffman codes
void printHuffmanCodes(struct HuffmanCode huffmanCodes[], int size) {
    printf("\nHuffman codes:\n");
    for (int i = 0; i < size; ++i) {
        printf("%c: %s\n", huffmanCodes[i].data, huffmanCodes[i].code);
    }
}

// Function to encode a message using Huffman codes
char* encodeMessage(struct HuffmanCode huffmanCodes[], char* message) {
    int len = strlen(message);
    char* encodedMessage = (char*) malloc(sizeof(char) * len * MAX_TREE_HT);
    encodedMessage[0] = '\0';
    for (int i = 0; message[i]; ++i) {
        strcat(encodedMessage, huffmanCodes[message[i] - 'a'].code);
    }
    return encodedMessage;
}

// Function to decode a message using Huffman codes
char* decodeMessage(struct HuffmanNode* root, char* message) {
    int len = strlen(message);
    char* decodedMessage = (char*) malloc(sizeof(char) * len * MAX_TREE_HT);
    decodedMessage[0] = '\0';
    int j = 0;
    for (int i = 0; i < len; ++i) {
        if (message[i] == '0') root = root->left; else root = root->right;
        if (!root->left && !root->right) {
            decodedMessage[j++] = root->data;
            root = root;
        }
    }
    decodedMessage[j] = '\0';
    return decodedMessage;
}

int main() {
    // Sample paranoid message
    char message[] = "The quick brown fox jumps over the lazy dog.";

    // Get the frequency of each character in the message
    struct Frequency freq[] = {
        {'a', getFrequency('a', message)},
        {'b', getFrequency('b', message)},
        {'c', getFrequency('c', message)},
        {'d', getFrequency('d', message)},
        {'e', getFrequency('e', message)},
        {'f', getFrequency('f', message)},
        {'g', getFrequency('g', message)},
        {'h', getFrequency('h', message)},
        {'i', getFrequency('i', message)},
        {'j', getFrequency('j', message)},
        {'k', getFrequency('k', message)},
        {'l', getFrequency('l', message)},
        {'m', getFrequency('m', message)},
        {'n', getFrequency('n', message)},
        {'o', getFrequency('o', message)},
        {'p', getFrequency('p', message)},
        {'q', getFrequency('q', message)},
        {'r', getFrequency('r', message)},
        {'s', getFrequency('s', message)},
        {'t', getFrequency('t', message)},
        {'u', getFrequency('u', message)},
        {'v', getFrequency('v', message)},
        {'w', getFrequency('w', message)},
        {'x', getFrequency('x', message)},
        {'y', getFrequency('y', message)},
        {'z', getFrequency('z', message)}
    };

    unsigned int size = sizeof freq / sizeof freq[0];

    // Build the Huffman tree
    struct HuffmanNode* root = buildHuffmanTree(freq, size);

    // Traverse the Huffman tree and store the Huffman codes
    struct HuffmanCode huffmanCodes[size];
    int top = 0;

    void traverseHuffmanTree(struct HuffmanNode* root, char* code) {
        if (root->left) {
            code[top++] = '0';
            traverseHuffmanTree(root->left, code);
            top--;
        }
        if (root->right) {
            code[top++] = '1';
            traverseHuffmanTree(root->right, code);
            top--;
        }
        if (!root->left && !root->right) {
            huffmanCodes[root->data - 'a'].data = root->data;
            huffmanCodes[root->data - 'a'].code = (char*) malloc(sizeof(char) * (top + 1));
            code[top] = '\0';
            strcpy(huffmanCodes[root->data - 'a'].code, code);
        }
    }

    char code[MAX_TREE_HT];
    traverseHuffmanTree(root, code);

    // Print the Huffman codes
    printHuffmanCodes(huffmanCodes, size);

    // Encode the message using Huffman codes
    char* encodedMessage = encodeMessage(huffmanCodes, message);
    printf("\nEncoded message:\n%s\n", encodedMessage);

    // Decode the message using Huffman codes
    char* decodedMessage = decodeMessage(root, encodedMessage);
    printf("\nDecoded message:\n%s\n", decodedMessage);

    return 0;
}