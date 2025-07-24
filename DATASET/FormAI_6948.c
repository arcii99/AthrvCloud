//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#define MAX_TREE_HT 256

struct heapNode{
    char data;
    unsigned freq;
    struct heapNode *left, *right;
};

struct minHeap{
    unsigned size;
    unsigned capacity;
    struct heapNode** array;
};

struct heapNode* newNode(char data, unsigned freq){
    struct heapNode* temp = (struct heapNode*)malloc(sizeof(struct heapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

struct minHeap* createMinHeap(unsigned capacity){
    struct minHeap* minHeap = (struct minHeap*)malloc(sizeof(struct minHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct heapNode**)malloc(minHeap->capacity * sizeof(struct heapNode*));
    return minHeap;
}

void swapHeapNode(struct heapNode** a, struct heapNode** b){
    struct heapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct minHeap* minHeap, int idx){
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;
    if (smallest != idx){
        swapHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

int isSizeOne(struct minHeap* minHeap){
    return (minHeap->size == 1);
}

struct heapNode* extractMin(struct minHeap* minHeap){
    struct heapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(struct minHeap* minHeap, struct heapNode* heapNode){
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && heapNode->freq < minHeap->array[(i - 1) / 2]->freq){
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = heapNode;
}

void buildMinHeap(struct minHeap* minHeap){
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

void printArr(int arr[], int n){
    int i;
    for (i = 0; i < n; ++i){
        printf("%d", arr[i]);
    }
    printf("\n");
}

int isLeaf(struct heapNode* root){
    return !(root->left) && !(root->right);
}

struct minHeap* createAndBuildMinHeap(char data[], int freq[], int size){
    struct minHeap* minHeap = createMinHeap(size);
    int i;
    for (i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

struct heapNode* buildHuffmanTree(char data[], int freq[], int size){
    struct heapNode *left, *right, *top;
    struct minHeap* minHeap = createAndBuildMinHeap(data, freq, size);
    while (!isSizeOne(minHeap)){
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

void printCodes(struct heapNode* root, int arr[], int top){
    if (root->left){
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right){
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (isLeaf(root)){
        printf("%c: ", root->data);
        printArr(arr, top);
    }
}

void HuffmanCodes(char data[], int freq[], int size){
    struct heapNode* root = buildHuffmanTree(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    printCodes(root, arr, top);
}

int main(){
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Huffman codes:\n");
    HuffmanCodes(arr, freq, size);
    return 0;
}