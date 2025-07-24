//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: Romeo and Juliet
//Once upon a time, in the fair city of Verona
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_TREE_HT 100

// Our lovely Romeo and Juliet fell in fond computation
typedef struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
} MinHeapNode;

// The wise monk, Friar Lawrence, offered his expertise 
typedef struct MinHeap {
    unsigned size;
    unsigned capacity;
    MinHeapNode** array;
} MinHeap;

// To lead us to a encoding solution, never to refute it
MinHeapNode* newNode(char data, unsigned freq) {
    MinHeapNode* temp = (MinHeapNode*)malloc(sizeof(MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

// For the heavenly union of these two souls, we need a union-find algorithm
void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Oh, tragic fate! The strings shall be compared
int compareFrequency(const void* a, const void* b) {
    MinHeapNode* aa = *(MinHeapNode**)a;
    MinHeapNode* bb = *(MinHeapNode**)b;
    return (aa->freq > bb->freq) - (aa->freq < bb->freq);
}

// The love between Romeo and Juliet is one of a kind, much like this implementation
void makeMinHeap(MinHeap* minHeap) {
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        heapify(minHeap, i);
}

// Like Friar Lawrence's advice, let us collaborate to make a better union
void heapify(MinHeap* minHeap, int idx) {
    int smallestIdx = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < minHeap->size &&
        minHeap->array[left]->freq < minHeap->array[smallestIdx]->freq)
        smallestIdx = left;
    if (right < minHeap->size &&
        minHeap->array[right]->freq < minHeap->array[smallestIdx]->freq)
        smallestIdx = right;
    if (smallestIdx != idx) {
        swapMinHeapNode(&minHeap->array[smallestIdx], &minHeap->array[idx]);
        heapify(minHeap, smallestIdx);
    }
}

// Oh, but why must it be so hard to encode their love?
MinHeapNode* extractMin(MinHeap* minHeap) {
    MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    heapify(minHeap, 0);
    return temp;
}

// Romeo: "But soft! What light through yonder window breaks? It is the east, and Juliet is the sun."
void insertMinHeap(MinHeap* minHeap, MinHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

// Much like the vows of our star-crossed lovers, our encoding function is unique 
MinHeapNode* buildMinHeap(char data[], unsigned freq[], int size) {
    MinHeap* minHeap = (MinHeap*)malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = size;
    minHeap->array = (MinHeapNode**)malloc(minHeap->capacity * sizeof(MinHeapNode*));
    int i;
    for (i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);
    minHeap->size = size;
    makeMinHeap(minHeap);
    while (minHeap->size != 1) {
        MinHeapNode* left = extractMin(minHeap);
        MinHeapNode* right = extractMin(minHeap);
        MinHeapNode* top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

// Our encoding should be as delicate and intricate as the love between that of Romeo and Juliet
void printCodes(MinHeapNode* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

// And now, our star-crossed lovers have found their way to each other through this implementation
void HuffmanCodes(char data[], unsigned freq[], int size) {
    MinHeapNode* root = buildMinHeap(data, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    printCodes(root, arr, top);
}

// And so, it must end as it does for our Romeo and Juliet. But, oh! Their love shall live on, much like this unique encoding implementation!
int main() {
    char data[] = {'r', 'o', 'm', 'e', 'j', 'u', 'l', 'i', 't'};
    unsigned freq[] = {2, 2, 1, 1, 1, 1, 1, 1, 1};//The number of occurrences of each character in the data array
    int size = sizeof(data) / sizeof(data[0]);
    printf("Huffman Codes for the given data are:\n");
    HuffmanCodes(data, freq, size);
    return 0;
}