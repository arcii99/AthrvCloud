//FormAI DATASET v1.0 Category: Compression algorithms ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Huffman node structure
struct MinHeapNode {
    char data;
    int freq;
    struct MinHeapNode *left, *right;
};

// A priority queue / min heap structure
struct MinHeap {
    int size;
    int capacity;
    struct MinHeapNode **array;
};

// Huffman function declarations
struct MinHeapNode* newNode(char, int);
struct MinHeap* createMinHeap(int);
void swapMinHeapNode(struct MinHeapNode**, struct MinHeapNode**);
void minHeapify(struct MinHeap*, int);
int isSizeOne(struct MinHeap*);
struct MinHeapNode* extractMin(struct MinHeap*);
void insertMinHeap(struct MinHeap*, struct MinHeapNode*);
void printArr(int arr[], int n);
int isLeaf(struct MinHeapNode*);
struct MinHeap* buildMinHeap(char data[], int freq[], int size);
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size);
void encode(struct MinHeapNode*, int arr[], int top, int codes[][256]);
void decode(struct MinHeapNode*, int* bits, int n);
void printCodes(char data[], int freq[], int size);

int main() {
    // Input strings to be compressed
    char str1[] = "aaaaabbbbbcccccdddddeeeee";
    char str2[] = "The quick brown fox jumps over the lazy dog.";
    char str3[] = "Hello World!";
    char str4[] = "Compression algorithms aim to reduce the size of data in order to save storage space and increase efficiency in transmission.";

    // Get lengths of input strings
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    int len3 = strlen(str3);
    int len4 = strlen(str4);

    // Arrays to hold frequency and characters of input strings
    char data1[len1];
    int freq1[len1];
    char data2[len2];
    int freq2[len2];
    char data3[len3];
    int freq3[len3];
    char data4[len4];
    int freq4[len4];

    // Populate frequency and character arrays for each input string
    int i, j, k, found;
    for (i = 0; i < len1; i++) {
        found = 0;
        for (j = 0; j <= i; j++) {
            if (data1[j] == str1[i]) {
                freq1[j]++;
                found = 1;
                break;
            }
        }
        if (found == 0) {
            data1[i] = str1[i];
            freq1[i] = 1;
        }
    }
    for (i = 0; i < len2; i++) {
        found = 0;
        for (j = 0; j <= i; j++) {
            if (data2[j] == str2[i]) {
                freq2[j]++;
                found = 1;
                break;
            }
        }
        if (found == 0) {
            data2[i] = str2[i];
            freq2[i] = 1;
        }
    }
    for (i = 0; i < len3; i++) {
        found = 0;
        for (j = 0; j <= i; j++) {
            if (data3[j] == str3[i]) {
                freq3[j]++;
                found = 1;
                break;
            }
        }
        if (found == 0) {
            data3[i] = str3[i];
            freq3[i] = 1;
        }
    }
    for (i = 0; i < len4; i++) {
        found = 0;
        for (j = 0; j <= i; j++) {
            if (data4[j] == str4[i]) {
                freq4[j]++;
                found = 1;
                break;
            }
        }
        if (found == 0) {
            data4[i] = str4[i];
            freq4[i] = 1;
        }
    }

    // Build Huffman trees for each input string
    struct MinHeapNode *root1, *root2, *root3, *root4;
    root1 = buildHuffmanTree(data1, freq1, len1);
    root2 = buildHuffmanTree(data2, freq2, len2);
    root3 = buildHuffmanTree(data3, freq3, len3);
    root4 = buildHuffmanTree(data4, freq4, len4);

    // Display codes for each input string
    printf("Huffman Codes for Input String 1:\n");
    printCodes(data1, freq1, len1);
    printf("\nHuffman Codes for Input String 2:\n");
    printCodes(data2, freq2, len2);
    printf("\nHuffman Codes for Input String 3:\n");
    printCodes(data3, freq3, len3);
    printf("\nHuffman Codes for Input String 4:\n");
    printCodes(data4, freq4, len4);

    // Generate binary strings for each input string
    int codes1[256][256], codes2[256][256], codes3[256][256], codes4[256][256];
    int bits1[len1], bits2[len2], bits3[len3], bits4[len4];
    int top1 = 0, top2 = 0, top3 = 0, top4 = 0;
    encode(root1, bits1, top1, codes1);
    encode(root2, bits2, top2, codes2);
    encode(root3, bits3, top3, codes3);
    encode(root4, bits4, top4, codes4);
    int binary1[256 * len1], binary2[256 * len2], binary3[256 * len3], binary4[256 * len4];
    int index1 = 0, index2 = 0, index3 = 0, index4 = 0;
    for (i = 0; i < len1; i++) {
        for (j = 0; j < strlen((char*)codes1[data1[i]]); j++) {
            binary1[index1++] = codes1[data1[i]][j] - '0';
        }
    }
    for (i = 0; i < len2; i++) {
        for (j = 0; j < strlen((char*)codes2[data2[i]]); j++) {
            binary2[index2++] = codes2[data2[i]][j] - '0';
        }
    }
    for (i = 0; i < len3; i++) {
        for (j = 0; j < strlen((char*)codes3[data3[i]]); j++) {
            binary3[index3++] = codes3[data3[i]][j] - '0';
        }
    }
    for (i = 0; i < len4; i++) {
        for (j = 0; j < strlen((char*)codes4[data4[i]]); j++) {
            binary4[index4++] = codes4[data4[i]][j] - '0';
        }
    }

    // Print binary strings for each input string
    printf("\nBinary String for Input String 1:\n");
    for (i = 0; i < index1; i++) {
        printf("%d", binary1[i]);
    }
    printf("\n\nBinary String for Input String 2:\n");
    for (i = 0; i < index2; i++) {
        printf("%d", binary2[i]);
    }
    printf("\n\nBinary String for Input String 3:\n");
    for (i = 0; i < index3; i++) {
        printf("%d", binary3[i]);
    }
    printf("\n\nBinary String for Input String 4:\n");
    for (i = 0; i < index4; i++) {
        printf("%d", binary4[i]);
    }

    // Convert binary strings back to original input strings
    int n1 = index1, n2 = index2, n3 = index3, n4 = index4;
    printf("\n\nDecoded String for Input String 1: ");
    decode(root1, binary1, n1);
    printf("\nDecoded String for Input String 2: ");
    decode(root2, binary2, n2);
    printf("\nDecoded String for Input String 3: ");
    decode(root3, binary3, n3);
    printf("\nDecoded String for Input String 4: ");
    decode(root4, binary4, n4);

    return 0;
}

