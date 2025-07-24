//FormAI DATASET v1.0 Category: Compression algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress a given string using run-length encoding
char* compress(char* string) {
    int length = strlen(string);
    int i = 0, j = 0, count = 1;
    char currentChar = string[0];
    char* compressed = (char*) malloc(sizeof(char) * length);

    while (i < length) {
        if (string[i] == currentChar) {
            count++;
        } else {
            compressed[j] = currentChar;
            compressed[j+1] = count + '0';

            j += 2;
            currentChar = string[i];
            count = 1;
        }

        i++;
    }

    // add last set of characters
    compressed[j] = currentChar;
    compressed[j+1] = count + '0';
    compressed[j+2] = '\0';

    return compressed;
}

int main() {
    char* myString = "aaabbcccdddde";

    printf("Original string: %s\n", myString);
    char* compressed = compress(myString);
    printf("Compressed string: %s\n", compressed);

    free(compressed);
    return 0;
}