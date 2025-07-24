//FormAI DATASET v1.0 Category: Error handling ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

int main() {
    int num1, num2, result;

    printf("Enter First Number: ");
    if(scanf("%d", &num1) != 1) { // Checking if the input is integer or not
        printf("Invalid input!\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter Second Number: ");
    if(scanf("%d", &num2) != 1) { // Checking if the input is integer or not
        printf("Invalid input!\n");
        exit(EXIT_FAILURE);
    }

    if(num2 == 0) { // Handling division by zero error
        printf("Division by zero is not possible!\n");
        exit(EXIT_FAILURE);
    }

    result = num1 / num2;
    printf("Result: %d\n", result);

    return 0;
}