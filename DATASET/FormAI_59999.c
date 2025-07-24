//FormAI DATASET v1.0 Category: Compression algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the input string using our unique algorithm
char* compress(char* input) {
    // Check if the input string is null or empty
    if (input == NULL || strlen(input) == 0) {
        return NULL;
    }

    // Count the number of consecutive characters (including whitespace) in the input string
    int count = 1;
    int index = 0;
    int length = strlen(input);
    char currentChar = input[0];
    char* compressed = (char*) malloc(length * sizeof(char));

    for (int i = 1; i < length; i++) {
        if (input[i] == currentChar) {
            count++;
        } else {
            compressed[index++] = currentChar;
            compressed[index++] = count + '0';
            currentChar = input[i];
            count = 1;
        }
    }

    compressed[index++] = currentChar;
    compressed[index++] = count + '0';
    compressed[index] = '\0';

    return compressed;
}

int main() {
    char* input = "aaaaaabccccdeeefggggg";
    char* compressed = compress(input);
    printf("Original string: %s\n", input);
    printf("Compressed string: %s\n", compressed);
    free(compressed);
    return 0;
}