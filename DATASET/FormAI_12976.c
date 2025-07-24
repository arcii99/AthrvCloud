//FormAI DATASET v1.0 Category: Compression algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

void compress(char* input, int size);

int main() {
    char input[MAX_SIZE];
    printf("Enter a string to compress: ");
    fgets(input, MAX_SIZE, stdin);
    printf("Original string: %s", input);
    compress(input, strlen(input));
    printf("Compressed string: %s", input);
    return 0;
}

void compress(char* input, int size) {
    char compressed[MAX_SIZE];
    int count = 1;
    char prev = input[0];
    int index = 0;
    for (int i = 1; i < size; i++) {
        if (input[i] == prev) {
            count++;
        } else {
            compressed[index++] = prev;
            compressed[index++] = count + '0';
            count = 1;
            prev = input[i];
        }
    }
    compressed[index++] = prev;
    compressed[index++] = count + '0';
    compressed[index] = '\0';
    if (strlen(compressed) < size) {
        strcpy(input, compressed);
    }
}