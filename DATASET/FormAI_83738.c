//FormAI DATASET v1.0 Category: Compression algorithms ; Style: shape shifting
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_CHARS 256
#define MAX_LEN 1000

// Function to perform run-length encoding compression
char* runLengthEncoding(char* str)
{
    int n = strlen(str);
    int i, j, count;

    char* result = (char*)malloc(sizeof(char) * (n + 1));
    int resultIndex = 0;

    for (i = 0; i < n; i++) {
        result[resultIndex++] = str[i];

        count = 1;
        while (i < n - 1 && str[i] == str[i + 1]) {
            count++;
            i++;
        }

        if (count > 1) {
            char temp[10];
            sprintf(temp, "%d", count);
            for (j = 0; temp[j] != '\0'; j++) {
                result[resultIndex++] = temp[j];
            }
        }
    }

    result[resultIndex] = '\0';

    return result;
}

// Function to perform Huffman compression
char* huffmanCompression(char* str)
{
    int freq[MAX_CHARS] = { 0 };
    int n = strlen(str), i;

    for (i = 0; i < n; i++) {
        freq[str[i]]++;
    }

    // Create a min heap tree and build Huffman tree
    buildHuffmanTree(freq);

    // Encode the string using Huffman codes
    char* result = (char*)malloc(sizeof(char) * (MAX_LEN + 1));
    encodeString(str, result);
    return result;
}

// ASCII characters and their frequencies
char charArray[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
int charFreq[] = { 5, 9, 12, 13, 16, 45 };
int charArrayLength = sizeof(charFreq) / sizeof(charFreq[0]);

// Min heap node
struct MinHeapNode {
    char data;
    unsigned freq;
    struct MinHeapNode *left, *right;
};

// Min heap (priority queue)
struct MinHeap {
    unsigned size;
    unsigned capacity;
    struct MinHeapNode** array;
};

// Function to create a new min heap node
struct MinHeapNode* newMinHeapNode(char data, unsigned freq)
{
    struct MinHeapNode* temp = (struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
    return temp;
}

// Function to create a new min heap (priority queue)
struct MinHeap* createMinHeap(unsigned capacity)
{
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHeapNode**)malloc(minHeap->capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

// Function to swap two min heap nodes
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b)
{
    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

// Function to perform down-heapification on min heap
void minHeapify(struct MinHeap* minHeap, int idx)
{
    int smallest, left, right;
    smallest = idx;
    left = 2 * idx + 1;
    right = 2 * idx + 2;

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

// Function to check if min heap contains only one node
int isSizeOne(struct MinHeap* minHeap)
{
    return (minHeap->size == 1);
}

// Function to perform extraction of minimum frequency node from min heap
struct MinHeapNode* extractMin(struct MinHeap* minHeap)
{
    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

// Function to insert new node into min heap
void insertMinHeap(struct MinHeap* minHeap, struct MinHeapNode* minHeapNode)
{
    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = minHeapNode;
}

// Function to build min heap tree
void buildHuffmanTree(int freq[])
{
    struct MinHeapNode *left, *right, *top;
    struct MinHeap* minHeap = createMinHeap(charArrayLength);

    for (int i = 0; i < charArrayLength; ++i) {
        minHeap->array[i] = newMinHeapNode(charArray[i], freq[i]);
    }

    minHeap->size = charArrayLength;

    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = newMinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }
}

// Function to decode string using Huffman codes
void decodeString(struct MinHeapNode* root, char* s, int* index)
{
    if (!root) {
        return;
    }

    if (root->data != '$') {
        s[*index] = root->data;
        (*index)++;
    }

    decodeString(root->left, s, index);
    decodeString(root->right, s, index);
}

// Function to perform encoding of input string using Huffman codes
void encodeString(char* str, char* result)
{
    struct MinHeapNode *left, *right, *top;
    int i;
    struct MinHeap* minHeap = createMinHeap(charArrayLength);

    for (i = 0; i < charArrayLength; ++i) {
        minHeap->array[i] = newMinHeapNode(charArray[i], charFreq[i]);
    }

    minHeap->size = charArrayLength;

    while (!isSizeOne(minHeap)) {
        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = newMinHeapNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    struct MinHeapNode* root = extractMin(minHeap);
    char codes[MAX_CHARS] = { 0 }, bits[MAX_LEN] = { 0 };

    // Generate Huffman codes for each ASCII character
    generateCodes(root, codes, 0);

    int n = strlen(str), index = 0;

    // Encode the input string using Huffman codes
    for (i = 0; i < n; ++i) {
        strcpy(&bits[index], codes[str[i]]);
        index += strlen(codes[str[i]]);
    }

    bits[index] = '\0';

    // Decode the encoded string for verification
    index = 0;
    decodeString(root, result, &index);
}

// Function to generate Huffman codes for each ASCII character
void generateCodes(struct MinHeapNode* root, char *code, int top)
{
    // Assign 0 to left edge and recur if left child exists
    if (root->left) {
        code[top] = '0';
        generateCodes(root->left, code, top + 1);
    }

    // Assign 1 to right edge and recur if right child exists
    if (root->right) {
        code[top] = '1';
        generateCodes(root->right, code, top + 1);
    }

    // Leaf node reached, print Huffman code
    if (!root->left && !root->right) {
        printf("%c: %s\n", root->data, code);
    }
}

// Main function
int main()
{
    char str[MAX_LEN];
    printf("Enter a string to compress: ");
    scanf("%[^\n]s", str);

    printf("\nRun-length encoding:\n");
    char* rle_result = runLengthEncoding(str);
    printf("Compressed string: %s\n", rle_result);

    printf("\nHuffman compression:\n");
    char* huffman_result = huffmanCompression(str);
    printf("Compressed string: %s\n", huffman_result);

    free(rle_result);
    free(huffman_result);

    return 0;
}