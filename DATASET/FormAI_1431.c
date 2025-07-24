//FormAI DATASET v1.0 Category: Compression algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * A simple compression algorithm that converts repeated characters in a string into
 * a count of the character followed by the character itself.
 *
 * For example, the string "aaabbbcc" will be compressed to "3a3b2c".
 */

char* compress(char* str) {
    int len = strlen(str);
    char* output = (char*) malloc((len * 2 + 1) * sizeof(char)); // allocate space for output string
    char current_char = str[0];
    int count = 1;
    int output_index = 0;

    for (int i = 1; i <= len; i++) {
        if (str[i] == current_char) { // if the current character is the same as the last one
            count++;
        } else { // if the current character is different from the last one
            output[output_index++] = count + '0'; // add the count
            output[output_index++] = current_char; // add the character
            current_char = str[i]; // update the current character
            count = 1; // reset the count
        }
    }

    output[output_index] = '\0'; // add the null terminator

    return output;
}

int main() {
    char* str = "aaabbbcc";
    char* compressed_str = compress(str);

    printf("Original string: %s\n", str);
    printf("Compressed string: %s\n", compressed_str);

    free(compressed_str); // free the memory allocated for the compressed string

    return 0;
}