//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

// Huffman tree node structure
struct MinHeapNode{
    char data;
    unsigned frequency;
    struct MinHeapNode *left, *right;
};

// Min heap structure
struct MinHeap{
    unsigned size;
    unsigned capacity;
    struct MinHeapNode **array;
};

// Creates a new node for Huffman tree
struct MinHeapNode* newNode(char data, unsigned frequency){
    struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->frequency = frequency;
    return temp;
}

// Creates a new min heap
struct MinHeap* createMinHeap(unsigned capacity){
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

// Swaps two nodes
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b){
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Heapify
void minHeapify(struct MinHeap* minHeap, int idx){
    int smallest = idx;
    int left = 2*idx+1;
    int right = 2*idx+2;
    if (left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency)
        smallest = left;
    if (right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency)
        smallest = right;
    if (smallest != idx){
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Check if heap size is 1
int isSizeOne(struct MinHeap* minHeap){
    return (minHeap->size == 1);
}

// Get minimum frequency node from min heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap){
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size-1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Insert a new node to min heap
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode){
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->frequency < minHeap->array[(i-1)/2]->frequency){
        minHeap->array[i] = minHeap->array[(i-1)/2];
        i = (i-1)/2;
    }
    minHeap->array[i] = minHeapNode;
}

// Builds Huffman tree
struct MinHeapNode* buildHuffmanTree(char data[], int frequency[], int size){
    struct MinHeapNode *left, *right, *top;
    struct MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i){
        insertMinHeap(minHeap, newNode(data[i], frequency[i]));
    }
    while (!isSizeOne(minHeap)){
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

// Prints Huffman codes from tree
void printCodes(struct MinHeapNode* root, int A[], int top){
    if (root->left){
        A[top] = 0;
        printCodes(root->left, A, top+1);
    }
    if (root->right){
        A[top] = 1;
        printCodes(root->right, A, top+1);
    }
    if (root->left == NULL && root->right == NULL){
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", A[i]);
        printf("\n");
    }
}

// Wrapper for Huffman tree and printing codes
void HuffmanCodes(char data[], int frequency[], int size){
    struct MinHeapNode* root = buildHuffmanTree(data, frequency, size);
    int A[MAX_TREE_HT], top = 0;
    printCodes(root, A, top);
}

int main(){
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int frequency[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data)/sizeof(data[0]);
    HuffmanCodes(data, frequency, size);
    return 0;
}