//FormAI DATASET v1.0 Category: Compression algorithms ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to store the compressed data
typedef struct {
    char* compressedData;
    int compressedLength;
} CompressedData;

// Compress the given data using RLE algorithm
CompressedData runLengthEncoding(char* data, int dataSize) {
    CompressedData compressedData;
    compressedData.compressedData = (char*) malloc(sizeof(char) * (dataSize * 2));
    compressedData.compressedLength = 0;

    int count = 1;
    char currentChar = data[0];
    for (int i = 1; i < dataSize; i++) {
        if (data[i] == currentChar) {
            count++;
        } else {
            // Store the count and currentChar in compressed data
            compressedData.compressedData[compressedData.compressedLength++] = count;
            compressedData.compressedData[compressedData.compressedLength++] = currentChar;

            count = 1;
            currentChar = data[i];
        }
    }

    // Store the last count and currentChar in compressed data
    compressedData.compressedData[compressedData.compressedLength++] = count;
    compressedData.compressedData[compressedData.compressedLength++] = currentChar;

    return compressedData;
}

// Decompress the given data using RLE algorithm
char* runLengthDecoding(char* compressedData, int compressedLength) {
    char* data = (char*) malloc(sizeof(char) * (compressedLength * 2));
    int dataIndex = 0;

    for (int i = 0; i < compressedLength; i += 2) {
        int count = compressedData[i];
        char currentChar = compressedData[i + 1];

        for (int j = 0; j < count; j++) {
            data[dataIndex++] = currentChar;
        }
    }

    return data;
}

int main() {
    char* data = "AAABBBCCCCDDDDDDEFGGG";
    int dataSize = strlen(data);

    // Compress the data
    CompressedData compressedData = runLengthEncoding(data, dataSize);

    // Print the compressed data
    printf("Compressed Data: ");
    for (int i = 0; i < compressedData.compressedLength; i++) {
        printf("%d%c", compressedData.compressedData[i], i % 2 == 0 ? 'x' : ' ');
    }
    printf("\n");

    // Decompress the data
    char* decompressedData = runLengthDecoding(compressedData.compressedData, compressedData.compressedLength);

    // Print the decompressed data
    printf("Decompressed Data: %s\n", decompressedData);

    return 0;
}