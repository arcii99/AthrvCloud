//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_TREE_HT 100

typedef struct MinHeapNode {
    char data;
    unsigned frequency;
    struct MinHeapNode *left, *right;
} MinHeapNode_t;

typedef struct MinHeap {
    unsigned size;
    unsigned capacity;
    MinHeapNode_t **array;
} MinHeap_t;

typedef struct HuffmanCode {
    char data;
    char *code;
} HuffmanCode_t;

MinHeapNode_t *newMinHeapNode(char data, unsigned frequency) {
    MinHeapNode_t *node = (MinHeapNode_t *) malloc(sizeof(MinHeapNode_t));
    node->left = node->right = NULL;
    node->data = data;
    node->frequency = frequency;
    return node;
}

MinHeap_t *createMinHeap(unsigned capacity) {
    MinHeap_t *minHeap = (MinHeap_t *) malloc(sizeof(MinHeap_t));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (MinHeapNode_t **) malloc(minHeap->capacity * sizeof(MinHeapNode_t *));
    return minHeap;
}

void swapMinHeapNode(MinHeapNode_t **a, MinHeapNode_t **b) {
    MinHeapNode_t *t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(MinHeap_t *minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < minHeap->size &&
        minHeap->array[left]->frequency < minHeap->array[smallest]->frequency)
        smallest = left;
    if (right < minHeap->size &&
        minHeap->array[right]->frequency < minHeap->array[smallest]->frequency)
        smallest = right;
    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

int isSizeOne(MinHeap_t *minHeap) {
    return (minHeap->size == 1);
}

MinHeapNode_t *extractMin(MinHeap_t *minHeap) {
    MinHeapNode_t *temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void insertMinHeap(MinHeap_t *minHeap, MinHeapNode_t *minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->frequency < minHeap->array[(i - 1) / 2]->frequency) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

void buildMinHeap(MinHeap_t *minHeap) {
    int n = minHeap->size - 1;
    for (int i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

void printArray(char arr[], int n) {
    for (int i = 0; i < n; ++i)
        printf("%c", arr[i]);
    printf("\n");
}

int isLeaf(MinHeapNode_t *root) {
    return !(root->left) && !(root->right);
}

MinHeap_t *createAndBuildMinHeap(char data[], int freq[], int size) {
    MinHeap_t *minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newMinHeapNode(data[i], freq[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

MinHeapNode_t *buildHuffmanTree(char data[], int freq[], int size) {
    MinHeapNode_t *left, *right, *top;
    MinHeap_t *minHeap = createAndBuildMinHeap(data, freq, size);
    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newMinHeapNode('$', left->frequency + right->frequency);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}

void printCodes(MinHeapNode_t *root, char arr[], int top, HuffmanCode_t huffmanCodes[]) {
    if (root->left) {
        arr[top] = '0';
        printCodes(root->left, arr, top + 1, huffmanCodes);
    }
    if (root->right) {
        arr[top] = '1';
        printCodes(root->right, arr, top + 1, huffmanCodes);
    }
    if (isLeaf(root)) {
        huffmanCodes[(int) root->data].data = root->data;
        huffmanCodes[(int) root->data].code = (char *) malloc((top+1) * sizeof(char));
        for (int i=0; i<=top; ++i) {
            huffmanCodes[(int) root->data].code[i] = arr[i];
        }
    }
}

void HuffmanCodes(char data[], int freq[], int size, HuffmanCode_t huffmanCodes[]) {
    MinHeapNode_t *root = buildHuffmanTree(data, freq, size);
    char arr[MAX_TREE_HT];
    int top = 0;
    printCodes(root, arr, top, huffmanCodes);
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data)/sizeof(data[0]);
    HuffmanCode_t huffmanCodes[CHAR_MAX];
    for (int i = 0; i < CHAR_MAX; ++i) {
        huffmanCodes[i].data = '\0';
        huffmanCodes[i].code = NULL;
    }
    HuffmanCodes(data, freq, size, huffmanCodes);
    
    printf("Huffman codes for characters: \n");
    for (int i=0; i<size; ++i) {
        printf("%c: %s\n", huffmanCodes[(int) data[i]].data, huffmanCodes[(int) data[i]].code);
    }

    return 0;
}