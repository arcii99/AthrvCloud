//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 512
#define MAX_OUTPUT_SIZE 1024

/* Huffman Tree node structure */
struct Node {
    char data;
    unsigned freq;
    struct Node *left, *right;
};

/* Priority Queue structure */
struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct Node **array;
};

/* Create a new Node */
struct Node* newNode(char data, unsigned freq) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

/* Create a priority Queue of given capacity */
struct MinHeap* createMinHeap(unsigned capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct Node**)malloc(minHeap->capacity * sizeof(struct Node*));
    return minHeap;
}

/* Swap Nodes */
void swap(struct Node** a, struct Node** b) {
    struct Node* t = *a;
    *a = *b;
    *b = t;
}

/* Heapify the Priority Queue */
void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;
    if (smallest != idx) {
        swap(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

/* Check if size if 1 */
int isSizeOne(struct MinHeap* minHeap) {
    return minHeap->size == 1;
}

/* Extract the minimum value node from heap */
struct Node* extractMin(struct MinHeap* minHeap) {
    struct Node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

/* Insert a new Node to the Priority Queue */
void insertMinHeap(struct MinHeap* minHeap, struct Node* node) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && node->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = node;
}

/* Build Huffman Tree */
struct Node* buildHuffmanTree(char data[], int freq[], int size) {
    struct Node *left, *right, *top;
    struct MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; i++) {
        insertMinHeap(minHeap, newNode(data[i], freq[i]));
    }
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

/* A utility function to print array of size n */
void printArr(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

/* Recursive function to print the Huffman code */
void printCodes(struct Node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }
    if (root->left == NULL && root->right == NULL) {
        printf("%c: ", root->data);
        printArr(arr, top);
    }
}

/* Main function */
int main() {
    char input[MAX_INPUT_SIZE];
    fgets(input, MAX_INPUT_SIZE, stdin);
    input[strcspn(input, "\r\n")] = 0;
    int freq[MAX_INPUT_SIZE], count = 0;
    for (int i = 0; i < 256; i++)
        freq[i] = 0;
    int n = strlen(input);
    for (int i = 0; i < n; i++)
        freq[input[i]]++;
    char data[n];
    for (int i = 0; i < n; i++) {
        if (freq[input[i]] > 0) {
            data[count] = input[i];
            count++;
            freq[input[i]] = 0;
        }
    }
    struct Node* root = buildHuffmanTree(data, freq, count);
    int arr[MAX_OUTPUT_SIZE], top = 0;
    printCodes(root, arr, top);
    return 0;
}