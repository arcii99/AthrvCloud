//FormAI DATASET v1.0 Category: Error handling ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
    int num1, num2, result;

    printf("Enter the first number: ");
    if(scanf("%d", &num1) != 1)
    {
        perror("Error occurred while reading input");
        exit(EXIT_FAILURE);
    }

    printf("Enter the second number: ");
    if(scanf("%d", &num2) != 1)
    {
        perror("Error occurred while reading input");
        exit(EXIT_FAILURE);
    }

    if(num2 == 0)
    {
        fprintf(stderr, "Error: Division by zero\n");
        exit(EXIT_FAILURE);
    }

    result = num1 / num2;
    printf("Result: %d\n", result);

    return 0;
}