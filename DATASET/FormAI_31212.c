//FormAI DATASET v1.0 Category: Huffman Coding Implementation ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//Struct for Huffman coding tree
struct HuffmanTree {
    char data; //The character represented by the node
    int freq; // The frequency of the character in the input string
    struct HuffmanTree *leftChild, *rightChild; //Left and Right child nodes
};

struct MinHeapNode {
    struct HuffmanTree *node; // The Huffman tree node
    struct MinHeapNode *next; //The Next node in the heap
};

//Utility function to create a new MinHeap node
struct MinHeapNode *createMinHeapNode(struct HuffmanTree* node) {
    struct MinHeapNode *newNode = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));
    newNode->node = node;
    newNode->next = NULL;
    return newNode;
}

//Utility function to create a new Huffman tree node
struct HuffmanTree *createHuffmanNode(char data, int freq) {
    struct HuffmanTree *newNode = (struct HuffmanTree *)malloc(sizeof(struct HuffmanTree));
    newNode->data = data;
    newNode->freq = freq;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}

//Function to merge two trees and return new root
struct HuffmanTree *mergeTrees(struct HuffmanTree *leftChild, struct HuffmanTree *rightChild) {
    struct HuffmanTree *parentNode = createHuffmanNode('$', leftChild->freq + rightChild->freq);
    parentNode->leftChild = leftChild;
    parentNode->rightChild = rightChild;
    return parentNode;
}

//Function to insert new MinHeapNode into minHeap
void insertMinHeap(struct MinHeapNode** headNode, struct HuffmanTree* node) {
    struct MinHeapNode* newNode = createMinHeapNode(node);
    struct MinHeapNode* tempNode = *headNode;
    
    //Handle case where minHeap is empty
    if ((*headNode) == NULL) {
        *headNode = newNode;
        return;
    }
    
    //Case where node is the new head of the list
    if (newNode->node->freq < (*headNode)->node->freq) {
        newNode->next = *headNode;
        *headNode = newNode;
        return;
    }
    
    //Handle case where node is inserted in the middle or at the end of the list
    while (tempNode->next != NULL && tempNode->next->node->freq < newNode->node->freq) {
        tempNode = tempNode->next;
    }
    newNode->next = tempNode->next;
    tempNode->next = newNode;
}

//Utility function to pop the minimum node from the minHeap
struct MinHeapNode* popMinNode(struct MinHeapNode **headNode) {
    struct MinHeapNode *tempNode = (*headNode);
    (*headNode) = (*headNode)->next;
    return tempNode;
}

//Function to build the Huffman Tree
struct HuffmanTree *buildHuffmanTree(char *inputString, int *freqArray, int len) {

    //Create a minHeap and populate it with new HuffmanTree nodes
    struct MinHeapNode *minHeap = NULL;
    for (int i = 0; i < len; i++) {
        struct HuffmanTree *newNode = createHuffmanNode(inputString[i], freqArray[i]);
        insertMinHeap(&minHeap, newNode);
    }
    
    //Construct the tree by iterating though minHeap until only one tree is left
    for (int i = 1; i < len; i++) {
        struct HuffmanTree *leftChild = popMinNode(&minHeap)->node;
        struct HuffmanTree *rightChild = popMinNode(&minHeap)->node;
        struct HuffmanTree *parentNode = mergeTrees(leftChild, rightChild);
        insertMinHeap(&minHeap, parentNode);
    }
    
    //Return the root of the constructed Huffman Tree
    return popMinNode(&minHeap)->node;
}

//Function to print the Huffman Codes for each character
void printHuffmanCodes(struct HuffmanTree *root, int arr[], int top) {
    
    //Recursively traverse the tree and print the codes
    if (root->leftChild) {
        arr[top] = 0;
        printHuffmanCodes(root->leftChild, arr, top + 1);
    }

    if (root->rightChild) {
        arr[top] = 1;
        printHuffmanCodes(root->rightChild, arr, top + 1);
    }
    
    //Print the code when a leaf node is reached
    if (root->leftChild == NULL && root->rightChild == NULL) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++) {
            printf("%d", arr[i]);
        }
        printf("\n");
    }
}

int main() {
    char inputString[] = "This is an example string for Huffman Coding";
    int len = strlen(inputString);
    int freqArray[256] = {0}; //Initialize frequency array to zero
    
    //Count the occurance of each character in the input string
    for (int i = 0; i < len; i++) {
        freqArray[inputString[i]]++;
    }
    
    //Build the Huffman tree using the input string and character frequency array
    struct HuffmanTree *huffmanTreeRoot = buildHuffmanTree(inputString, freqArray, len);

    //Print the Huffman codes for each character
    int arr[256], top = 0;
    printHuffmanCodes(huffmanTreeRoot, arr, top);

    return 0;
}