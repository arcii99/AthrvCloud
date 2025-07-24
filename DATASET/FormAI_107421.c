//FormAI DATASET v1.0 Category: Compression algorithms ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the size of the buffer used to store the compressed data
#define BUFFER_SIZE 1024

// Function to compress a string using a simple run-length encoding algorithm
void compress(char* input, char* output) {
    int count = 1;
    char current = input[0];
    int i, j = 0;

    // Loop through the input string, updating count and current as needed
    for (i = 1; i < strlen(input); i++) {
        if (input[i] == current) {
            count++;
        } else {
            // Write the current count and character to the output array
            output[j++] = count;
            output[j++] = current;
            current = input[i];
            count = 1;
        }
    }

    // Write the final count and character to the output array
    output[j++] = count;
    output[j++] = current;

    // Add a null terminator to the end of the output string
    output[j] = '\0';
}

int main() {
    char input[] = "Hello, world! This is a test string.";
    char output[BUFFER_SIZE];
    memset(output, 0, BUFFER_SIZE);

    printf("Original string: %s\n", input);

    compress(input, output);

    printf("Compressed string: %s\n", output);

    return 0;
}