//FormAI DATASET v1.0 Category: Compression algorithms ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 256

char compressed[BUFFER_SIZE];
char decompressed[BUFFER_SIZE];

int compress(char* string) {
    char currentChar = string[0];
    int frequency = 1;
    int j = 0;
    for(int i = 1; i < strlen(string) + 1; i++) {
        if(string[i] == currentChar) {
            frequency++;
        } else {
            compressed[j++] = currentChar;
            compressed[j++] = frequency + '0';
            currentChar = string[i];
            frequency = 1;
        }
    }
    compressed[j] = '\0';
    return 0;
}

int decompress(char* string) {
    int j = 0;
    for(int i = 0; i < strlen(string); i += 2) {
        char currentChar = string[i];
        int frequency = string[i + 1] - '0';
        for(int k = 0; k < frequency; k++) {
            decompressed[j++] = currentChar;
        }
    }
    decompressed[j] = '\0';
    return 0;
}

int main() {
    char string[BUFFER_SIZE];
    printf("Enter a string to compress: ");
    scanf("%s", string);
    compress(string);
    printf("Compressed string: %s\n", compressed);
    decompress(compressed);
    printf("Decompressed string: %s\n", decompressed);
    return 0;
}