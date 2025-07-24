//FormAI DATASET v1.0 Category: Error handling ; Style: energetic
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, result;

    printf("Enter number 1: ");
    if (scanf("%d", &num1) != 1) {
        printf("Invalid input. Expected an integer value.\n");
        exit(EXIT_FAILURE);
    }

    printf("Enter number 2: ");
    if (scanf("%d", &num2) != 1) {
        printf("Invalid input. Expected an integer value.\n");
        exit(EXIT_FAILURE);
    }

    if (num2 == 0) {
        printf("Error: division by zero.\n");
        exit(EXIT_FAILURE);
    }

    result = num1 / num2;

    printf("%d / %d = %d\n", num1, num2, result);

    return 0;
}