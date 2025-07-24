//FormAI DATASET v1.0 Category: Compression algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

/**
 * Compresses a given string using the RLE algorithm.
 *
 * @param char* source: The source string to compress.
 * @return char*: The compressed string.
 */
char* compress(char* source) {
    int sourceLength = strlen(source);
    if (sourceLength == 0) {
        return "";
    }

    int bufferIndex = 0;
    char* buffer = (char*) malloc(BUFFER_SIZE * sizeof(char));
    if (buffer == NULL) {
        perror("Unable to allocate memory for buffer!");
        exit(EXIT_FAILURE);
    }

    int count = 1;
    for (int i = 1; i <= sourceLength; i++) {
        if (i == sourceLength || source[i] != source[i - 1]) {
            buffer[bufferIndex++] = source[i - 1];
            if (count > 1) {
                int digits = snprintf(NULL, 0, "%d", count);
                if (bufferIndex + digits >= BUFFER_SIZE) {
                    int newSize = BUFFER_SIZE * 2;
                    buffer = (char*) realloc(buffer, newSize * sizeof(char));
                    if (buffer == NULL) {
                        perror("Unable to reallocate memory for buffer!");
                        exit(EXIT_FAILURE);
                    }
                }
                sprintf(&buffer[bufferIndex], "%d", count);
                bufferIndex += digits;
            }
            count = 1;
        } else {
            count++;
        }
    }
    buffer[bufferIndex] = '\0';
    return buffer;
}

/**
 * Decompresses a given string using the RLE algorithm.
 *
 * @param char* source: The source string to decompress.
 * @return char*: The decompressed string.
 */
char* decompress(char* source) {
    int sourceLength = strlen(source);
    if (sourceLength == 0) {
        return "";
    }

    int bufferIndex = 0;
    char* buffer = (char*) malloc(BUFFER_SIZE * sizeof(char));
    if (buffer == NULL) {
        perror("Unable to allocate memory for buffer!");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < sourceLength; i++) {
        if (source[i] >= '0' && source[i] <= '9') {
            int count = source[i] - '0';
            while (source[i + 1] >= '0' && source[i + 1] <= '9') {
                count = count * 10 + (source[i + 1] - '0');
                i++;
            }
            for (int j = 0; j < count - 1; j++) {
                buffer[bufferIndex++] = buffer[bufferIndex - 1];
                if (bufferIndex >= BUFFER_SIZE) {
                    int newSize = BUFFER_SIZE * 2;
                    buffer = (char*) realloc(buffer, newSize * sizeof(char));
                    if (buffer == NULL) {
                        perror("Unable to reallocate memory for buffer!");
                        exit(EXIT_FAILURE);
                    }
                }
            }
        } else {
            buffer[bufferIndex++] = source[i];
            if (bufferIndex >= BUFFER_SIZE) {
                int newSize = BUFFER_SIZE * 2;
                buffer = (char*) realloc(buffer, newSize * sizeof(char));
                if (buffer == NULL) {
                    perror("Unable to reallocate memory for buffer!");
                    exit(EXIT_FAILURE);
                }
            }
        }
    }
    buffer[bufferIndex] = '\0';
    return buffer;
}

int main() {
    char* input = "AAAAAABBBCCDDDDEEEE";
    char* compressed = compress(input);
    char* decompressed = decompress(compressed);

    printf("Input: %s\n", input);
    printf("Compressed: %s\n", compressed);
    printf("Decompressed: %s\n", decompressed);

    free(compressed);
    free(decompressed);

    return 0;
}