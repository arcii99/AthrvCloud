//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structures used in the program
struct Node {
    unsigned int freq;
    unsigned char symbol;
    struct Node *left, *right;
};

struct Heap {
    unsigned int size;
    unsigned int capacity;
    struct Node **array;
};

// Function declarations
void shapeshift(char *input); // Function that shapeshifts the input
struct Node *createNode(unsigned char symbol, unsigned int freq);
struct Heap *initHeap(unsigned int capacity);
void minHeap(struct Heap *heap, int idx);
int isSizeOne(struct Heap *heap);
struct Node *getMin(struct Heap *heap);
void insert(struct Heap *heap, struct Node *node);
void buildHeap(struct Heap *heap);
void printArr(unsigned char *arr, int n);
int isLeaf(struct Node *node);
struct Heap *buildTree(unsigned char symbols[], unsigned int freq[], int size);
void encode(struct Node *root, unsigned char *arr, int top);
void decode(struct Node *root, int *idx, unsigned char *arr);

// Main function
int main() {
    char input[1000];
    printf("Enter some text: ");
    fgets(input, 1000, stdin); // Get input from user
    
    shapeshift(input); // Perform shapeshift on the input
    
    return 0;
}

// Function that shapeshifts the input
void shapeshift(char *input) {
    int i, j;
    unsigned char symbols[256];
    unsigned int freq[256];
    
    // Initialize frequency array to 0
    for(i=0; i<256; i++) {
        freq[i] = 0;
    }
    
    // Calculate frequency of each symbol in the input
    i = 0;
    while(input[i] != '\0') {
        freq[(int)input[i]]++;
        i++;
    }
    
    // Get unique symbols from the input
    j = 0;
    for(i=0; i<256; i++) {
        if(freq[i] > 0) {
            symbols[j] = (unsigned char)i;
            j++;
        }
    }
    
    // Build Huffman tree and get encoded message
    struct Heap *heap = buildTree(symbols, freq, j);

    unsigned char encoded_msg[1000];
    encode(heap->array[1], encoded_msg, 0);
    
    // Print encoded message
    printf("Encoded message: ");
    printArr(encoded_msg, strlen((char*)encoded_msg));
    printf("\n");
    
    // Decode message
    int idx = 0;
    unsigned char decoded_msg[1000];
    while(idx < strlen((char*)encoded_msg)) {
        decode(heap->array[1], &idx, decoded_msg);
    }
    decoded_msg[idx] = '\0';
    
    // Print decoded message
    printf("Decoded message: %s\n", decoded_msg);
}

// Function to create a new node
struct Node *createNode(unsigned char symbol, unsigned int freq) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->symbol = symbol;
    newNode->freq = freq;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to create heap
struct Heap *initHeap(unsigned int capacity) {
    struct Heap *heap = (struct Heap*)malloc(sizeof(struct Heap));
    heap->capacity = capacity;
    heap->size = 0;
    heap->array = (struct Node**)malloc(heap->capacity * sizeof(struct Node*));
    return heap;
}

// Function to heapify a subtree
void minHeap(struct Heap *heap, int idx) {
    int smallest = idx;
    int left = 2 * idx;
    int right = 2 * idx + 1;
    
    if(left <= heap->size && heap->array[left]->freq < heap->array[smallest]->freq) {
        smallest = left;
    }
    
    if(right <= heap->size && heap->array[right]->freq < heap->array[smallest]->freq) {
        smallest = right;
    }
    
    if(smallest != idx) {
        struct Node *tmp = heap->array[idx];
        heap->array[idx] = heap->array[smallest];
        heap->array[smallest] = tmp;
        minHeap(heap, smallest);
    }
}

// Function to check if the heap has only one node
int isSizeOne(struct Heap *heap) {
    return heap->size == 1;
}

// Function to get minimum value node from heap
struct Node *getMin(struct Heap *heap) {
    struct Node *node = heap->array[1];
    heap->array[1] = heap->array[heap->size];
    heap->size--;
    minHeap(heap, 1);
    return node;
}

// Function to insert node in heap
void insert(struct Heap *heap, struct Node *node) {
    heap->size++;
    int i = heap->size;
    while(i > 1 && node->freq < heap->array[i/2]->freq) {
        heap->array[i] = heap->array[i/2];
        i = i/2;
    }
    heap->array[i] = node;
}

// Function to build the heap
void buildHeap(struct Heap *heap) {
    int i, n;
    n = heap->size;
    for(i=n/2; i>=1; i--) {
        minHeap(heap, i);
    }
}

// Function to print an array
void printArr(unsigned char *arr, int n) {
    int i;
    for(i=0; i<n; i++) {
        printf("%c", arr[i]);
    }
}

// Function to check if a node is a leaf
int isLeaf(struct Node *node) {
    return node->left == NULL && node->right == NULL;
}

// Function to build the Huffman tree
struct Heap *buildTree(unsigned char symbols[], unsigned int freq[], int size) {
    int i;
    struct Heap *heap = initHeap(size);
    for(i=0; i<size; i++) {
        insert(heap, createNode(symbols[i], freq[i]));
    }
    
    buildHeap(heap);
    
    while(!isSizeOne(heap)) {
        struct Node *left = getMin(heap);
        struct Node *right = getMin(heap);
        
        struct Node *newNode = createNode('$', left->freq + right->freq);
        newNode->left = left;
        newNode->right = right;
        insert(heap, newNode);
    }
    
    return heap;
}

// Function to encode message
void encode(struct Node *root, unsigned char *arr, int top) {
    static unsigned char encoded_msg[1000]; // Static variable to hold encoded message
    if(root->left) {
        arr[top] = '0';
        encode(root->left, arr, top+1);
    }
    
    if(root->right) {
        arr[top] = '1';
        encode(root->right, arr, top+1);
    }
    
    if(isLeaf(root)) {
        int i;
        for(i=0; i<top; i++) {
            encoded_msg[i] = arr[i];
        }
        encoded_msg[top] = '\0';
        printf("%c%c", root->symbol, '\0');
        printf("%s", encoded_msg);
    }
}

// Function to decode message
void decode(struct Node *root, int *idx, unsigned char *arr) {
    if(isLeaf(root)) {
        printf("%c", root->symbol);
        arr[*idx] = root->symbol;
        *idx += 1;
        return;
    }
    
    if(arr[*idx] == '0') {
        *idx += 1;
        decode(root->left, idx, arr);
    }
    else {
        *idx += 1;
        decode(root->right, idx, arr);
    }
}