//FormAI DATASET v1.0 Category: Compression algorithms ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHUNK_SIZE 1024 // Define the chunk size for compression

// A function to compress the input data
int compress(char *input, char *output) {
    int count = 1, i, j, len = strlen(input);
    char prev = input[0];

    for (i = 1, j = 0; i < len; ++i) {
        if (input[i] == prev) {
            ++count;
        } else {
            output[j++] = prev;
            sprintf(&output[j], "%d", count);
            j += strlen(&output[j]);
            prev = input[i];
            count = 1;
        }
    }

    // Add the last character
    output[j++] = prev;
    sprintf(&output[j], "%d", count);
    j += strlen(&output[j]);
    output[j] = '\0';

    return j;
}

// A function to decompress the input data
int decompress(char *input, char *output) {
    int i, j, k, len = strlen(input);
    char prev = input[0];
    char count[CHUNK_SIZE] = {'\0'};

    for (i = 1, j = 0, k = 0; i < len; ++i) {
        if (input[i] >= '0' && input[i] <= '9') {
            count[k++] = input[i];
        } else {
            int num = atoi(count);
            for (int n = 0; n < num; ++n) {
                output[j++] = prev;
            }
            prev = input[i];
            memset(count, '\0', CHUNK_SIZE);
            k = 0;
        }
    }

    // Add the last character
    int num = atoi(count);
    for (int n = 0; n < num; ++n) {
        output[j++] = prev;
    }
    output[j] = '\0';

    return j;
}

int main() {
    char input[] = "aaabbbcddddd";
    char compressed[CHUNK_SIZE] = {'\0'};   // Initialize the compressed buffer
    char decompressed[CHUNK_SIZE] = {'\0'}; // Initialize the decompressed buffer

    // Compress the input data
    int len = compress(input, compressed);

    printf("Compressed data: %s\n", compressed);

    // Decompress the compressed data
    decompress(compressed, decompressed);

    printf("Original data: %s\n", decompressed);

    return 0;
}