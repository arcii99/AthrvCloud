//FormAI DATASET v1.0 Category: Compression algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// This is our special compression algorithm!
char* compress(char* str) {
    int len = strlen(str);
    char* compressed = (char*)malloc((len + 1) * sizeof(char));  // Allocate memory for compressed string
    int count = 1;
    char curr = str[0];
    int i;

    for (i = 1; i < len; i++) {
        if (str[i] == curr) {  // Count consecutive occurrences of the current character
            count++;
        }
        else {
            compressed[strlen(compressed)] = curr;  // Append character to the compressed string
            compressed[strlen(compressed)] = count + '0';  // Append count as a digit to the compressed string
            count = 1;  // Reset count
            curr = str[i];  // Move on to the next character
        }
    }

    compressed[strlen(compressed)] = curr;  // Append the last character
    compressed[strlen(compressed)] = count + '0';  // Append the last count

    return compressed;
}

int main() {
    char* str = "Let's compress this string!";
    printf("Original string: %s\n", str);

    char* compressed = compress(str);
    printf("Compressed string: %s\n", compressed);

    free(compressed);  // Don't forget to free the memory!

    return 0;
}