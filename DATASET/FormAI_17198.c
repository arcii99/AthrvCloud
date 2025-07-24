//FormAI DATASET v1.0 Category: Error handling ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT_SIZE 20

int main() {
    char input[MAX_INPUT_SIZE];
    int num, result;

    printf("Enter a number: ");
    fgets(input, MAX_INPUT_SIZE, stdin);

    if (sscanf(input, "%d", &num) != 1) {
        fprintf(stderr, "Error: Invalid input, please enter a valid integer\n");
        exit(EXIT_FAILURE);
    }
    
    if (num < 0) {
        fprintf(stderr, "Error: Invalid input, please enter a non-negative integer\n");
        exit(EXIT_FAILURE);
    }
    
    if (num > 100) {
        fprintf(stderr, "Error: Invalid input, please enter a number less than or equal to 100\n");
        exit(EXIT_FAILURE);
    }

    result = num * 2;

    printf("The number %d multiplied by 2 is %d\n", num, result);

    return 0;
}