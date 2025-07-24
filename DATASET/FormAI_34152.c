//FormAI DATASET v1.0 Category: Error handling ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LENGTH 100

void errorHandling(char* errorMessage) {
    fprintf(stderr, "Error: %s\n", errorMessage); // Output error to standard error
    exit(1); // Exit program with non-zero status code
}

int main() {
    char input[MAX_INPUT_LENGTH];

    printf("Enter a number between 1 and 10: ");
    fgets(input, MAX_INPUT_LENGTH, stdin); // Get input from user

    // Remove trailing newline character from input
    if (input[strlen(input)-1] == '\n') {
        input[strlen(input)-1] = '\0';
    }

    // Convert input to integer
    int num = atoi(input);

    // Check if input is within range
    if (num < 1 || num > 10) {
        errorHandling("Input out of range!");
    } else {
        printf("You entered: %d\n", num);
    }

    return 0;
}