//FormAI DATASET v1.0 Category: Error handling ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

#define MAX_INPUT 1000

// Function to handle errors
void handleError(int errNum, const char *errMsg, char *line) {
    fprintf(stderr, "\nERROR %d: %s - %s\n", errNum, errMsg, line);
    exit(EXIT_FAILURE);
}

// Function to read input from user
void readInput(char *input) {
    printf("Enter a string: ");
    fgets(input, MAX_INPUT, stdin);

    // Check for read errors
    if (ferror(stdin))
        handleError(errno, "Error reading from input", input);
}

// Function to convert input to an integer
int convertToInt(char *input) {
    char *endptr;
    int num = strtol(input, &endptr, 10);

    // Check for conversion errors
    if (errno == ERANGE || *endptr != '\n')
        handleError(errno, "Error converting input to integer", input);

    return num;
}

int main() {
    char input[MAX_INPUT];
    int intInput;

    readInput(input);
    intInput = convertToInt(input);

    printf("The integer input is: %d\n", intInput);

    return 0;
}