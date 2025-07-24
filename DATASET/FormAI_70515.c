//FormAI DATASET v1.0 Category: Error handling ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_LEN 100

int main() {
    char input[MAX_INPUT_LEN];
    int num1, num2, result;
    
    printf("Enter the first number: ");
    fgets(input, MAX_INPUT_LEN, stdin);
    if (sscanf(input, "%d", &num1) != 1) {
        printf("ERROR: Invalid input. Please enter a valid integer.\n");
        return EXIT_FAILURE;
    }

    printf("Enter the second number: ");
    fgets(input, MAX_INPUT_LEN, stdin);
    if (sscanf(input, "%d", &num2) != 1) {
        printf("ERROR: Invalid input. Please enter a valid integer.\n");
        return EXIT_FAILURE;
    }

    if (num2 == 0) {
        printf("ERROR: Division by zero not allowed.\n");
        return EXIT_FAILURE;
    }

    result = num1 / num2;
    printf("%d divided by %d is %d.\n", num1, num2, result);

    return EXIT_SUCCESS;
}