// Function to create new Huffman tree node
struct MinHeapNode* newNode(char data, int freq) {
    struct MinHeapNode* node = (struct MinHeapNode*) malloc(sizeof(struct MinHeapNode));
    node->left = node->right = NULL;
    node->data = data;
    node->freq = freq;
    return node;
}

// Function to create new min heap
struct MinHeap* createMinHeap(int capacity) {
    struct MinHeap* minHeap = (struct MinHeap*) malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**) malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

// Function to swap two min heap nodes
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b) {
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Function to heapify min heap
void minHeapify(struct MinHeap* minHeap, int idx) {
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
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

// Function to check if size of heap is one
int isSizeOne(struct MinHeap* minHeap) {
    return (minHeap->size == 1);
}

// Function to extract minimum element from min heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap) {
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Function to insert node into min heap
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode) {
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}

// Function to print Huffman codes from the root of Huffman tree
void printArr(int arr[], int n) {
    int i;
    for (i = 0; i < n; ++i) {
        printf("%d", arr[i]);
    }
    printf("\n");
}

// Function to check if node is a leaf
int isLeaf(struct MinHeapNode* root) {
    return !(root->left) && !(root->right);
}

// Function to build min heap based on input string frequency and character data
struct MinHeap* buildMinHeap(char data[], int freq[], int size) {
    struct MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i) {
        minHeap->array[i] = newNode(data[i], freq[i]);
    }
    minHeap->size = size;
    int n = size - 1;
    for (int i = (n - 1) / 2; i >= 0; --i) {
        minHeapify(minHeap, i);
    }
    return minHeap;
}

// Function to build the Huffman tree based on min heap
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size) {
    struct MinHeapNode *left, *right, *top;
    struct MinHeap* minHeap = buildMinHeap(data, freq, size);
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

// Function to encode input string based on Huffman tree
void encode(struct MinHeapNode* root, int arr[], int top, int codes[][256]) {
    if (root->left) {
        arr[top] = 0;
        encode(root->left, arr, top + 1, codes);
    }
    if (root->right) {
        arr[top] = 1;
        encode(root->right, arr, top + 1, codes);
    }
    if (isLeaf(root)) {
        arr[top] = '\0';
        int i = 0;
        while (codes[(int)root->data][i] != -1) {
            i++;
        }
        for (int j = 0; j < top; j++) {
            codes[(int)root->data][i + j] = arr[j];
        }
        codes[(int)root->data][i + top] = -1;
    }
}

// Function to decode input string based on Huffman tree
void decode(struct MinHeapNode* root, int* bits, int n) {
    struct MinHeapNode* curr = root;
    for (int i = 0; i < n; i++) {
        if (bits[i] == 0) {
            curr = curr->left;
        } else {
            curr = curr->right;
        }
        if (isLeaf(curr)) {
            printf("%c", curr->data);
            curr = root;
        }
    }
}

// Function to print Huffman codes for input string
void printCodes(char data[], int freq[], int size) {
    int bits[size];
    int codes[256][256];
    struct MinHeapNode* root = buildHuffmanTree(data, freq, size);
    encode(root, bits, 0, codes);
    for (int i = 0; i < size; ++i) {
        printf("%c: ", data[i]);
        printArr(codes[(int)data[i]], strlen((char*)codes[(int)data[i]]));
    }
}