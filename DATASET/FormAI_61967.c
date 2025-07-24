//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>

// Define constants
#define MAX_TREE_HT 100

// Define node struct
struct node {
    char data;
    unsigned frequency;
    struct node *left, *right;
};

// Define min heap struct
struct minHeap {
    unsigned size;
    unsigned capacity;
    struct node** array;
};

// Create new node function
struct node* newNode(char data, unsigned frequency) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->frequency = frequency;
    return temp;
}

// Create new min heap function
struct minHeap* createMinHeap(unsigned capacity) {
    struct minHeap* heap = (struct minHeap*)malloc(sizeof(struct minHeap));
    heap->size = 0;
    heap->capacity = capacity;
    heap->array = (struct node**)malloc(heap->capacity * sizeof(struct node*));
    return heap;
}

// Swap nodes function
void swapNodes(struct node** a, struct node** b) {
    struct node* t = *a;
    *a = *b;
    *b = t;
}

// Heapify function
void minHeapify(struct minHeap* heap, int index) {
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < heap->size && heap->array[left]->frequency < heap->array[smallest]->frequency)
        smallest = left;
    if (right < heap->size && heap->array[right]->frequency < heap->array[smallest]->frequency)
        smallest = right;
    if (smallest != index) {
        swapNodes(&heap->array[smallest], &heap->array[index]);
        minHeapify(heap, smallest);
    }
}

// Check if heap has only one node
int isSizeOne(struct minHeap* heap) {
    return (heap->size == 1);
}

// Extract minimum node function
struct node* extractMin(struct minHeap* heap) {
    struct node* temp = heap->array[0];
    heap->array[0] = heap->array[heap->size - 1];
    --heap->size;
    minHeapify(heap, 0);
    return temp;
}

// Insert node to heap function
void insertMinHeap(struct minHeap* heap, struct node* node) {
    ++heap->size;
    int i = heap->size - 1;
    while (i && node->frequency < heap->array[(i - 1) / 2]->frequency) {
        heap->array[i] = heap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    heap->array[i] = node;
}

// Build min heap function
void buildMinHeap(struct minHeap* heap) {
    int n = heap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i) {
        minHeapify(heap, i);
    }
}

// Check if node is leaf function
int isLeaf(struct node* node) {
    return !(node->left) && !(node->right);
}

// Create min heap and build it function
struct minHeap* createAndBuild(char data[], int frequency[], int size) {
    struct minHeap* heap = createMinHeap(size);
    for (int i = 0; i < size; ++i) {
        heap->array[i] = newNode(data[i], frequency[i]);
    }
    heap->size = size;
    buildMinHeap(heap);
    return heap;
}

// Create Huffman tree function
struct node* buildHuffmanTree(char data[], int frequency[], int size) {
    struct node *left, *right, *top;
    struct minHeap* heap = createAndBuild(data, frequency, size);

    while (!isSizeOne(heap)) {
        left = extractMin(heap);
        right = extractMin(heap);

        top = newNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;

        insertMinHeap(heap, top);
    }

    return extractMin(heap);
}

// Print codes function
void printCodes(struct node* root, int arr[], int top) {
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
        for (int i = 0; i < top; ++i) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

// Huffman coding main function
void HuffmanCodes(char data[], int frequency[], int size) {
    struct node* root = buildHuffmanTree(data, frequency, size);

    int arr[MAX_TREE_HT], top = 0;

    printCodes(root, arr, top);
}

// Main function
int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frequency[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data) / sizeof(data[0]);

    HuffmanCodes(data, frequency, size);

    return 0;
}