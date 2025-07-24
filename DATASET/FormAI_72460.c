//FormAI DATASET v1.0 Category: Compression algorithms ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

int main() {
    int count, i, j;
    char character;
    printf("Enter a string (max length 100): ");
    char *input_string = malloc(sizeof(char) * 100);
    scanf("%s", input_string);

    char *compressed_string = malloc(sizeof(char) * 100);
    int compressed_index = 0;

    for (i = 0; input_string[i] != '\0'; i++) {
        character = input_string[i];
        count = 1;
        while (input_string[i + 1] == character) {
            count++;
            i++;
        }
        compressed_string[compressed_index++] = character;

        if (count > 1) {
            compressed_string[compressed_index++] = count + '0';
        }
    }
    compressed_string[compressed_index] = '\0';

    printf("Original String: %s\n", input_string);
    printf("Compressed String: %s\n", compressed_string);

    free(input_string);
    free(compressed_string);

    return 0;
}