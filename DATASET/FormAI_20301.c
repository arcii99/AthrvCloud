//FormAI DATASET v1.0 Category: Compression algorithms ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFFER_SIZE 100

int main() {
    char input[BUFFER_SIZE], compressed[BUFFER_SIZE];
    printf("Enter a string to compress: ");
    fgets(input, BUFFER_SIZE, stdin);
    int length = strlen(input);
    input[length-1] = '\0';     // remove the newline character from input
    printf("Original string: %s\n", input);

    // perform compression algorithm
    int count = 1, index = 0;
    char current_char = input[0];
    for (int i = 1; i < length; i++) {
        if (input[i] == current_char) {
            count++;
        } else {
            compressed[index++] = current_char;
            char count_str[10];
            sprintf(count_str, "%d", count);
            strcat(compressed, count_str);
            index += strlen(count_str);
            current_char = input[i];
            count = 1;
        }
    }
    compressed[index++] = current_char;
    char count_str[10];
    sprintf(count_str, "%d", count);
    strcat(compressed, count_str);
    index += strlen(count_str);
    compressed[index] = '\0';

    printf("Compressed string: %s\n", compressed);

    return 0;
}