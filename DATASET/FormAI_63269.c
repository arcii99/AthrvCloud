//FormAI DATASET v1.0 Category: Error handling ; Style: detailed
#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int num1, num2;
    printf("Enter two numbers to divide: ");
    scanf("%d %d", &num1, &num2);

    if (num2 == 0) 
    {
        fprintf(stderr, "Error: Division by zero\n");
        // Custom error message printed to stderr
        exit(EXIT_FAILURE); // Exit program with error status
    }
    else 
    {
        int result = num1 / num2;
        printf("%d divided by %d is %d\n", num1, num2, result);
    }

    return 0;
}