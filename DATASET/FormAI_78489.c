//FormAI DATASET v1.0 Category: Compression algorithms ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_BUFFER 1024
#define MAX_COMPRESSED_BUFFER 1024

/* A paranoid compression algorithm that doesn't trust the input */

void compress(char *input, char *output) {

    if (input == NULL || output == NULL) {
        printf("Invalid input");
        return;
    }

    unsigned char buffer[MAX_INPUT_BUFFER];
    unsigned char compressed[MAX_COMPRESSED_BUFFER];

    memset(buffer, 0, MAX_INPUT_BUFFER);
    memset(compressed, 0, MAX_COMPRESSED_BUFFER);

    int i = 0;
    int j = 0;
    int k = 0;

    while (input[i] != '\0') {
    
        if (j == MAX_INPUT_BUFFER) {
            printf("Input buffer overflow");
            return;
        }
        
        if (k == MAX_COMPRESSED_BUFFER) {
            printf("Compressed buffer overflow");
            return;
        }

        unsigned char c = input[i];
        unsigned char byte = 0;

        // paranoid bit manipulation
        byte = byte | ((c & 0x01) << 7);
        byte = byte | ((c & 0x02) << 5);
        byte = byte | ((c & 0x04) << 3);
        byte = byte | ((c & 0x08) << 1);
        byte = byte | ((c & 0x10) >> 1);
        byte = byte | ((c & 0x20) >> 3);
        byte = byte | ((c & 0x40) >> 5);
        byte = byte | ((c & 0x80) >> 7);

        buffer[j++] = byte;

        if (j % 8 == 0) {
            unsigned char to_compress = buffer[0];
            for (int l = 1; l < 8; l++) {
                to_compress = to_compress ^ buffer[l];
            }
            compressed[k++] = to_compress;
            memset(buffer, 0, 8);
            j = 0;
        }

        i++;

    }

    if (j > 0) {
        unsigned char to_compress = buffer[0];
        for (int l = 1; l < j; l++) {
            to_compress = to_compress ^ buffer[l];
        }
        compressed[k++] = to_compress;
    }

    memcpy(output, compressed, k);
}

int main() {

    char input[] = "This is a test input";
    char compressed[MAX_COMPRESSED_BUFFER];

    memset(compressed, 0, MAX_COMPRESSED_BUFFER);

    compress(input, compressed);

    for (int i = 0; i < strlen(input); i++) {
        printf("%c", input[i]);
    }
    printf("\n");

    for (int i = 0; i < strlen(input); i++) {
        printf("%02x ", input[i]);
    }
    printf("\n");

    for (int i = 0; i < strlen(input); i++) {
        printf("%02x ", compressed[i]);
    }
    printf("\n");

    return 0;
}