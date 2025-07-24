//FormAI DATASET v1.0 Category: Compression algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define our "cheerful" compression algorithm
char *compress(char *original) {
    int count = 1, i, j;
    char *compressed = malloc(sizeof(char) * (strlen(original) + 1));

    // Loop through the original string and count consecutive characters
    for (i = 0, j = 0; i < strlen(original); i++) {
        if (original[i] == original[i+1] && original[i+1] != '\0') {
            count++;
        } else {
            // If we have more than 3 consecutive characters, compress them
            if (count > 3) {
                compressed[j++] = '/';
                compressed[j++] = original[i];
                compressed[j++] = count + '0';
                count = 1;
            // Otherwise, just copy the original character to the compressed string
            } else {
                for (int k = 0; k < count; k++) {
                    compressed[j++] = original[i];
                }
                count = 1;
            }
        }
    }
    compressed[j] = '\0';
    return compressed;
}

int main() {
    char original[] = "Happyyyyyyyyy Birthday!!!!!";
    char *compressed = compress(original);

    printf("Original String: %s\n", original);
    printf("Compressed String: %s\n", compressed);

    free(compressed);
    return 0;
}