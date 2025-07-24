//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
    char data;
    int freq;
    struct node *left, *right;
} node;

typedef struct minheap {
    int size;
    int capacity;
    node **arr;
} minheap;

// Function to create a new node
node *createNode(char data, int freq) {
    node *temp = (node*)malloc(sizeof(node));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

// Function to swap nodes
void swap(node **a, node **b) {
    node *temp = *a;
    *a = *b;
    *b = temp;
}

// Function to create a minimum heap
minheap *createMinHeap(int capacity) {
    minheap *heap = (minheap*)malloc(sizeof(minheap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->arr = (node**)malloc(capacity * sizeof(node*));
    return heap;
}

// Function to maintain the heap property of the heap
void minHeapify(minheap *heap, int index) {
    int smallest = index;
    int left = 2*index +1;
    int right = 2*index + 2;
    if (left < heap->size && heap->arr[left]->freq < heap->arr[smallest]->freq)
        smallest  = left;
    if (right < heap->size && heap->arr[right]->freq < heap->arr[smallest]->freq)
        smallest = right;
    if (smallest != index) {
        swap(&heap->arr[smallest], &heap->arr[index]);
        minHeapify(heap, smallest);
    }
}

// Function to check if the heap is empty or not
int isHeapEmpty(minheap *heap) {
    return (heap->size == 0);
}

// Function to extract minimum node from the heap
node *extractMin(minheap *heap) {
    node *temp = heap->arr[0];
    heap->arr[0] = heap->arr[heap->size -1];
    --heap->size;
    minHeapify(heap, 0);
    return temp;
}

// Function to insert a new node into the heap
void insertNode(minheap *heap, node *temp) {
    ++heap->size;
    int i = heap->size -1;
    while(i && temp->freq < heap->arr[(i-1)/2]->freq) {
        heap->arr[i] = heap->arr[(i-1)/2];
        i = (i-1)/2;
    }
    heap->arr[i] = temp;
}

// Function to build the minimum heap
void buildMinHeap(minheap *heap) {
    int n = heap->size -1;
    int i;
    for (i = (n-1)/2; i >= 0; --i)
        minHeapify(heap, i);
}

// Function to check if the node is a leaf node or not
int isLeaf(node *root) {
    return !(root->left) && !(root->right);
}

// Function to create a minimum heap and build it for the Huffman Coding algorithm
minheap *buildMinHeapForHuffman(char data[], int freq[], int size) {
    minheap *heap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        heap->arr[i] = createNode(data[i], freq[i]);
    heap->size = size;
    buildMinHeap(heap);
    return heap;
}

// Function to build a Huffman tree and print the Huffman codes for each character
void HuffmanCoding(char data[], int freq[], int size) {
    node *left, *right, *top;
    minheap *heap = buildMinHeapForHuffman(data, freq, size);

    while(!isHeapEmpty(heap)) {
        left = extractMin(heap);
        right = extractMin(heap);
        top = createNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertNode(heap, top);
    }

    // Create a code[] array to hold the Huffman codes for each character
    int code[size];
    int topIndex = 0;
    printCodes(heap->arr[0], code, topIndex);
}

// Function to print the Huffman codes for each character
void printCodes(node *root, int code[], int topIndex) {
    if (root->left) {
        code[topIndex] = 0;
        printCodes(root->left, code, topIndex + 1);
    }
    if (root->right) {
        code[topIndex] = 1;
        printCodes(root->right, code, topIndex + 1);
    }
    if (isLeaf(root)) {
        printf(" %c: ", root->data);
        for (int i = 0; i < topIndex; ++i) {
            printf("%d", code[i]);
        }
        printf("\n");
    }
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e'};
    int freq[] = {10, 5, 8, 15, 7};
    int size = sizeof(data) / sizeof(data[0]);

    printf("Welcome to the Happy Huffman Coding Implementation Program! Let's get started!\n");
    printf("The character array to be coded is: {a, b, c, d, e}\n");
    printf("The frequency of each character in the array is: {10, 5, 8, 15, 7}\n");
    printf("The Huffman Code for each character in the array is:\n");
    HuffmanCoding(data, freq, size);

    printf("Thank you for using this Happy Huffman Coding Implementation Program, have a nice day! :)\n");
    return 0;
}