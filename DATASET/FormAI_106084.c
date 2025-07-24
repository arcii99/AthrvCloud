//FormAI DATASET v1.0 Category: Compression algorithms ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress the given input string using mathematical compression algorithm
char* compress(char* input) {
    int i = 0, j = 0, count = 1;
    int len = strlen(input);
    char* output = (char*) malloc((len + 1) * sizeof(char));

    // Calculate the compressed string by counting the number of times each character appears
    while (i < len) {
        if (input[i] == input[i + 1]) {
            count++;
        } else {
            output[j++] = input[i];
            output[j++] = (count + '0');
            count = 1;
        }
        i++;
    }

    output[j] = '\0';

    return output;
}

int main() {
    // Test the compression algorithm with example input string
    char* input = "aaabbbcccddd";
    char* output = compress(input);

    printf("Input string : %s\n", input);
    printf("Output string: %s\n", output);

    free(output);

    return 0;
}