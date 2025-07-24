//FormAI DATASET v1.0 Category: Compression algorithms ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT 1000
#define MAX_OUTPUT 100000

/**
 * This function compresses the input string using a simple compression algorithm.
 * The algorithm replaces repeated characters with a count of the number of repetitions.
 * For example, the string "aaabbbc" would be compressed to "a3b3c1".
 *
 * @param input The input string to compress
 * @param output The output string where the compressed version will be stored
 * @return The length of the compressed string
 */
int compress(char *input, char *output) {
    int input_len = strlen(input);
    int output_len = 0;
    int count = 1;
    char prev = input[0];

    for (int i = 1; i < input_len; i++) {
        if (input[i] == prev) {
            count++;
        } else {
            output[output_len++] = prev;
            output_len += sprintf(&output[output_len], "%d", count);
            count = 1;
            prev = input[i];
        }
    }

    // Add the last character and count
    output[output_len++] = prev;
    output_len += sprintf(&output[output_len], "%d", count);

    // Null-terminate the output string
    output[output_len] = '\0';

    return output_len;
}

int main() {
    char input[MAX_INPUT];
    char output[MAX_OUTPUT];

    printf("Enter a string to compress: ");
    fgets(input, MAX_INPUT, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove the newline character from input

    int output_len = compress(input, output);

    printf("Compressed string: %s\n", output);
    printf("Length of compressed string: %d\n", output_len);

    return 0;
}