//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: dynamic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_TREE_HT 60       //Maximum height of Huffman tree

//Data structure to store the Huffman tree node
struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
};

//Data structure to represent a priority queue of heap nodes
struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode** array;
};

//Function to create a new Huffman tree node
struct MinHeapNode* newNode(char data, unsigned frequency) {
    struct MinHeapNode* node = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
 
    node->left = NULL;
    node->right = NULL;
    node->data = data;
    node->freq = frequency;
 
    return node;
}

//Function to create a new MinHeap from an array of given capacity
struct MinHeap* createMinHeap(unsigned capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity*sizeof(struct MinHeapNode*));
    return minHeap;
}

//Function to swap two nodes of min heap
void swapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

//MinHeapify Function
void minHeapify(struct MinHeap* minHeap, int index) {
    int smallest = index;
    int left = 2*index+1;
    int right = 2*index+2;
 
    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
      smallest = left;
 
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
      smallest = right;
 
    if (smallest != index) {
        swapNode(&minHeap->array[smallest], &minHeap->array[index]);
        minHeapify(minHeap, smallest);
    }
}

//Check if size of heap is 1 and returns minimum of two nodes
int isSizeOne(struct MinHeap* minHeap) {
    return (minHeap->size==1);
}

//Function to extract minimum from heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size-1];
    minHeap->size--;
    minHeapify(minHeap, 0);
    return temp;
}

//Function to insert a new node in heap
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
    minHeap->size++;
    int i = minHeap->size-1;
    while (i && minHeapNode->freq < minHeap->array[(i-1)/2]->freq) {
        minHeap->array[i] = minHeap->array[(i-1)/2];
        i = (i-1)/2;
    }
    minHeap->array[i] = minHeapNode;
}

//Build Huffman tree
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
    struct MinHeapNode *left, *right, *top;
 
    struct MinHeap* minHeap = createMinHeap(size);
 
    for (int i = 0; i < size; i++)
        insertMinHeap(minHeap, newNode(data[i], freq[i]));
 
    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
 
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
 
        insertMinHeap(minHeap, top);
    }
 
    return extractMin(minHeap);
}

//Assign code to each character in the tree
void assignCodes(struct MinHeapNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        assignCodes(root->left, arr, top+1);
    }
 
    if (root->right) {
        arr[top] = 1;
        assignCodes(root->right, arr, top+1);
    }
 
    if (root->left==NULL && root->right==NULL) {
        printf(" %c: ", root->data);
        for (int i = 0; i < top; i++)
            printf("%d", arr[i]);
        printf("\n");
    }
}

//Huffman function to encode text
void HuffmanEncode(char data[], int freq[], int size) {
    struct MinHeapNode* root = buildHuffmanTree(data, freq, size);
 
    int arr[MAX_TREE_HT], top = 0;
 
    assignCodes(root, arr, top);
}
 
//Driver function
int main() {
    printf("Huffman Coding Implementation \n");
 
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
 
    int size = sizeof(arr)/sizeof(arr[0]);
 
    HuffmanEncode(arr, freq, size);
 
    return 0;
}