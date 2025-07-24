//FormAI DATASET v1.0 Category: Compression algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000
#define MAX_COMPRESSED_LENGTH 500

char* compress(char* input) {
    int count = 1;
    char* compressed = malloc(sizeof(char) * MAX_COMPRESSED_LENGTH);

    char current_char = input[0];
    int compressed_index = 0;

    for (int i = 1; i < strlen(input); i++) {
        if (input[i] == current_char) {
            count++;
        } else {
            compressed[compressed_index++] = current_char;
            compressed[compressed_index++] = '0' + count;
            current_char = input[i];
            count = 1;
        }
    }

    compressed[compressed_index++] = current_char;
    compressed[compressed_index++] = '0' + count;
    compressed[compressed_index] = '\0';

    return compressed;
}

int main() {
    char input[MAX_INPUT_LENGTH];
    printf("Enter the string to compress: ");
    scanf("%[^\n]s", input);

    char* compressed = compress(input);
    printf("Compressed string: %s\n", compressed);
    free(compressed);

    return 0;
}