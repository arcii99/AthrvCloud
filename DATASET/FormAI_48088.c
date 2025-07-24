//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: decentralized
// Huffman coding implementation in C using decentralized approach

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// defining maximum size of a character
#define MAX_CHAR 256

// defining structure for each node of Huffman tree
struct node {
    char data;
    int freq;
    struct node *left, *right;
};

// function to create a new node in Huffman tree
struct node* createNode(char data, int freq) {
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->freq = freq;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// function to compare two nodes based on their frequency
int compareNodes(void* a, void* b) {
    struct node** nodeA = (struct node**)a;
    struct node** nodeB = (struct node**)b;
    return (*nodeA)->freq - (*nodeB)->freq;
}

// function to build a Huffman tree and return root node
struct node* buildHuffmanTree(char data[], int freq[], int size) {
    struct node **nodeArr = (struct node**)malloc(sizeof(struct node*) * size);
    for (int i = 0; i < size; ++i)
        nodeArr[i] = createNode(data[i], freq[i]);

    int count = size;
    while (count > 1) {
        qsort(nodeArr, count, sizeof(struct node*), compareNodes);
        struct node* left = nodeArr[0];
        struct node* right = nodeArr[1];
        int sum = left->freq + right->freq;
        struct node* newNode = createNode('\0', sum);
        newNode->left = left;
        newNode->right = right;

        nodeArr[0] = newNode;
        nodeArr[1] = nodeArr[count-1];
        --count;
    }

    return nodeArr[0];
}

// function to print Huffman codes for each character
void printHuffmanCodes(struct node* root, int arr[], int top) {
    if (root->left) {
        arr[top] = 0;
        printHuffmanCodes(root->left, arr, top+1);
    }
    if (root->right) {
        arr[top] = 1;
        printHuffmanCodes(root->right, arr, top+1);
    }
    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; ++i)
            printf("%d", arr[i]);
        printf("\n");
    }
}

int main() {
    // input string
    char str[] = "Huffman coding is a data compression algorithm.";

    int freq[MAX_CHAR] = {0};
    int size = 0;
    // calculate frequency of each character
    for (int i = 0; str[i] != '\0'; ++i) {
        ++freq[str[i]];
        ++size;
    }

    char data[MAX_CHAR] = {0};
    int index = 0;
    // create array of non-zero frequency characters
    for (int i = 0; i < MAX_CHAR; ++i) {
        if (freq[i] > 0) {
            data[index++] = i;
        }
    }

    // build Huffman tree
    struct node* root = buildHuffmanTree(data, freq, index);

    // print Huffman codes for each character
    int arr[MAX_CHAR] = {0};
    printHuffmanCodes(root, arr, 0);

    return 0;
}