//FormAI DATASET v1.0 Category: Compression algorithms ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

char* compress(char* input) {
    int len = strlen(input);
    char curr_char = input[0];
    int curr_count = 1;
    int output_index = 0;

    char* output = (char*)malloc(sizeof(char) * MAX_LEN);
    memset(output, '\0', MAX_LEN);

    for (int i = 1; i <= len; i++) {
        if (input[i] == curr_char) {
            curr_count++;
        } else {
            // Add the compressed version of the current character to the output
            output[output_index++] = curr_char;
            output[output_index++] = '0' + curr_count;

            // Reset counts for the new character
            curr_char = input[i];
            curr_count = 1;
        }
    }

    return output;
}

int main() {
    char* input = "wwwwaaadexxxxxx";
    printf("Original string: %s\n", input);

    char* compressed = compress(input);
    printf("Compressed string: %s\n", compressed);

    free(compressed);
    return 0;
}