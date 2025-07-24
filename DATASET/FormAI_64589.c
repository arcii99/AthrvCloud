//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: decentralized
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_TREE_HT 100

char arr[MAX_TREE_HT], left[MAX_TREE_HT][MAX_TREE_HT], right[MAX_TREE_HT][MAX_TREE_HT];
int freq[MAX_TREE_HT], leftSize[MAX_TREE_HT], rightSize[MAX_TREE_HT];

// Node structure
struct Node{
    char data;
    unsigned freq;
    struct Node *left, *right;
};

// Create a node of the tree
struct Node* newNode(char data, unsigned freq){
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

// Swap two nodes
void swap(struct Node** a, struct Node** b){
    struct Node* t = *a;
    *a = *b;
    *b = t;
}

// Store the heap
struct MinHeap{
    unsigned size;
    unsigned capacity;
    struct Node** array;
};

// Create a new min heap node
struct Node* newHeapNode(char data, unsigned freq){
    struct Node* temp = newNode(data, freq);
    return temp;
}

// Create a min heap structure
struct MinHeap* createMinHeap(unsigned capacity){
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct Node**)malloc(minHeap->capacity * sizeof(struct Node*));
    return minHeap;
}

// Min heapify function
void minHeapify(struct MinHeap* minHeap, int idx){
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
      smallest = left;
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
      smallest = right;
    if (smallest != idx){
        swap(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Check if size is 1
int isSizeOne(struct MinHeap* minHeap){
    return (minHeap->size == 1);
}

// Extract the minimum value node from heap
struct Node* extractMin(struct MinHeap* minHeap){
    struct Node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Insert the node into heap
void insertMinHeap(struct MinHeap* minHeap, struct Node* node){
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && node->freq < minHeap->array[(i - 1)/2]->freq){
        minHeap->array[i] = minHeap->array[(i - 1)/2];
        i = (i - 1)/2;
    }
    minHeap->array[i] = node;
}

// Build the min heap
void buildMinHeap(struct MinHeap* minHeap){
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1)/2; i >= 0; --i)
        minHeapify(minHeap, i);
}

// Check if it is a leaf node
int isLeaf(struct Node* root){
    return !(root->left) && !(root->right);
}

// Create and build the min heap
struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size){
    struct MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newHeapNode(data[i], freq[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

// Build the Huffman tree and store codes in arr[]
void buildHuffmanTree(char data[], int freq[], int size){
    struct Node *left, *right, *top;
    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);
    while (!isSizeOne(minHeap)){
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    struct Node* root = minHeap->array[0];
    int arrIndex = 0;
    encode(root, arr, arrIndex);
}

// Encode the given Huffman Tree
void encode(struct Node* root, char str[], int top){
    if (root->left){
        str[top] = '0';
        encode(root->left, str, top + 1);
    }
    if (root->right){
        str[top] = '1';
        encode(root->right, str, top + 1);
    }
    if (isLeaf(root)){
        printf("%c: %s\n", root->data, str);
    }
}

// Main method
int main(){
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data)/sizeof(data[0]);
    printf("The Huffman codes are:\n");
    buildHuffmanTree(data, freq, size);
    return 0;
}