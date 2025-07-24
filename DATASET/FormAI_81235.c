//FormAI DATASET v1.0 Category: Compression algorithms ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// This algorithm compresses a string by replacing any consecutive groups of characters with a number that represents the frequency of those characters.
// For example, "aabbbcccc" would become "a2b3c4"

char *compress(const char *str) {
    // Create a new string for the compressed version
    char *compressed = malloc(MAX_LENGTH * sizeof(char));
    int len = strlen(str);
    int curr_char_count = 0;
    char curr_char = str[0];
    int marker = 0;
    int i;

    // Loop through each character in the string
    for (i = 0; i < len; i++) {
        // If the current character is the same as the previous character, increment the count
        if (str[i] == curr_char) {
            curr_char_count++;
        }
        // If the current character is different, record the compressed version of the previous group and start a new count
        else {
            marker += sprintf(&compressed[marker], "%c%d", curr_char, curr_char_count);
            curr_char = str[i];
            curr_char_count = 1;
        }
    }

    // Add the final group to the compressed version
    marker += sprintf(&compressed[marker], "%c%d", curr_char, curr_char_count);

    // Trim the compressed string to the correct length
    compressed = realloc(compressed, marker * sizeof(char));

    return compressed;
}

int main() {
    char *str = "aabbbcccc";
    char *compressed = compress(str);

    printf("Original string: %s\n", str);
    printf("Compressed string: %s\n", compressed);

    free(compressed);
    
    return 0;
}