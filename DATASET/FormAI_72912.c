//FormAI DATASET v1.0 Category: Error handling ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

/* Define an imaginary error code */
#define ERROR_CUSTOM (-1)

/* Define an imaginary function that could produce an error */
int dangerous_function(int input) {
    /* We don't like even numbers */
    if (input % 2 == 0) {
        /* Return the custom error code */
        return ERROR_CUSTOM;
    }
    /* All good */
    return input * 2;
}

int main(int argc, char *argv[]) {
    int input, result;

    /* Prompt the user for input */
    printf("Enter an odd number: ");
    scanf("%d", &input);

    /* Call our imaginary function and handle any errors */
    result = dangerous_function(input);
    if (result == ERROR_CUSTOM) {
        printf("Error: input must be odd!\n");
        /* Exit with a non-zero status to indicate an error condition */
        exit(EXIT_FAILURE);
    }

    /* Print the result of the function */
    printf("The answer is %d\n", result);

    return 0;
}