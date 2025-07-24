//FormAI DATASET v1.0 Category: Compression algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to the Happy Compression Algorithm!\n");
    printf("We will compress your data and make it happy and compact!\n");

    char str[100];

    printf("Please enter the string you want to compress: ");
    scanf("%s", str);

    // Count the frequency of each character in the string
    int freq[256] = {0};
    for(int i=0; i<strlen(str); i++) {
        freq[str[i]]++;
    }

    // Create a priority queue for characters and their frequency
    int queue[256];
    int numElements = 0;
    for(int i=0; i<256; i++) {
        if(freq[i] > 0) {
            queue[numElements++] = i;
        }
    }

    // Sort the priority queue
    for(int i=0; i<numElements-1; i++) {
        for(int j=i+1; j<numElements; j++) {
            if(freq[queue[j]] > freq[queue[i]]) {
                int temp = queue[i];
                queue[i] = queue[j];
                queue[j] = temp;
            }
        }
    }

    // Create the binary tree for the compression algorithm
    struct Node {
        int value;
        struct Node* left;
        struct Node* right;
    };

    struct Node* root = NULL;

    while(numElements > 1) {
        int i = queue[numElements-2];
        int j = queue[numElements-1];

        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->value = -1;
        newNode->left = (struct Node*)malloc(sizeof(struct Node));
        newNode->right = (struct Node*)malloc(sizeof(struct Node));

        newNode->left->value = i;
        newNode->left->left = NULL;
        newNode->left->right = NULL;

        newNode->right->value = j;
        newNode->right->left = NULL;
        newNode->right->right = NULL;

        queue[numElements-2] = -1;
        queue[numElements-1] = -1;

        numElements--;

        int insertIndex = -1;
        for(int k=0; k<numElements; k++) {
            if(freq[queue[k]] < freq[i] + freq[j]) {
                insertIndex = k;
                break;
            }
        }

        if(insertIndex < 0) {
            insertIndex = numElements;
        }

        for(int k=numElements; k>=insertIndex; k--) {
            queue[k+1] = queue[k];
        }

        queue[insertIndex] = -1;
        numElements++;

        for(int k=0; k<numElements; k++) {
            if(queue[k] == -1) {
                queue[k] = insertIndex;
                break;
            }
        }

        root = newNode;
    }

    char encodingTable[256][100];
    for(int i=0; i<256; i++) {
        encodingTable[i][0] = '\0';
    }

    // Generate the encoding table
    void generateEncodingTable(struct Node* node, char* prefix, int prefixLength) {
        if(node->left == NULL && node->right == NULL) {
            sprintf(encodingTable[node->value], "%s", prefix);
            return;
        }

        prefix[prefixLength] = '0';
        prefix[prefixLength+1] = '\0';
        generateEncodingTable(node->left, prefix, prefixLength+1);

        prefix[prefixLength] = '1';
        prefixLength++;
        prefix[prefixLength] = '\0';
        generateEncodingTable(node->right, prefix, prefixLength);

        prefix[prefixLength-1] = '\0';
    }

    char prefix[100] = "";
    generateEncodingTable(root, prefix, 0);

    // Compress the string using the encoding table
    char compressed[1000] = "";
    int compressedIndex = 0;
    for(int i=0; i<strlen(str); i++) {
        strcat(compressed, encodingTable[str[i]]);
        compressedIndex += strlen(encodingTable[str[i]]);
    }

    printf("Your compressed data is: %s\n", compressed);

    // Decompress the string using the binary tree
    char decompressed[100] = "";
    int decompressedIndex = 0;
    struct Node* currentNode = root;
    for(int i=0; i<strlen(compressed); i++) {
        if(currentNode->left == NULL && currentNode->right == NULL) {
            decompressed[decompressedIndex++] = currentNode->value;
            currentNode = root;
        }

        if(compressed[i] == '0') {
            currentNode = currentNode->left;
        } else {
            currentNode = currentNode->right;
        }
    }

    decompressed[decompressedIndex] = '\0';

    printf("Your decompressed data is: %s\n", decompressed);

    printf("Thank you for using the Happy Compression Algorithm!\n");

    return 0;
}