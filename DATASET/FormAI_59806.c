//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 50

// struct for the Huffman tree node
struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
};

// struct for storing the Huffman code of each character
struct HuffmanCode {
    char c;
    char code[MAX_TREE_HT];
};

// struct for creating a min heap with MinHeapNodes
struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode **array;
};

// function to create a new MinHeapNode
struct MinHeapNode* createMinHeapNode(char data, unsigned freq) {
    struct MinHeapNode* node = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

// function to swap two MinHeapNodes
void swapMinHeapNode(struct MinHeapNode **a, struct MinHeapNode **b) {
    struct MinHeapNode *t = *a;
    *a = *b;
    *b = t;
}

// function to the min heapify the heap
void minHeapify(struct MinHeap *minHeap, int idx) {
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

// check if size of heap is 1
int isSizeOne(struct MinHeap *minHeap) {
    return (minHeap->size == 1);
}

// function to extract the min value node from the min heap
struct MinHeapNode* extractMin(struct MinHeap *minHeap) {
    struct MinHeapNode* temp = minHeap->array[0];

    minHeap->array[0] = minHeap->array[minHeap->size - 1];

    --minHeap->size;
    minHeapify(minHeap, 0);

    return temp;
}

// function to insert a new node into the min heap
void insertMinHeap(struct MinHeap *minHeap, struct MinHeapNode *minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = minHeapNode;
}

// function to build the min heap for the given array of characters
struct MinHeap* buildMinHeap(char data[], int freq[], int size) {
    int i;
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = size;
    minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));

    for (i = 0; i < size; ++i)
        minHeap->array[i] = createMinHeapNode(data[i], freq[i]);

    minHeap->size = size;
    for (i = (size - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);

    return minHeap;
}

// function to check if a node is a leaf node
int isLeaf(struct MinHeapNode* root) {
    return !(root->left) && !(root->right);
}

// function to create a Huffman tree from the min heap
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
    struct MinHeapNode *left, *right, *top;

    struct MinHeap* minHeap = buildMinHeap(data, freq, size);

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

// function to copy a string into a destination array
void copyString(char *str1, char *str2, int n) {
    int i;
    for(i = 0; i < n; i++)
        *(str2+i) = *(str1+i);
}

// function to traverse the Huffman tree and store the Huffman codes of each character
void traverseHuffmanTree(struct MinHeapNode* root, char *code, int top, struct HuffmanCode *codeArray) {
    if (root->left) {
        *(code+top) = '0';
        traverseHuffmanTree(root->left, code, top + 1, codeArray);
    }

    if (root->right) {
        *(code+top) = '1';
        traverseHuffmanTree(root->right, code, top + 1, codeArray);
    }

    if (isLeaf(root)) {
        code[top] = '\0';
        int len = strlen(code);
        char *newCode = (char*)malloc(len*sizeof(char));
        copyString(code, newCode, len);
        codeArray[root->data].c = root->data;
        copyString(newCode, codeArray[root->data].code, len);
    }
}

// function to print the Huffman codes of each character
void printHuffmanCodes(struct HuffmanCode *codeArray, int size) {
    int i;
    printf("\nHuffman Codes:\n");
    for (i = 0; i < size; ++i)
        printf("%c: %s\n", codeArray[i].c, codeArray[i].code);
}

// function to free the memory allocated for the MinHeapNode structures
void freeMinHeapNodes(struct MinHeapNode* node) {
    if(node == NULL)
        return;

    freeMinHeapNodes(node->left);
    freeMinHeapNodes(node->right);

    free(node);
}

int main() {
    char data[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};
    int size = sizeof(data)/sizeof(data[0]);
    struct HuffmanCode codeArray[size];
    memset(codeArray, 0, sizeof(codeArray));
    struct MinHeapNode* root = buildHuffmanTree(data, freq, size);

    char code[MAX_TREE_HT];
    traverseHuffmanTree(root, code, 0, codeArray);
    printHuffmanCodes(codeArray, size);

    freeMinHeapNodes(root);

    return 0;
}