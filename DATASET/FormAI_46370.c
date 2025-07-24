//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TREE_NODES 256
#define MAX_CODE_SIZE 256

typedef struct TreeNode *Tree;
typedef struct TreeNode {
    int freq;
    unsigned char symbol;
    Tree left, right;
} TreeNode;

typedef struct PriorityQueueNode *PriorityQueue;
typedef struct PriorityQueueNode {
    Tree node;
    PriorityQueue next;
} PriorityQueueNode;

int frequency[MAX_TREE_NODES];
char codeTable[MAX_TREE_NODES][MAX_CODE_SIZE];
int codeLength[MAX_TREE_NODES];

void calculateFrequency(char *string) {
    int i;
    for (i = 0; i < strlen(string); i++) {
        unsigned char symbol = string[i];
        frequency[symbol]++;
    }
}

Tree buildHuffmanTree() {
    PriorityQueue queue = NULL;
    int i;
    for (i = 0; i < MAX_TREE_NODES; i++) {
        if (frequency[i] > 0) {
            Tree node = (Tree)malloc(sizeof(TreeNode));
            node->freq = frequency[i];
            node->symbol = i;
            node->left = NULL;
            node->right = NULL;
            PriorityQueue qNode = (PriorityQueue)malloc(sizeof(PriorityQueueNode));
            qNode->node = node;
            qNode->next = NULL;
            if (queue == NULL) {
                queue = qNode;
            } else {
                PriorityQueue curr = queue;
                while (curr->next != NULL && curr->next->node->freq <= node->freq) {
                    curr = curr->next;
                }
                qNode->next = curr->next;
                curr->next = qNode;
            }
        }
    }

    while (queue->next != NULL) {
        PriorityQueue first = queue;
        PriorityQueue second = queue->next;
        queue = queue->next->next;

        Tree node = (Tree)malloc(sizeof(TreeNode));
        node->freq = first->node->freq + second->node->freq;
        node->left = first->node;
        node->right = second->node;
        node->symbol = 0;
        PriorityQueue qNode = (PriorityQueue)malloc(sizeof(PriorityQueueNode));
        qNode->node = node;
        qNode->next = NULL;

        if (queue == NULL) {
            queue = qNode;
        } else {
            PriorityQueue curr = queue;
            while (curr->next != NULL && curr->next->node->freq <= node->freq) {
                curr = curr->next;
            }
            qNode->next = curr->next;
            curr->next = qNode;
        }
    }

    return queue->node;
}

void traverseHuffmanTree(Tree node, int code[], int depth) {
    if (node == NULL) {
        return;
    }
    if (node->left == NULL && node->right == NULL) {
        int i;
        for (i = 0; i < depth; i++) {
            codeTable[node->symbol][i] = code[i] + '0';
            codeLength[node->symbol] = depth;
        }
        return;
    }
    code[depth] = 0;
    traverseHuffmanTree(node->left, code, depth+1);
    code[depth] = 1;
    traverseHuffmanTree(node->right, code, depth+1);
}

void encode(char *string, FILE *outputFile) {
    int i;
    for (i = 0; i < strlen(string); i++) {
        fprintf(outputFile,"%s", codeTable[string[i]]);
    }
}

void decode(FILE *inputFile, FILE *outputFile, Tree tree, int remainingBits) {
    Tree curr = tree;
    unsigned char bits;
    while (!feof(inputFile)) {
        bits = fgetc(inputFile);
        int i;
        for (i = 0; i < 8; i++) {
            if (remainingBits == 0) {
                bits = fgetc(inputFile);
                remainingBits = 8;
            }
            if ((bits & (1 << (7 - i))) == 0) {
                curr = curr->left;
            } else {
                curr = curr->right;
            }
            if (curr->left == NULL && curr->right == NULL) {
                fputc(curr->symbol, outputFile);
                curr = tree;
            }
            remainingBits--;
        }
    }
}

int main() {
    char *message = "Huffman coding is a lossless data compression algorithm.";
    FILE *outputFile = fopen("encoded.bin", "wb");
    FILE *inputFile = fopen("encoded.bin", "rb");

    calculateFrequency(message);
    Tree tree = buildHuffmanTree();
    int code[MAX_CODE_SIZE];
    traverseHuffmanTree(tree, code, 0);
    encode(message, outputFile);

    fclose(outputFile);
    outputFile = fopen("encoded.bin", "rb");

    FILE *decodedFile = fopen("decoded.txt", "w");
    int remainingBits = 0;

    decode(inputFile, decodedFile, tree, remainingBits);

    fclose(decodedFile);
    fclose(outputFile);
    fclose(inputFile);

    return 0;
}