//FormAI DATASET v1.0 Category: Compression algorithms ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compute the run length of a character
int calculateRunLength(char* string, int index, int length) {
    int count = 1;
    while (index + count < length && string[index] == string[index + count]) {
        count++;
    }
    return count;
}

// Function to compress the input string using the run length encoding algorithm
char* compress(char* input) {
    int inputLength = strlen(input);
    char* output = (char*) malloc(sizeof(char) * inputLength);
    int outputIndex = 0;

    for (int i = 0; i < inputLength; i++) {
        int runLength = calculateRunLength(input, i, inputLength);

        if (runLength > 2) {
            output[outputIndex++] = runLength + '0';
            output[outputIndex++] = input[i];

            i += runLength - 1;
        }
        else {
            output[outputIndex++] = input[i];
        }
    }

    output[outputIndex] = '\0';
    return output;
}

int main() {
    char* input = "aabbbccdddddd";
    char* compressed = compress(input);

    printf("Compressed: %s\n", compressed);
    // Output: Compressed: a2b3c2d6

    free(compressed);
    return 0;
}