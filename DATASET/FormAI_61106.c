//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <pthread.h>
#include <unistd.h>

#define MAX_TREE_HT 100

/* Huffman Tree node */
struct HuffmanNode {
    char data;
    unsigned freq;
    struct HuffmanNode *left, *right;
};

/* Huffman Tree */
struct HuffmanTree {
    struct HuffmanNode *root;
};

/* Huffman Code node */
struct HuffmanCodeNode {
    char data;
    char *code;
};

/* Global variables */
struct HuffmanTree *huffmanTree;
struct HuffmanCodeNode *huffmanCodes;
int code_count = 0;

/* Asynchronous function to create Huffman Tree */
void *createHuffmanTree(void *arg) {
    char *data = (char*) arg;
    int freq[256] = {0};
    
    // Calculate frequency of each character in data
    for (int i=0; data[i]!='\0'; i++) {
        freq[(int) data[i]]++;
    }
    
    // Create a list of Huffman Tree nodes
    struct HuffmanNode *treeNode[256];
    int count = 0;
    for (int i=0; i<256; i++) {
        if (freq[i] > 0) {
            treeNode[count] = (struct HuffmanNode *) malloc(sizeof(struct HuffmanNode));
            treeNode[count]->data = (char) i;
            treeNode[count]->freq = freq[i];
            treeNode[count]->left = NULL;
            treeNode[count]->right = NULL;
            count++;
        }
    }

    // Build Huffman Tree
    while (count > 1) {
        // Find two nodes with lowest frequency
        int min1, min2;
        min1 = min2 = 999999999;
        for (int i=0; i<count; i++) {
            if (treeNode[i]->freq < min1) {
                min2 = min1;
                min1 = treeNode[i]->freq;
            } else if (treeNode[i]->freq < min2) {
                min2 = treeNode[i]->freq;
            }
        }

        // Create new node as parent of two nodes with lowest frequency
        struct HuffmanNode *newNode = (struct HuffmanNode *) malloc(sizeof(struct HuffmanNode));
        newNode->data = '\0';
        newNode->freq = min1 + min2;
        newNode->left = NULL;
        newNode->right = NULL;

        // Assign the two nodes as left and right child of new node
        for (int i=0; i<count; i++) {
            if (treeNode[i]->freq == min1 || treeNode[i]->freq == min2) {
                newNode->left = treeNode[i];
                treeNode[i] = NULL;
            } else if (treeNode[i] != NULL) {
                newNode->right = treeNode[i];
            }
        }
        treeNode[0] = newNode;

        // Decrease count of nodes in tree
        count--;
    }
    
    huffmanTree->root = treeNode[0];
    return NULL;
}

/* Asynchronous function to generate Huffman Codes */
void *generateHuffmanCodes(void *arg) {
    struct HuffmanNode *root = (struct HuffmanNode *) arg;
    char code[MAX_TREE_HT];
    generateCodes(root, code, 0);
    return NULL;
}

/* Function to generate Huffman Code for each character in Huffman Tree */
void generateCodes(struct HuffmanNode *node, char *code, int level) {
    if (node == NULL) {
        return;
    }
    if (node->left != NULL) {
        code[level] = '0';
        generateCodes(node->left, code, level+1);
    }
    if (node->right != NULL) {
        code[level] = '1';
        generateCodes(node->right, code, level+1);
    }
    if (node->left == NULL && node->right == NULL) {
        huffmanCodes[code_count].data = node->data;
        huffmanCodes[code_count].code = (char *) malloc(sizeof(char) * (level + 1));
        memcpy(huffmanCodes[code_count].code, code, level+1);
        code_count++;
    }
}

/* Function to encode a string using Huffman Codes */
char *encodeString(char *input) {
    int len = strlen(input);
    char *output = (char *) malloc(sizeof(char) * (MAX_TREE_HT * len));
    output[0] = '\0';
    
    // Traverse input string and append Huffman Codes to output
    for (int i=0; i<len; i++) {
        for (int j=0; j<code_count; j++) {
            if (huffmanCodes[j].data == input[i]) {
                strcat(output, huffmanCodes[j].code);
                break;
            }
        }
    }
    return output;
}

int main() {
    // Input string to encode
    char *input = "Hello, World!";

    // Create Huffman Tree asynchronously
    huffmanTree = (struct HuffmanTree *) malloc(sizeof(struct HuffmanTree));
    pthread_t treeThread;
    pthread_create(&treeThread, NULL, createHuffmanTree, (void *) input);

    // Generate Huffman Codes asynchronously
    pthread_t codeThread;
    pthread_create(&codeThread, NULL, generateHuffmanCodes, (void *) huffmanTree->root);

    pthread_join(treeThread, NULL);
    pthread_join(codeThread, NULL);

    // Encode input string using Huffman Codes and print output
    char *output = encodeString(input);
    printf("Input String: %s\nHuffman Encoded String: %s\n", input, output);

    return 0;
}