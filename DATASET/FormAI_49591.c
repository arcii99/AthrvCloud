//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the character code length to be 256
#define CHAR_CODE_LENGTH 256

// Define a struct for Huffman codes
struct HuffmanCode {
    char symbol;
    char* code;
};

// Define a struct for a node in the Huffman tree
struct HuffmanNode {
    char symbol;
    int frequency;
    struct HuffmanNode* left;
    struct HuffmanNode* right;
};

// Define a struct for a priority queue
struct PriorityQueue {
    int size;
    int capacity;
    struct HuffmanNode** nodes;
};

// Define a function to create a new Huffman node
struct HuffmanNode* newHuffmanNode(char symbol, int frequency) {
    struct HuffmanNode* node = (struct HuffmanNode*)malloc(sizeof(struct HuffmanNode));
    node->symbol = symbol;
    node->frequency = frequency;
    node->left = NULL;
    node->right = NULL;

    return node;
}

// Define a function to create a new priority queue
struct PriorityQueue* newPriorityQueue(int capacity) {
    struct PriorityQueue* pq = (struct PriorityQueue*)malloc(sizeof(struct PriorityQueue));
    pq->size = 0;
    pq->capacity = capacity;
    pq->nodes = (struct HuffmanNode**)malloc(capacity * sizeof(struct HuffmanNode*));

    return pq;
}

// Define a function to swap two Huffman nodes
void swap(struct HuffmanNode** a, struct HuffmanNode** b) {
    struct HuffmanNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Define a function to min-heapify the priority queue
void minHeapify(struct PriorityQueue* pq, int idx) {
    int smallest = idx;
    int l = 2 * idx + 1;
    int r = 2 * idx + 2;

    if (l < pq->size && pq->nodes[l]->frequency < pq->nodes[smallest]->frequency) {
        smallest = l;
    }

    if (r < pq->size && pq->nodes[r]->frequency < pq->nodes[smallest]->frequency) {
        smallest = r;
    }

    if (smallest != idx) {
        swap(&pq->nodes[smallest], &pq->nodes[idx]);
        minHeapify(pq, smallest);
    }
}

// Define a function to check if the priority queue is empty
int isPriorityQueueEmpty(struct PriorityQueue* pq) {
    return pq->size == 0;
}

// Define a function to extract the minimum value node from the priority queue
struct HuffmanNode* extractMin(struct PriorityQueue* pq) {
    struct HuffmanNode* minNode = pq->nodes[0];
    pq->nodes[0] = pq->nodes[pq->size - 1];
    pq->size--;
    minHeapify(pq, 0);

    return minNode;
}

// Define a function to insert a node into the priority queue
void insert(struct PriorityQueue* pq, struct HuffmanNode* node) {
    pq->size++;
    int i = pq->size - 1;

    while (i && node->frequency < pq->nodes[(i - 1) / 2]->frequency) {
        pq->nodes[i] = pq->nodes[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    pq->nodes[i] = node;
}

// Define a function to build the Huffman tree from a frequency table
struct HuffmanNode* buildHuffmanTree(int* frequencies) {
    struct PriorityQueue* pq = newPriorityQueue(CHAR_CODE_LENGTH);

    for (int i = 0; i < CHAR_CODE_LENGTH; i++) {
        if (frequencies[i]) {
            insert(pq, newHuffmanNode(i, frequencies[i]));
        }
    }

    while (pq->size > 1) {
        struct HuffmanNode *left = extractMin(pq);
        struct HuffmanNode *right = extractMin(pq);
        struct HuffmanNode *node = newHuffmanNode('$', left->frequency + right->frequency);
        node->left = left;
        node->right = right;
        insert(pq, node);
    }

    return extractMin(pq);
}

// Define a function to generate the Huffman codes for each character
void generateHuffmanCodes(struct HuffmanNode* root, struct HuffmanCode codes[], char* code, int depth) {
    if (!root) {
        return;
    }

    if (root->symbol != '$') {
        code[depth] = '\0';
        codes[root->symbol].symbol = root->symbol;
        codes[root->symbol].code = (char*)malloc((depth + 1) * sizeof(char));
        strcpy(codes[root->symbol].code, code);
    }

    code[depth] = '0';
    generateHuffmanCodes(root->left, codes, code, depth + 1);

    code[depth] = '1';
    generateHuffmanCodes(root->right, codes, code, depth + 1);
}

// Define a function to print the Huffman codes for each character
void printHuffmanCodes(struct HuffmanCode codes[]) {
    printf("Huffman Codes:\n");
    for (int i = 0; i < CHAR_CODE_LENGTH; i++) {
        if (codes[i].code) {
            printf("%c: %s\n", codes[i].symbol, codes[i].code);
        }
    }
}

// Define the main function
int main() {
    char str[] = "the quick brown fox jumps over the lazy dog";
    int frequencies[CHAR_CODE_LENGTH] = {0};

    // Calculate the frequency of each character in the string
    for (int i = 0; i < strlen(str); i++) {
        frequencies[str[i]]++;
    }

    // Build the Huffman tree from the frequency table
    struct HuffmanNode* root = buildHuffmanTree(frequencies);

    // Generate the Huffman codes for each character
    struct HuffmanCode codes[CHAR_CODE_LENGTH] = {{'\0', NULL}};
    char code[CHAR_CODE_LENGTH];
    generateHuffmanCodes(root, codes, code, 0);

    // Print the Huffman codes for each character
    printHuffmanCodes(codes);

    return 0;
}