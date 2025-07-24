//FormAI DATASET v1.0 Category: Compression algorithms ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This program implements a simple compression algorithm
// that outputs the number of consecutive characters in a string

void compress(char *s) {
    int n = strlen(s);
    int i, j = 0;
    char compressed[n];

    // loop through the string
    for (i = 0; i < n; i++) {
        int count = 1;
        compressed[j++] = s[i];

        // check if the current and next characters are the same
        while (i < n - 1 && s[i] == s[i+1]) {
            count++;
            i++;
        }

        // store the count as a character
        char buffer[10];
        sprintf(buffer, "%d", count);
        for (int k = 0; k < strlen(buffer); k++) {
            compressed[j++] = buffer[k];
        }
    }

    // add null terminator to compressed string
    compressed[j] = '\0';

    printf("Original string: %s\n", s);
    printf("Compressed string: %s\n", compressed);
}

int main() {
    char s[] = "aaabbbbccddddeee";
    compress(s);

    return 0;
}