//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Huffman Coding Tree Node
struct HCNode {
    int frequency;
    char symbol;
    struct HCNode* left;
    struct HCNode* right;
};

// create a new Huffman Coding Tree Node with the given symbol and frequency
struct HCNode* newHCNode(char symbol, int frequency) {
    struct HCNode* node = (struct HCNode*) malloc(sizeof(struct HCNode));
    node->left = NULL;
    node->right = NULL;
    node->symbol = symbol;
    node->frequency = frequency;
    
    return node;
}

// compare function for qsort
int cmp(const void* a, const void* b) {
    struct HCNode** nodeA = (struct HCNode**) a;
    struct HCNode** nodeB = (struct HCNode**) b;
    
    return ((*nodeA)->frequency - (*nodeB)->frequency);
}

// print the Huffman Coding Tree
void printHCNode(struct HCNode* node, int level, char* path) {
    if (node == NULL) return;
    
    printf("%*s%c:%s\n", level*2, "", node->symbol, path);
    
    char* leftPath = (char*) malloc(sizeof(char) * strlen(path) + 2);
    strcpy(leftPath, path);
    strcat(leftPath, "0");
    printHCNode(node->left, level+1, leftPath);
    
    char* rightPath = (char*) malloc(sizeof(char) * strlen(path) + 2);
    strcpy(rightPath, path);
    strcat(rightPath, "1");
    printHCNode(node->right, level+1, rightPath);
}

// encode message using Huffman Coding Tree
char* HuffmanEncoding(char* message, struct HCNode* root) {
    int messageLength = strlen(message);
    char* encodedMessage = (char*) malloc(sizeof(char) * messageLength);
    
    for(int i = 0; i < messageLength; i++) {
        char* path = (char*) malloc(sizeof(char) * messageLength);
        struct HCNode* current = root;
        
        while (current->symbol != message[i]) {
            if (current->left && strchr(current->left->symbol, message[i])) {
                strcat(path, "0");
                current = current->left;
            } else if (current->right && strchr(current->right->symbol, message[i])) {
                strcat(path, "1");
                current = current->right;
            }
        }
        
        strcat(encodedMessage, path);
    }
    
    return encodedMessage;
}

// decode message using Huffman Coding Tree
char* HuffmanDecoding(char* encodedMessage, struct HCNode* root) {
    int encodedMessageLength = strlen(encodedMessage);
    char* decodedMessage = (char*) malloc(sizeof(char) * encodedMessageLength + 1);
    struct HCNode* current = root;
    
    for(int i = 0; i < encodedMessageLength; i++) {
        if (current->left == NULL && current->right == NULL) {
            strcat(decodedMessage, &current->symbol);
            current = root;
        }
        
        if (encodedMessage[i] == '0') {
            current = current->left;
        } else if (encodedMessage[i] == '1') {
            current = current->right;
        }
    }
    
    strcat(decodedMessage, &current->symbol);
    
    return decodedMessage;
}

// Huffman Coding function
char* HuffmanCoding(char* message) {
    int messageLength = strlen(message);
    struct HCNode** frequencyTable = (struct HCNode**) malloc(sizeof(struct HCNode*) * messageLength);
    
    //initialize frequency tables
    int numNodes = 0;
    for(int i = 0; i < messageLength; i++) {
        int j;
        for(j = 0; j < numNodes; j++) {
            if (frequencyTable[j]->symbol == message[i]) {
                frequencyTable[j]->frequency++;
                break;
            }
        }
        
        if (j == numNodes) {
            struct HCNode* node = newHCNode(message[i], 1);
            frequencyTable[numNodes++] = node;
        }
    }
    
    // create Huffman Coding Tree
    while (numNodes > 1) {
        qsort(frequencyTable, numNodes, sizeof(struct HCNode*), cmp);
        struct HCNode* node = newHCNode('\0', frequencyTable[0]->frequency + frequencyTable[1]->frequency);
        node->left = frequencyTable[0];
        node->right = frequencyTable[1];
        
        frequencyTable[0] = node;
        frequencyTable[1] = frequencyTable[numNodes - 1];
        
        numNodes--;
    }
    
    printf("\n---Huffman Coding Tree---\n");
    printHCNode(frequencyTable[0], 0, "");
    
    //encode message
    char* encodedMessage = HuffmanEncoding(message, frequencyTable[0]);
    printf("\nEncoded Message: %s\n", encodedMessage);
    
    //decode message
    char* decodedMessage = HuffmanDecoding(encodedMessage, frequencyTable[0]);
    printf("\nDecoded Message: %s\n", decodedMessage);
    
    return encodedMessage;
}

// test function
void runHuffmanCoding() {
    char* message = "Huffman Coding is cool!";
    
    printf("Original Message: %s\n", message);
    
    char* encodedMessage = HuffmanCoding(message);
    
    free(encodedMessage);
}

int main() {
    runHuffmanCoding();
    
    return 0;
}