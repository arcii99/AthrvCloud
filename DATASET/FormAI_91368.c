//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 256

// node structure for Huffman Tree
struct huffmanNode {
    int freq;
    char character;
    struct huffmanNode *left;
    struct huffmanNode *right;
};

// function to create a new node for Huffman Tree
struct huffmanNode *createNode(char ch, int freq) {
    struct huffmanNode *node = (struct huffmanNode *)malloc(sizeof(struct huffmanNode));
    node->character = ch;
    node->freq = freq;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// function to create min heap
void buildMinHeap(struct huffmanNode **heap, int n) {
    int i;
    for (i = n / 2; i >= 0; i--) {
        minHeapify(heap, i, n);
    }
}

// function to get the minimum element from heap
struct huffmanNode *getMin(struct huffmanNode **heap, int n) {
    struct huffmanNode *temp = heap[0];
    heap[0] = heap[n - 1];
    minHeapify(heap, 0, n - 1);
    return temp;
}

// function to maintain min heap property
void minHeapify(struct huffmanNode **heap, int i, int n) {
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
    int smallest = i;
    if (leftChild < n && heap[leftChild]->freq < heap[smallest]->freq) {
        smallest = leftChild;
    }
    if (rightChild < n && heap[rightChild]->freq < heap[smallest]->freq) {
        smallest = rightChild;
    }
    if (smallest != i) {
        struct huffmanNode *temp = heap[i];
        heap[i] = heap[smallest];
        heap[smallest] = temp;
        minHeapify(heap, smallest, n);
    }
}

// function to build Huffman Tree
struct huffmanNode *buildHuffmanTree(char *str, int *freq) {
    int n = strlen(str);
    struct huffmanNode *heap[n];
    int i;
    for (i = 0; i < n; i++) {
        heap[i] = createNode(str[i], freq[i]);
    }
    buildMinHeap(heap, n);
    while (n != 1) {
        struct huffmanNode *left = getMin(heap, n--);
        struct huffmanNode *right = getMin(heap, n--);
        struct huffmanNode *node = createNode('$', left->freq + right->freq);
        node->left = left;
        node->right = right;
        heap[n++] = node;
        buildMinHeap(heap, n);
    }
    return heap[0];
}

// function to print Huffman Codes
void printCodes(struct huffmanNode *root, char *code, int top) {
    if (root->left) {
        code[top] = '0';
        printCodes(root->left, code, top + 1);
    }
    if (root->right) {
        code[top] = '1';
        printCodes(root->right, code, top + 1);
    }
    if (!root->left && !root->right) {
        code[top] = '\0';
        printf("%c: %s\n", root->character, code);
    }
}

// main function
int main() {
    char str[] = "Huffman Coding Example Program";
    int freq[MAX_SIZE] = {0};   // initialize frequency array to zero
    int i;
    for (i = 0; i < strlen(str); i++) {
        freq[(int)str[i]]++;
    }
    struct huffmanNode *root = buildHuffmanTree(str, freq);
    char code[MAX_SIZE];
    int top = 0;
    printf("Huffman Codes:\n");
    printCodes(root, code, top);
    return 0;
}