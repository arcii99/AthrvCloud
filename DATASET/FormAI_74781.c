//FormAI DATASET v1.0 Category: Error handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>

void throw_error(int error_code);

int main(void) {
    int numerator, denominator, result;

    // Get user input
    printf("Enter numerator: ");
    scanf("%d", &numerator);
    printf("Enter denominator: ");
    scanf("%d", &denominator);

    // Check for division by zero
    if (denominator == 0) {
        throw_error(1);
    }

    // Perform division
    result = numerator / denominator;
    printf("%d / %d = %d\n", numerator, denominator, result);

    return 0;
}

void throw_error(int error_code) {
    printf("ERROR: ");

    switch (error_code) {
        case 1:
            printf("Divide by zero\n");
            break;
        case 2:
            printf("File not found\n");
            break;
        case 3:
            printf("Memory allocation failed\n");
            break;
        default:
            printf("Unknown error\n");
            break;
    }

    exit(error_code);
}