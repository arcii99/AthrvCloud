//FormAI DATASET v1.0 Category: Error handling ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function that throws an error */
void throw_error(int error_code) {
    char* error_message = "";

    /* Choose error message based on error code */
    switch(error_code) {
        case 1:
            error_message = "Error: Invalid input!\n";
            break;
        case 2:
            error_message = "Error: Memory allocation failed!\n";
            break;
        default:
            error_message = "Unknown error occured!\n";
            break;
    }

    /* Print error message and exit program with error code */
    printf("%s", error_message);
    exit(error_code);
}

int main() {
    char input_string[100];
    int* dynamic_array;
    int array_size;
    int i;

    /* Prompt user for input */
    printf("Enter an array size between 1 and 10: ");
    fgets(input_string, 100, stdin);

    /* Remove trailing newline character from input */
    input_string[strcspn(input_string, "\n")] = 0;

    /* Validate input */
    if(strlen(input_string) == 0 || atoi(input_string) < 1 || atoi(input_string) > 10) {
        throw_error(1);
    }

    /* Convert input to integer */
    array_size = atoi(input_string);

    /* Allocate memory for dynamic array */
    dynamic_array = (int*) malloc(array_size * sizeof(int));

    /* Check if memory allocation succeeded */
    if(dynamic_array == NULL) {
        throw_error(2);
    }

    /* Fill dynamic array with random numbers */
    for(i = 0; i < array_size; i++) {
        dynamic_array[i] = rand();
    }

    /* Print dynamic array */
    printf("Dynamic array: [");
    for(i = 0; i < array_size; i++) {
        printf("%d", dynamic_array[i]);
        if(i != array_size - 1) {
            printf(", ");
        }
    }
    printf("]\n");

    /* Free dynamically allocated memory */
    free(dynamic_array);

    return 0;
}