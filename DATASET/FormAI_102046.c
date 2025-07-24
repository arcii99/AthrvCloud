//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of characters that can be encoded
#define MAX_CHARACTERS 256

// Define the node structure for Huffman tree
typedef struct node {
    char character;
    int frequency;
    struct node *left;
    struct node *right;
} node;

// Define the node structure for Huffman Min Heap
typedef struct huffmanMinHeap {
    int size;
    int capacity;
    node **array;
} huffmanMinHeap;

// Function to create a new node
node *createNode(char character, int frequency) {
    node *newNode = (node *) malloc(sizeof(node));
    newNode->character = character;
    newNode->frequency = frequency;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to create a new Huffman Min Heap
huffmanMinHeap *createHuffmanMinHeap(int capacity) {
    huffmanMinHeap *newHeap = (huffmanMinHeap *) malloc(sizeof(huffmanMinHeap));
    newHeap->size = 0;
    newHeap->capacity = capacity;
    newHeap->array = (node **) malloc(capacity * sizeof(node *));
    return newHeap;
}

// Function to swap two nodes
void swapNodes(node **x, node **y) {
    node *temp = *x;
    *x = *y;
    *y = temp;
}

// Function to perform heapify operation for Min Heap
void minHeapify(huffmanMinHeap *heap, int index) {
    int smallest = index;
    int leftIndex = 2 * index + 1;
    int rightIndex = 2 * index + 2;

    if (leftIndex < heap->size && heap->array[leftIndex]->frequency < heap->array[smallest]->frequency) {
        smallest = leftIndex;
    }

    if (rightIndex < heap->size && heap->array[rightIndex]->frequency < heap->array[smallest]->frequency) {
        smallest = rightIndex;
    }

    if (smallest != index) {
        swapNodes(&heap->array[smallest], &heap->array[index]);
        minHeapify(heap, smallest);
    }
}

// Function to check if the Heap has only one node left
int isSizeOne(huffmanMinHeap *heap) {
    return (heap->size == 1);
}

// Function to extract the minimum node from the Heap
node *extractMin(huffmanMinHeap *heap) {
    node *minimumNode = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    --heap->size;
    minHeapify(heap, 0);
    return minimumNode;
}

// Function to insert a new node into the Heap
void insertNode(huffmanMinHeap *heap, node *newNode) {
    ++heap->size;
    int i = heap->size - 1;
    while (i && newNode->frequency < heap->array[(i - 1) / 2]->frequency) {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->array[i] = newNode;
}

// Function to build the Huffman Min Heap
huffmanMinHeap *buildHuffmanMinHeap(char characters[], int frequencies[], int size) {
    huffmanMinHeap *heap = createHuffmanMinHeap(size);

    for (int i = 0; i < size; i++) {
        node *newNode = createNode(characters[i], frequencies[i]);
        insertNode(heap, newNode);
    }

    return heap;
}

// Function to check if a node is a leaf node
int isLeaf(node *node) {
    return !(node->left) && !(node->right);
}

// Function to print Huffman codes from the root of the Huffman tree
void printHuffmanCodes(node *root, int codes[], int top) {
    if (root->left) {
        codes[top] = 0;
        printHuffmanCodes(root->left, codes, top + 1);
    }

    if (root->right) {
        codes[top] = 1;
        printHuffmanCodes(root->right, codes, top + 1);
    }

    if (isLeaf(root)) {
        printf("%c: ", root->character);
        for (int i = 0; i < top; i++) {
            printf("%d", codes[i]);
        }
        printf("\n");
    }
}

// Function to build the Huffman tree
node *buildHuffmanTree(char characters[], int frequencies[], int size) {
    node *leftNode, *rightNode, *parentNode;

    huffmanMinHeap *heap = buildHuffmanMinHeap(characters, frequencies, size);

    while (!isSizeOne(heap)) {
        leftNode = extractMin(heap);
        rightNode = extractMin(heap);

        parentNode = createNode('$', leftNode->frequency + rightNode->frequency);
        parentNode->left = leftNode;
        parentNode->right = rightNode;

        insertNode(heap, parentNode);
    }

    return extractMin(heap);
}

int main() {
    char characters[MAX_CHARACTERS];
    int frequencies[MAX_CHARACTERS];
    char sentence[MAX_CHARACTERS];
    int sentenceLength;

    printf("Welcome to the Huffman Coding Implementation program!\n");

    printf("Enter a sentence to encode: ");
    fgets(sentence, MAX_CHARACTERS, stdin);
    sentenceLength = strlen(sentence);

    // Initialize frequencies of all the characters to 0
    for (int i = 0; i < MAX_CHARACTERS; i++) {
        frequencies[i] = 0;
    }

    // Calculate frequency of each character in the sentence
    for (int i = 0; i < sentenceLength; i++) {
        frequencies[(int) sentence[i]]++;
    }

    // Copy non-zero frequency characters from the sentence to the character array
    int j = 0;
    for (int i = 0; i < MAX_CHARACTERS; i++) {
        if (frequencies[i] > 0) {
            characters[j++] = (char) i;
        }
    }

    // Build the Huffman tree
    node *root = buildHuffmanTree(characters, frequencies, j);

    // Print Huffman codes
    int codes[MAX_CHARACTERS];
    int top = 0;
    printf("\nHuffman Codes:\n");
    printHuffmanCodes(root, codes, top);

    printf("\nThank you for using the Huffman Coding Implementation program!\n");

    return 0;
}