//FormAI DATASET v1.0 Category: Compression algorithms ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress a given string using the Run Length Encoding algorithm
void compress(char* str, int size) {
    char count[10];
    int j, k;
    // Iterate through the string
    for (int i = 0; i < size; i++) {
        printf("%c", str[i]);
        // Count occurrences of current character
        j = i + 1;
        k = 1;
        while (str[j] == str[i]) {
            k++;
            j++;
        }
        // Convert count to string and print
        sprintf(count, "%d", k);
        printf("%s", count);

        // Skip over repeated characters
        i = j - 1;
    }
}

int main() {
    // Input string
    char str[100];
    printf("Enter a string: ");
    gets(str);

    printf("Original: %s\n", str);
    printf("Compressed: ");
    // Compress the string
    compress(str, strlen(str));

    return 0;
}