//FormAI DATASET v1.0 Category: Compression algorithms ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// Function to compress a string
void compress(char* str) {
    uint32_t count = 1, i = 0, j = 0, k = 0;
    uint32_t len = strlen(str);
    char* res = (char*)malloc(len * sizeof(char));
    res[k++] = str[i++];

    while (i < len) {
        if (str[i] == res[j]) {
            count++;
            i++;
        } else {
            res[k++] = (char)count;
            count = 1;
            res[k++] = str[i++];
            j = k-1;
        }
    }

    res[k++] = (char)count;
    res[k] = '\0';

    // Print the compressed string
    printf("Compressed string: %s\n", res);

    // Free memory
    free(res);
}

int main() {
    char str[100];

    // Get user input
    printf("Enter a string to compress: ");
    fgets(str, sizeof(str), stdin);

    // Remove newline character
    str[strcspn(str, "\n")] = '\0';

    // Compress the string
    compress(str);

    return 0;
}