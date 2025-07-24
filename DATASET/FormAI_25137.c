//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100 //maximum height of the Huffman tree

//structure to store character frequency and Huffman tree nodes
struct MinHeapNode {
    char data; //character
    unsigned frequency; //frequency of character
    struct MinHeapNode *left, *right; //nodes of Huffman tree
};

//structure to store Min Heap
struct MinHeap {
    unsigned size; //current size of heap
    unsigned capacity; //maximum capacity of heap
    struct MinHeapNode **array; //array of nodes
};

//function to create a new Min Heap node
struct MinHeapNode* newNode(char data, unsigned frequency){
    struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->frequency = frequency;
    return temp;
}

//function to create a new Min Heap
struct MinHeap* createMinHeap(unsigned capacity){
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

//function to swap two nodes
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b){
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

//function to heapify the heap
void minHeapify(struct MinHeap* minHeap, int idx){
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    
    if(left < minHeap->size && minHeap->array[left]->frequency < minHeap->array[smallest]->frequency){
        smallest = left;
    }
    
    if(right < minHeap->size && minHeap->array[right]->frequency < minHeap->array[smallest]->frequency){
        smallest = right;
    }
    
    if(smallest != idx){
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

//function to check if size of heap is 1
int isSizeOne(struct MinHeap* minHeap){
    return (minHeap->size == 1);
}

//function to get the minimum value node from the heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap){
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

//function to insert a new node in the heap
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode){
    ++minHeap->size;
    int i = minHeap->size - 1;
    while(i && minHeapNode->frequency < minHeap->array[(i - 1) / 2]->frequency){
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

//function to build the Min Heap
void buildMinHeap(struct MinHeap* minHeap){
    int n = minHeap->size - 1;
    int i;
    for(i = (n - 1) / 2; i >= 0; --i){
        minHeapify(minHeap, i);
    }
}

//function to check if the node is a leaf node
int isLeaf(struct MinHeapNode* root){
    return !(root->left) && !(root->right);
}

//function to create a new node from the character and its frequency and add it to the heap
struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size){
    struct MinHeap* minHeap = createMinHeap(size);
    for(int i = 0; i < size; ++i){
        minHeap->array[i] = newNode(data[i], freq[i]);
    }
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

//function to build the Huffman tree
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size){
    struct MinHeapNode *left, *right, *top;
    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);
    while(!isSizeOne(minHeap)){
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

//function to print the Huffman codes from the root of Huffman tree
void printCodes(struct MinHeapNode* root, int arr[], int top){
    if(root->left){
        arr[top] = 0;
        printCodes(root->left, arr, top+1);
    }
    
    if(root->right){
        arr[top] = 1;
        printCodes(root->right, arr, top+1);
    }
    if(isLeaf(root)){
        printf("%c: ", root->data);
        for(int i = 0; i < top; ++i){
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

//function to encode the input string and print the Huffman codes
void HuffmanCodes(char data[], int freq[], int size){
    struct MinHeapNode* root = buildHuffmanTree(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    printCodes(root, arr, top);
}

int main()
{
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {15, 9, 12, 6, 5, 3};
    int size = sizeof(data)/sizeof(data[0]);
    HuffmanCodes(data, freq, size);
    return 0;
}