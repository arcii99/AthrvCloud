//FormAI DATASET v1.0 Category: Compression algorithms ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

char* compress(char* message);

int main() {
    char* message = "Hello, world! This is a compression algorithm.";
    printf("Original message: %s\n", message);
    char* compressed_message = compress(message);
    printf("Compressed message: %s\n", compressed_message);
    free(compressed_message);
    return 0;
}

char* compress(char* message) {
    char* compressed_message = (char*)malloc(MAX_SIZE * sizeof(char));
    int frequency[256] = { 0 };
    int unique_chars = 0;
    for (int i = 0; i < strlen(message); i++) {
        if (frequency[(int)message[i]] == 0) {
            unique_chars++;
        }
        frequency[(int)message[i]]++;
    }
    sprintf(compressed_message, "%d ", unique_chars);
    for (int i = 0, j = strlen(compressed_message); i < 256; i++) {
        if (frequency[i] != 0) {
            sprintf(compressed_message + j, "%c%d ", i, frequency[i]);
            j = strlen(compressed_message);
        }
    }
    int compressed_size = strlen(compressed_message);
    for (int i = 0; i < strlen(message); i++) {
        sprintf(compressed_message + compressed_size, "%d ", frequency[(int)message[i]]);
        compressed_size = strlen(compressed_message);
    }
    return compressed_message;
}