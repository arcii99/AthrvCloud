//FormAI DATASET v1.0 Category: Compression algorithms ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* A simple function to compress a given string using run-length encoding */
char* compress(char* str) {
    int len = strlen(str);
    int pos = 0, count = 1;

    char* result = (char*) malloc(len * sizeof(char)); // Allocate memory for the compressed string

    for (int i = 0; i < len; i++) {
        if (i + 1 < len && str[i] == str[i+1]) {
            count++; // Increment the count if the current character is the same as the next character
        }
        else {
            // If the current character is different than the next character, append the count and character to the result
            result[pos++] = (char) (count + '0');
            result[pos++] = str[i];
            count = 1; // Reset the count
        }
    }

    result[pos] = '\0'; // Add the terminating character to the result

    return result;
}

/* The main function */
int main() {
    char* str = "aabbbcdd";
    char* compressed_str = compress(str);

    printf("Original string: %s\n", str);
    printf("Compressed string: %s\n", compressed_str);

    free(compressed_str); // Free the memory allocated for the compressed string

    return 0;
}