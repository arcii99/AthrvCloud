//FormAI DATASET v1.0 Category: Compression algorithms ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to compress a string using numerical compression
void compress(char *str) {
    int len = strlen(str);
    char compressed[1000];

    // Keep track of current and last characters and their occurrence
    char curr_char = str[0];
    char last_char = str[0];
    int curr_count = 0;
    int last_count = 0;

    for (int i = 0; i < len; i++) {
        curr_char = str[i];

        // If current character is same as last character, increment count
        if (curr_char == last_char) {
            curr_count++;
        } else {
            // If current character is different, add last character and its count to compressed string
            compressed[last_count] = last_char;
            snprintf(&compressed[last_count+1], 10, "%d", last_count);
            last_count += strlen(&compressed[last_count]);
            last_char = curr_char;
            curr_count = 1;
        }
    }

    // Add last character and its count to compressed string
    compressed[last_count] = last_char;
    snprintf(&compressed[last_count+1], 10, "%d", last_count);
    last_count += strlen(&compressed[last_count]);

    // Print compressed string
    printf("Compressed string: %s\n", compressed);
}

int main() {
    char str[] = "aabbbccccdddeee";
    printf("Original string: %s\n", str);
    compress(str);
    return 0;
}