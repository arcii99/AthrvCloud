//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TREE_HT 256
#define MAX_INPUT_SIZE 256

// Structure to store Huffman Tree node
struct MinHeapNode
{
    char data;
    unsigned frequency;
    struct MinHeapNode *left, *right;
};

// Function to create a new Huffman Tree node
struct MinHeapNode* newNode(char data, unsigned frequency)
{
    struct MinHeapNode* node = (struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
    node->left = node->right = NULL;
    node->data = data;
    node->frequency = frequency;
    return node;
}

// A structure to represent a Min Heap
struct MinHeap 
{
    unsigned size;
    unsigned capacity;
    struct MinHeapNode** array;
};

// Function to create a new Min Heap node
struct MinHeapNode* createNode(char data, unsigned frequency)
{
    struct MinHeapNode* temp = newNode(data, frequency);
    return temp;
}

// Function to create a new Min Heap
struct MinHeap* createMinHeap(unsigned capacity)
{
    struct MinHeap* minHeap = (struct MinHeap*) malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**) malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

// Function to swap nodes of the Min Heap
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b)
{
    struct MinHeapNode* temp = *a;
    *a = *b;
    *b = temp;
}

// Function to maintain Min Heap property
void minHeapify(struct MinHeap* minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency) smallest = left;
    if (right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency) smallest = right;

    if (smallest != idx) 
    {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Function to check if size of heap is 1 or not
int isSizeOne(struct MinHeap* minHeap)
{
    return (minHeap->size == 1);
}

// Function to get minimum frequency node from heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap)
{
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Function to insert a new node to Min Heap
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode)
{
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && minHeapNode->frequency < minHeap->array[(i - 1) / 2]->frequency)
    {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = minHeapNode;
}

// Function to build Huffman Tree
struct MinHeapNode* buildHuffmanTree(char* data, int* freq, int size)
{
    struct MinHeapNode *left, *right, *top;
    struct MinHeap* minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i)
        insertMinHeap(minHeap, newNode(data[i], freq[i]));

    while (!isSizeOne(minHeap))
    {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = createNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);
}

// Function to print Huffman Code for each character
void printCodes(struct MinHeapNode* root, int arr[], int top)
{
    // Assign 0 to left edge and recur
    if (root->left)
    {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    // Assign 1 to right edge and recur
    if (root->right) 
    {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    // If this is a leaf node, print the character and its code
    if (!root->left && !root->right) 
    {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// Function to read input characters and their frequencies from file
int getFrequency(char data[], int freq[], char filename[])
{
    FILE *fptr = fopen(filename, "r");
    if (fptr == NULL){
        printf("File not found");
        return 0;
    }
    
    char input[MAX_INPUT_SIZE];
    int input_length, i;
    fgets(input, MAX_INPUT_SIZE, fptr);
    input_length = strlen(input);
    input[input_length-1] = '\0';
    
    for(i = 0; i < input_length-1; i++)
    {
        freq[(int)input[i]]++;
        data[i] = input[i];
    }
    
    fclose(fptr);
    return input_length-1;
}

// Driver function
int main()
{
    char filename[] = "input.txt";
    char data[MAX_TREE_HT] = {0};
    int freq[MAX_TREE_HT] = {0};
    int size = getFrequency(data, freq, filename);

    struct MinHeapNode* root = buildHuffmanTree(data, freq, size);

    int arr[MAX_TREE_HT], top = 0;
    printCodes(root, arr, top);

    return 0;
}