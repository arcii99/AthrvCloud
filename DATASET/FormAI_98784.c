//FormAI DATASET v1.0 Category: Compression algorithms ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1000
#define MAX_OUTPUT_SIZE MAX_INPUT_SIZE

int main() {
    char input[MAX_INPUT_SIZE], output[MAX_OUTPUT_SIZE];
    int count = 1, current = -1, previous = -1;

    printf("Enter a string to compress: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    // Compress the string
    for (int i = 0; i < strlen(input); i++) {
        current = input[i];

        if (previous == current) {
            count++;
        } else {
            if (count > 1) {
                sprintf(output + strlen(output), "%d", count);
            }
            sprintf(output + strlen(output), "%c", previous);
            count = 1;
        }

        previous = current;
    }

    // Add the last character and count to the output string
    if (count > 1) {
        sprintf(output + strlen(output), "%d", count);
    }
    sprintf(output + strlen(output), "%c", previous);

    printf("Compressed string: %s\n", output);

    return 0;
}