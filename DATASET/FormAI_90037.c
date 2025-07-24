//FormAI DATASET v1.0 Category: Compression algorithms ; Style: multi-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

#define MAX_CHARACTERS 256    // Max number of ASCII characters

/* Structure of a node in the Huffman tree */
struct huffmanNode
{
    char character;
    int frequency;
    struct huffmanNode *left, *right;
};

/* Structure containing the data of each thread */
struct threadData
{
    char *inputString;
    int start, end;
    int frequency[MAX_CHARACTERS];
};

/* Function protypes */
struct huffmanNode * createHuffmanTree(struct huffmanNode *nodeArray[], int n);
void * computeFrequency(void *tData);
void * buildHuffmanTree(void *tData);
char * compressString(char *inputString, struct huffmanNode *root);
void destroyHuffmanTree(struct huffmanNode *root);

int main()
{
    /* Input string */
    char inputString[] = "Hello Huffman Encoding!";
    printf("Input Data: %s\n", inputString);

    int length = strlen(inputString);

    /* Split work between threads */
    pthread_t threads[2];
    struct threadData tData[2];

    int splitIndex = length / 2;

    /* Thread 1 computes frequency counts */
    tData[0].inputString = inputString;
    tData[0].start = 0;
    tData[0].end = splitIndex - 1;
    memset(tData[0].frequency, 0, sizeof(tData[0].frequency));

    /* Thread 2 computes frequency counts */
    tData[1].inputString = inputString;
    tData[1].start = splitIndex;
    tData[1].end = length - 1;
    memset(tData[1].frequency, 0, sizeof(tData[1].frequency));

    /* Run threads */
    for(int i = 0; i < 2; i++)
    {
        int rc = pthread_create(&threads[i], NULL, computeFrequency, &tData[i]);
        if (rc)
        {
            printf("Error creating thread.\n");
            exit(1);
        }
    }

    /* Wait for threads to finish */
    for(int i = 0; i < 2; i++)
    {
        pthread_join(threads[i], NULL);
    }

    /* Combine frequency counts */
    int totalFrequency[MAX_CHARACTERS] = {0};
    for(int i = 0; i < MAX_CHARACTERS; i++)
    {
        totalFrequency[i] = tData[0].frequency[i] + tData[1].frequency[i];
    }

    /* Create Huffman nodes for each non-zero character frequency */
    struct huffmanNode *nodeArray[MAX_CHARACTERS] = {NULL};
    int n = 0;
    for(int i = 0; i < MAX_CHARACTERS; i++)
    {
        if(totalFrequency[i])
        {
            struct huffmanNode *node = malloc(sizeof(struct huffmanNode));
            node->character = i;
            node->frequency = totalFrequency[i];
            node->left = node->right = NULL;
            nodeArray[n] = node;
            n++;
        }
    }

    /* Build Huffman tree */
    struct threadData rootThreadData;
    rootThreadData.frequency[0] = n;    // Store number of nodes in first index

    pthread_t rootThread;
    int rc = pthread_create(&rootThread, NULL, buildHuffmanTree, &rootThreadData);
    if (rc)
    {
        printf("Error creating thread.\n");
        exit(1);
    }

    pthread_join(rootThread, NULL);

    /* Compress input string using Huffman encoding */
    char *compressedString = compressString(inputString, nodeArray[0]);

    printf("Compressed Data: %s\n", compressedString);

    /* Destroy Huffman tree */
    destroyHuffmanTree(nodeArray[0]);

    return 0;
}

/* Compute frequency counts for characters within given range */
void * computeFrequency(void *tData)
{
    struct threadData *data = (struct threadData*) tData;

    for(int i = data->start; i <= data->end; i++)
    {
        data->frequency[(int)data->inputString[i]]++;
    }

    pthread_exit(NULL);
}

/* Build Huffman tree by repeatedly merging nodes with lowest frequency */
void * buildHuffmanTree(void *tData)
{
    struct threadData *data = (struct threadData*) tData;
    int n = data->frequency[0];

    struct huffmanNode *nodeArray[MAX_CHARACTERS];
    int index = n;

    for(int i = 0; i < n; i++)
    {
        nodeArray[i] = malloc(sizeof(struct huffmanNode));
        nodeArray[i]->character = data->frequency[i+1];
        nodeArray[i]->frequency = data->frequency[i+n+1];
        nodeArray[i]->left = nodeArray[i]->right = NULL;
    }

    while(index > 1)
    {
        int min1 = 0;
        int min2 = 1;

        if(nodeArray[min2]->frequency < nodeArray[min1]->frequency)
        {
            int temp = min1;
            min1 = min2;
            min2 = temp;
        }

        for(int i = 2; i < index; i++)
        {
            if(nodeArray[i]->frequency < nodeArray[min1]->frequency)
            {
                min2 = min1;
                min1 = i;
            }
            else if(nodeArray[i]->frequency < nodeArray[min2]->frequency)
            {
                min2 = i;
            }
        }

        struct huffmanNode *newNode = malloc(sizeof(struct huffmanNode));
        newNode->frequency = nodeArray[min1]->frequency + nodeArray[min2]->frequency;
        newNode->left = nodeArray[min1];
        newNode->right = nodeArray[min2];

        nodeArray[min1] = newNode;
        nodeArray[min2] = nodeArray[--index];
    }

    data->frequency[0] = index;
    nodeArray[0]->left = nodeArray[1]->right = NULL;
    data->frequency[1] = (int)nodeArray[0]->character;
    data->frequency[2] = (int)nodeArray[1]->character;
    data->frequency[3] = nodeArray[0]->frequency;

    pthread_exit(NULL);
}

/* Compress input string using Huffman encoding */
char * compressString(char *inputString, struct huffmanNode *root)
{
    int length = strlen(inputString);
    char *outputString = malloc((length+1)*sizeof(char));

    int bitIndex = 0;
    unsigned char bitBuffer = 0;

    for(int i = 0; i < length; i++)
    {
        struct huffmanNode *current = root;
        while(current->left)
        {
            if(inputString[i] & (1 << bitIndex))
            {
                current = current->right;
            }
            else
            {
                current = current->left;
            }

            bitIndex++;
            if(bitIndex == 8)
            {
                bitIndex = 0;
                outputString[(i*8)/sizeof(char)] = bitBuffer;
                bitBuffer = 0;
            }
        }

        if(bitIndex == 0)
        {
            outputString[(i*8)/sizeof(char)] = bitBuffer;
            bitBuffer = 0;
        }

        bitBuffer |= (1 << bitIndex);
    }

    outputString[((length*8)-1)/sizeof(char)+1] = bitBuffer;

    return outputString;
}

/* Recursively destroy Huffman tree nodes */
void destroyHuffmanTree(struct huffmanNode *root)
{
    if(root)
    {
        destroyHuffmanTree(root->left);
        destroyHuffmanTree(root->right);
        free(root);
    }
}