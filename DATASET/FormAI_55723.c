//FormAI DATASET v1.0 Category: Compression algorithms ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1000

int main() {
    char input[MAX_BUFFER_SIZE];
    printf("Enter a string to compress: ");
    scanf("%s", input);

    // Initialize variables
    char current_char = input[0];
    int length = strlen(input);
    int count = 1;

    // Initialize output string with first character
    char output[MAX_BUFFER_SIZE];
    strcpy(output, "");
    char count_char[MAX_BUFFER_SIZE];

    // Loop through input string and compress
    for (int i = 1; i < length; i++) {
        if (input[i] == current_char) {
            count++;
        } else {
            // Add to output string
            sprintf(count_char, "%d", count);
            strcat(output, count_char);
            strcat(output, &current_char);

            // Reset variables
            count = 1;
            current_char = input[i];
        }
    }

    // Add final section to output string
    sprintf(count_char, "%d", count);
    strcat(output, count_char);
    strcat(output, &current_char);

    printf("Compressed string: %s\n", output);

    return 0;
}