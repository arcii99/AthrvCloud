//FormAI DATASET v1.0 Category: Compression algorithms ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
#include <pthread.h>

#define MAX_SIZE 100

// data structure to represent compressed data
struct CompressedData {
    int originalSize; // size of original uncompressed data
    int compressedSize; // size of compressed data in bytes
    char* data; // pointer to compressed data
};

// function to compress data using a unique algorithm
void* compressData(void* args) {

    // get inputs from args
    char* originalData = ((char**)args)[0];
    int dataSize = *(int*)((char**)args)[1];
    int windowSize = *(int*)((char**)args)[2];

    // declare variables
    int i = 0, j = 0, k = 0;
    int start = 0, end = start + windowSize;
    int repeatedChar = 0, repeatCount = 0;
    bool isRepeated = false;
    char* compressedData = malloc(MAX_SIZE);
    char* compressedDataPtr = compressedData;

    // loop through original data
    while (start < dataSize) {

        // check if current window has repeated characters
        for (i = start; i < end; i++) {
            isRepeated = true;
            for (j = i + 1, k = 1; j < end; j++, k++) {
                if (originalData[i] != originalData[j]) {
                    isRepeated = false;
                    break;
                }
            }
            if (isRepeated) {
                repeatedChar = originalData[i];
                repeatCount = k;
                break;
            }
        }

        // if repeated characters found, write to compressed data
        if (isRepeated) {
            *compressedDataPtr++ = '~';
            *compressedDataPtr++ = (char)repeatedChar;
            *compressedDataPtr++ = (char)floor(log10(repeatCount)) + 48;
            while (repeatCount > 0) {
                *compressedDataPtr++ = (char)(repeatCount % 10) + 48;
                repeatCount /= 10;
            }
            compressedDataPtr--;
        } else {
            // write single character to compressed data
            *compressedDataPtr++ = originalData[start];
        }

        // move window
        start += windowSize;
        if (start >= dataSize) {
            break;
        }
        end = start + windowSize;
        if (end > dataSize) {
            end = dataSize;
        }
    }

    // create compressed data struct and return
    struct CompressedData* result = malloc(sizeof(struct CompressedData));
    result->compressedSize = (int)(compressedDataPtr - compressedData);
    result->originalSize = dataSize;
    result->data = compressedData;
    return result;
}

int main() {

    char originalData[MAX_SIZE] = "aabaaaaabcdbbcbcababbdbcaaaaaabaa";
    int dataSize = strlen(originalData);
    int windowSize = 3;

    // create thread for compressing data
    pthread_t threadID;
    void* args[3] = {originalData, &dataSize, &windowSize};
    pthread_create(&threadID, NULL, &compressData, args);

    // wait for thread to finish and get compressed data struct
    struct CompressedData* compressedData;
    pthread_join(threadID, &compressedData);

    // print original and compressed data
    printf("Original data: %s\n", originalData);
    printf("Original size: %d bytes\n", dataSize);
    printf("Compressed data: %s\n", compressedData->data);
    printf("Compressed size: %d bytes\n", compressedData->compressedSize);

    // free memory allocated for compressed data struct and data
    free(compressedData->data);
    free(compressedData);
    return 0;
}