//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_HT 100
#define MAX_CHAR 256

// Huffman Tree node
struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode* left;
    struct MinHeapNode* right;
};

// Min Heap structure for Huffman Tree
struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode** array;
};

// Huffman Binary Tree Node
struct HuffmanNode {
    char data;
    int code[MAX_TREE_HT];
    int code_count;
    struct HuffmanNode* left;
    struct HuffmanNode* right;
};

// Create a new Huffman Binary Tree Node
struct HuffmanNode* newHuffmanNode(char data) {
    struct HuffmanNode* node = (struct HuffmanNode*)malloc(sizeof(struct HuffmanNode));
    node->data = data;
    node->code_count = 0;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// Create a new Min Heap Node
struct MinHeapNode* newMinHeapNode(char data, unsigned freq) {
    struct MinHeapNode* node = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

// Create a new Min Heap Structure
struct MinHeap* createMinHeap(unsigned capacity) {
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

// Swap two Min Heap Nodes
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Min Heapify
void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = (idx * 2) + 1;
    int right = (idx * 2) + 2;
    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq) {
        smallest = left;
    }
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq) {
        smallest = right;
    }
    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

// Check whether given node is leaf node of the Huffman Binary Tree
int isLeaf(struct MinHeapNode* root) {
    return !(root->left) && !(root->right);
}

// Create and Build Min Heap from given array of nodes
struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size) {
    int i;
    struct MinHeap* minHeap = createMinHeap(size);
    for (i = 0; i < size; ++i) {
        minHeap->array[i] = newMinHeapNode(data[i], freq[i]);
    }
    minHeap->size = size;
    for (i = size / 2 - 1; i >= 0; --i) {
        minHeapify(minHeap, i);
    }
    return minHeap;
}

// Extract minimum value Node from Min Heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Insert Node into Min Heap
void insertMinHeapNode(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

// Build Huffman Binary Tree and create the Code Table
// Recursive Function
struct HuffmanNode* buildHuffmanTree(char data[], int freq[], int size, struct MinHeap* minHeap) {
    struct MinHeapNode *left, *right, *top;
    struct HuffmanNode *hNode;

    while (minHeap->size != 1) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newMinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeapNode(minHeap, top);
    }
    top = extractMin(minHeap);
    hNode = newHuffmanNode(top->data);
    int i;
    for (i = 0; i < size; ++i) {
        findHuffmanCodes(top, data[i], hNode->code, &(hNode->code_count));
    }
    return hNode;
}

// Find Huffman Codes for all characters in the given Huffman Binary Tree
// Recursive Function
void findHuffmanCodes(struct MinHeapNode* root, char data, int arr[], int* index) {
    if (root == NULL) {
        return;
    }
    if (root->left) {
        arr[*index] = 0;
        ++(*index);
        findHuffmanCodes(root->left, data, arr, index);
    }
    if (root->right) {
        arr[*index] = 1;
        ++(*index);
        findHuffmanCodes(root->right, data, arr, index);
    }
    if (isLeaf(root) && root->data == data) {
        int i;
        printf("'%c' : ", data);
        for (i = 0; i < *index; ++i) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
    if (*index > 0) {
        --(*index);
    }
}

// Main driver function to decode Huffman Binary Tree
void decodeHuffmanTree(struct HuffmanNode* root, char* str) {
    int i = 0;
    printf("\nDecoded Message: ");
    while (str[i]) {
        if (str[i] == '0') {
            root = root->left;
        } else {
            root = root->right;
        }
        if (isLeaf(root)) {
            printf("%c", root->data);
            root = newHuffmanNode('$');
        }
        ++i;
    }
}

// Driver Function
int main() {
    char data[MAX_CHAR];
    int freq[MAX_CHAR];
    int n;
    printf("Ahoy Matey! Welcome to our hilarious Huffman Encoding Program.\n");
    printf("This program encodes your message using Huffman Coding and makes it harder to interpret.\n");
    printf("Enter the length of your secret message (Characters): ");
    scanf("%d", &n);
    printf("Enter your furtive message: ");
    fflush(stdin);
    fgets(data, n+1, stdin);
    printf("Now, tell us the frequency of each character in your message.\n");
    int i;
    for (i = 0; i < n; ++i) {
        printf("Frequency of '%c': ", data[i]);
        scanf("%d", &freq[i]);
    }
    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, n);
    struct HuffmanNode* root = buildHuffmanTree(data, freq, n, minHeap);
    printf("And the Secret Code is...\n");
    for (i = 0; i < n; ++i) {
        printf("%c", data[i]);
        int j;
        for (j = 0; j < root->code_count; ++j) {
            if (root->code[j] == 0) {
                printf("O");
            } else {
                printf("X");
            }
        }
        printf("\n");
    }
    char str[MAX_CHAR];
    printf("Enter your secret message in binary: ");
    fflush(stdin);
    fgets(str, MAX_CHAR, stdin);
    decodeHuffmanTree(root, str);
    return 0;
}