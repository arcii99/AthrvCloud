//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 1000

int main() {
    char* input = malloc(MAX_INPUT_LENGTH);

    printf("Welcome to the input sanitizer program. Please enter your data:\n");

    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Sanitize input to remove unsafe characters
    int i, j;
    for (i = 0, j = 0; input[i] != '\0'; i++) {
        if ((input[i] >= '0' && input[i] <= '9') ||
            (input[i] >= 'a' && input[i] <= 'z') ||
            (input[i] >= 'A' && input[i] <= 'Z') ||
            input[i] == ' ' || input[i] == '\n') {

            input[j] = input[i];
            j++;
        }
    }
    input[j] = '\0';

    printf("\nSanitized input: %s", input);

    free(input);

    return 0;
}