//FormAI DATASET v1.0 Category: Compression algorithms ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 1024

/**
 * This function compresses a string using a simple algorithm where each character
 * is replaced by a count of how many times it appears in a row.
 * For example, the string "hello" would be compressed to "h1e1l2o1".
 * This algorithm works best on strings with repeated characters.
 */
char* compress(char* input_string) {
    // Allocate memory for the compressed string
    char* compressed_string = (char*)malloc(sizeof(char) * BUFFER_SIZE);

    int index = 0;
    int count = 1;
    char current_char = input_string[0];
    int len = strlen(input_string);

    // Loop through each character in the string
    for(int i = 1; i < len; i++) {
        // If the current character is the same as the previous one, increase the count
        if(input_string[i] == current_char) {
            count++;
        } else {
            // If the current character is different, append the previous character and its count to the compressed string
            index += sprintf(&compressed_string[index], "%c%d", current_char, count);
            current_char = input_string[i];
            count = 1;
        }
    }

    // Append the last character and its count to the compressed string
    index += sprintf(&compressed_string[index], "%c%d", current_char, count);

    // Trim any extra memory from the compressed string
    compressed_string = (char*)realloc(compressed_string, sizeof(char) * (index + 1));
    compressed_string[index] = '\0';

    return compressed_string;
}

int main() {
    char* string_to_compress = "aabbcddddeeeee";
    printf("String to compress: %s\n", string_to_compress);

    char* compressed_string = compress(string_to_compress);
    printf("Compressed string: %s\n", compressed_string);

    free(compressed_string);
    return 0;
}