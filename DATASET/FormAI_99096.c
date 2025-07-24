//FormAI DATASET v1.0 Category: Compression algorithms ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLEN 1000

char* compress(char* input); // Function to compress the input string

int main() {
    char input[MAXLEN];
    printf("Enter string to compress: ");
    fgets(input, MAXLEN, stdin);
    // Remove newline character from input
    if (input[strlen(input)-1] == '\n') {
        input[strlen(input)-1] = '\0';
    }
    printf("Original string: %s\n", input);
    char* compressed = compress(input);
    printf("Compressed string: %s\n", compressed);
    free(compressed); // Free memory allocated for compressed string
    return 0;
}

char* compress(char* input) {
    char* compressed = (char*) malloc(sizeof(char) * (strlen(input) + 1)); // Allocate memory for compressed string
    int len = strlen(input);
    int i = 0, j = 0;
    while (i < len) {
        int count = 1; // Count of consecutive characters
        while (input[i] == input[i+1] && i < len-1) { // Count consecutive characters
            count++;
            i++;
        }
        if (count == 1) { // If only one consecutive character, copy as it is
            compressed[j++] = input[i++];
        } else { // If more than one consecutive character, compress them
            compressed[j++] = count + '0'; // Store count as a character
            compressed[j++] = input[i]; // Store repeated character
            i++;
        }
    }
    compressed[j] = '\0'; // End compressed string with a null character
    return compressed;
}