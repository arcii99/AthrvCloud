//FormAI DATASET v1.0 Category: Compression algorithms ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

/**
 * This function will compress a string using a custom compression algorithm.
 * It works by taking the input string and replacing contiguous characters
 * with a number indicating the number of characters in that contiguous sequence.
 *
 * For example, the string "aaabbbccc" would be compressed to "a3b3c3".
 *
 * @param input the string to be compressed
 * @return the compressed input string
 */
char* compress(char* input) {
    int i, count = 1;
    char previous = input[0];
    char* compressed = (char*)malloc(strlen(input) * sizeof(char));
    for (i = 1; i < strlen(input); i++) {
        if (input[i] == previous) {
            count++;
        } else {
            sprintf(compressed + strlen(compressed), "%c%d", previous, count);
            previous = input[i];
            count = 1;
        }
    }
    sprintf(compressed + strlen(compressed), "%c%d", previous, count);
    return compressed;
}

// Test the compression function
int main() {
    char* input = "aaabbbccc";
    char* compressed = compress(input);
    printf("Input: %s\nCompressed: %s\n", input, compressed);
    free(compressed);
    return 0;
}