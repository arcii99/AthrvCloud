//FormAI DATASET v1.0 Category: Text processing ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define STR_SIZE 10000

int main() {
    char input[STR_SIZE] = {0};
    char output[STR_SIZE] = {0};

    // Read input
    printf("Enter a string: ");
    fgets(input, STR_SIZE, stdin);

    // Remove new line character if present
    for (int i = 0; i < STR_SIZE; i++) {
        if (input[i] == '\n') {
            input[i] = '\0';
            break;
        }
    }

    // Manipulate string
    int input_len = strlen(input);
    int output_index = 0;
    for (int i = 0; i < input_len; i++) {
        if (input[i] >= 'a' && input[i] <= 'z') {
            output[output_index++] = input[i] - 'a' + 'A';
        } else if (input[i] >= 'A' && input[i] <= 'Z') {
            output[output_index++] = input[i] - 'A' + 'a';
        } else if (input[i] == ' ') {
            output[output_index++] = input[i];
        }
    }

    // Print output
    printf("\nInput: %s\n", input);
    printf("Output: %s\n", output);

    return 0;
}