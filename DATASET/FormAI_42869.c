//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

typedef struct node{
    char data;
    unsigned freq;
    struct node *left, *right;
}node;

typedef struct MinHeap{
    unsigned size;
    unsigned capacity;
    node **array;
}MinHeap;

node* newNode(char data, unsigned freq){
    node* temp = (node*)malloc(sizeof(node));
    temp ->left = temp ->right = NULL;
    temp ->data = data;
    temp ->freq = freq;
    return temp;
}

MinHeap* createMinHeap(unsigned capacity){
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap ->size = 0;
    minHeap ->capacity = capacity;
    minHeap ->array = (node**)malloc(minHeap ->capacity*sizeof(node*));
    return minHeap;
}

void swapNode(node** a, node** b){
    node* temp = *a;
    *a = *b;
    *b = temp;
}

void Heapify(MinHeap* minHeap, int idx){
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
 
    if ((left < minHeap->size) && (minHeap->array[left]->freq < minHeap->array[smallest]->freq))
        smallest = left;
 
    if ((right < minHeap->size) && (minHeap->array[right]->freq < minHeap->array[smallest]->freq))
        smallest = right;
 
    if (smallest != idx){
        swapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        Heapify(minHeap, smallest);
    }
}

int isSizeOne(MinHeap* minHeap){
    return (minHeap->size == 1);
}

node* extractMin(MinHeap* minHeap){
    node* temp = minHeap ->array[0];
    minHeap ->array[0] = minHeap ->array[minHeap ->size - 1];
    --minHeap ->size;
    Heapify(minHeap, 0);
    return temp;
}

void insertMinHeap(MinHeap* minHeap, node* temp){
    ++minHeap ->size;
    int i = minHeap ->size - 1;
    while (i && temp ->freq < minHeap ->array[(i - 1) / 2] ->freq){
        minHeap ->array[i] = minHeap ->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap ->array[i] = temp;
}

void buildMinHeap(MinHeap* minHeap){
    int n = minHeap ->size - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; --i)
        Heapify(minHeap, i);
}

void printArr(int arr[], int n){
    int i;
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);
    printf("\n");
}

int isLeaf(node* root){
    return !(root ->left) && !(root ->right) ;
}

MinHeap* createAndBuildMinHeap(char data[], int freq[], int size){
    MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap ->array[i] = newNode(data[i], freq[i]);
    minHeap ->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

node* buildHuffmanTree(char data[], int freq[], int size){
    node *left, *right, *top;
    MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);

    while (!isSizeOne(minHeap)){
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left ->freq + right ->freq);
        top ->left = left;
        top ->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

void printCodes(node* root, int arr[], int top){
    if (root ->left){
        arr[top] = 0;
        printCodes(root ->left, arr, top + 1);
    }
 
    if (root ->right){
        arr[top] = 1;
        printCodes(root ->right, arr, top + 1);
    }

    if (isLeaf(root)){
        printf("%c:\t", root ->data);
        printArr(arr, top);
    }
}

void HuffmanCodes(char data[], int freq[], int size){
    node* root = buildHuffmanTree(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    printCodes(root, arr, top);
}

int main(){
    char arr[] = {'A', 'B', 'C', 'D', 'E', 'F'};
    int freq[] = {4, 5, 6, 2, 1, 3};
    int size = sizeof(arr)/sizeof(arr[0]);
    HuffmanCodes(arr, freq, size);
    return 0;
}