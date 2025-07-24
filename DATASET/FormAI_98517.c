//FormAI DATASET v1.0 Category: Compression algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 1000

char* compress(char* input) {
    char* output = malloc(MAX_LEN * sizeof(char));
    int input_len = strlen(input), output_len = 0, count = 1;

    for (int i = 0; i < input_len; i++) {
        if (input[i] == input[i+1]) {
            count++;
        } else {
            output[output_len++] = input[i];
            if (count > 1) {
                char buffer[MAX_LEN];
                sprintf(buffer, "%d", count);
                int buffer_len = strlen(buffer);
                for (int j = 0; j < buffer_len; j++) {
                    output[output_len++] = buffer[j];
                }
                count = 1;
            }
        }
    }
    output[output_len] = '\0';

    return output;
}

int main() {
    char input[MAX_LEN], *output;
    printf("Enter a string to compress:\n");
    fgets(input, MAX_LEN, stdin);

    // remove newline character from input
    if (input[strlen(input)-1] == '\n') input[strlen(input)-1] = '\0';

    output = compress(input);

    printf("Compressed string: %s\n", output);

    free(output);

    return 0;
}