//FormAI DATASET v1.0 Category: Compression algorithms ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STRING_LENGTH 1000

char compressed[MAX_STRING_LENGTH];
char decompressed[MAX_STRING_LENGTH];

void compress(char* str) {
    int compressed_idx = 0;
    int count = 1;
    for (int i = 0; i < strlen(str); i++) {
        if (str[i] == str[i+1]) {
            count++;
        } else {
            compressed[compressed_idx++] = str[i];
            compressed[compressed_idx++] = count;
            count = 1;
        }
    }
    compressed[compressed_idx++] = '\0';
}

void decompress(char* str) {
    int decompressed_idx = 0;
    for (int i = 0; i < strlen(str); i += 2) {
        char c = str[i];
        int count = str[i+1];
        for (int j = 0; j < count; j++) {
            decompressed[decompressed_idx++] = c;
        }
    }
    decompressed[decompressed_idx++] = '\0';
}

int main() {
    char original[MAX_STRING_LENGTH];
    printf("Enter a string to compress: ");
    scanf("%[^\n]", original);

    compress(original);
    printf("Compressed string: %s\n", compressed);

    decompress(compressed);
    printf("Decompressed string: %s\n", decompressed);

    return 0;
}