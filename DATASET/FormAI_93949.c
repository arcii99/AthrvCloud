//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100

typedef struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
} MinHeapNode;

typedef struct MinHeap {
    unsigned size;
    unsigned capacity;
    MinHeapNode **array;
} MinHeap;

typedef struct HuffmanNode {
    char data;
    char *code;
    struct HuffmanNode *next;
} HuffmanNode;

MinHeapNode* createMinHeapNode(char data, unsigned freq) {
    MinHeapNode* node = (MinHeapNode*) malloc(sizeof(MinHeapNode));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

MinHeap* createMinHeap(unsigned capacity) {
    MinHeap* minHeap = (MinHeap*) malloc(sizeof(MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode**) malloc(minHeap->capacity * sizeof(MinHeapNode*));
    return minHeap;
}

void swapMinHeapNode(MinHeapNode** a, MinHeapNode** b) {
    MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
 
    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;
 
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;
 
    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

int isSizeOne(MinHeap* minHeap) { 
    return (minHeap->size == 1); 
}

MinHeapNode* extractMin(MinHeap* minHeap) {
    MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(MinHeap* minHeap, MinHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1)/2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1)/2];
        i = (i - 1)/2;
    }
    minHeap->array[i] = minHeapNode;
}

void buildMinHeap(MinHeap* minHeap) {
    int n = minHeap->size - 1;
    int i;
    for(i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

void printArr(int arr[], int n) {
    int i;
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);
    printf("\n");
}

int isLeaf(MinHeapNode* root) {
    return !(root->left) && !(root->right);
}

MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) {
    MinHeap* minHeap = createMinHeap(size);
    int i;
    for (i = 0; i < size; ++i)
        minHeap->array[i] = createMinHeapNode(data[i], freq[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
    MinHeapNode *left, *right, *top;
    MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);
    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = createMinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

HuffmanNode* createHuffmanNode(char data, char* code) {
    HuffmanNode* node = (HuffmanNode*) malloc(sizeof(HuffmanNode));
    node->data = data;
    node->code = (char*) malloc(strlen(code));
    strcpy(node->code, code);
    node->next = NULL;
    return node;
}

void printHuffmanCodes(MinHeapNode* root, int arr[], int top, HuffmanNode** htable) {
    if (root->left) {
        arr[top] = 0;
        printHuffmanCodes(root->left, arr, top + 1, htable);
    }
    if (root->right) {
        arr[top] = 1;
        printHuffmanCodes(root->right, arr, top + 1, htable);
    }
    if (isLeaf(root)) {
        int i;
        printf("%c ", root->data);
        printf(": ");
        for (i = 0; i < top; ++i) {
            printf("%d", arr[i]);
        }
        HuffmanNode* huffmanNode = createHuffmanNode(root->data, arr);
        if (htable[root->data % MAX_TREE_HT] == NULL) {
            htable[root->data % MAX_TREE_HT] = huffmanNode;
        } else {
            HuffmanNode* current = htable[root->data % MAX_TREE_HT];
            while (current->next) {
                current = current->next;
            }
            current->next = huffmanNode;
        }
        printf("\n");
    }
}

void decodeHuffman(MinHeapNode* root, char* str) {
    MinHeapNode* current = root;
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (str[i] == '0') {
            current = current->left;
        } else if (str[i] == '1') {
            current = current->right;
        }
        if (isLeaf(current)) {
            printf("%c", current->data);
            current = root;
        }
    }
}

int main () {
    char arr[MAX_TREE_HT];
    int arr_freq[MAX_TREE_HT];
    int n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf(" %c", &arr[i]);
        printf("Enter frequency %d: ", i + 1);
        scanf("%d", &arr_freq[i]);
    }
    MinHeapNode* root = buildHuffmanTree(arr, arr_freq, n);
    int arr_code[MAX_TREE_HT], top = 0;
    HuffmanNode* htable[MAX_TREE_HT];
    for (i = 0; i < MAX_TREE_HT; i++) {
        htable[i] = NULL;
    }
    printf("The Symbol Codes are:\n");
    printHuffmanCodes(root, arr_code, top, htable);
    char input_string[MAX_TREE_HT];
    printf("Enter a string to encode using Huffman coding: ");
    scanf("%s", input_string);
    printf("Encoded string is: ");
    for (i = 0; i < strlen(input_string); i++) {
        HuffmanNode* current = htable[input_string[i] % MAX_TREE_HT];
        if (current) {
            while (current->data != input_string[i]) {
                current = current->next;
            }
            printf("%s", current->code);
        }
    }
    printf("\n");
    char encoded_string[MAX_TREE_HT];
    printf("Enter a string to decode using Huffman coding: ");
    scanf("%s", encoded_string);
    printf("Decoded string is: ");
    decodeHuffman(root, encoded_string);
    printf("\n");
    return 0;
}