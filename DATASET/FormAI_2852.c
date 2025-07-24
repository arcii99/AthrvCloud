//FormAI DATASET v1.0 Category: Compression algorithms ; Style: puzzling
// Welcome to the world of Puzzling C Compression!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Our function to compress the string
char *compress(char *original) {
    int len = strlen(original);
    int i = 0, j = 0, count = 1, index = 0;

    // Allocate memory for our compressed string
    char *compressed = malloc(sizeof(char) * len);

    // Iterate through the original string and compress it
    while (i < len) {
        if (original[i] == original[i + 1]) {
            count++;
        } else {
            // If it's a new character, add it to the compressed string and reset the count
            compressed[j++] = original[i];
            compressed[j] = '\0';
            sprintf(&compressed[strlen(compressed)], "%d", count);
            count = 1;
        }
        i++;
    }

    // If the compressed string is shorter, return it, otherwise return the original
    return strlen(compressed) < len ? compressed : original;
}

int main() {
    // Test our compression function
    char *original = "aaabbcccccddeeeee";
    char *compressed = compress(original);
    printf("Original string: %s\n", original);
    printf("Compressed string: %s\n", compressed);

    // Free any memory we allocated
    free(compressed);

    return 0;
}