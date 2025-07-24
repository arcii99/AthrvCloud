//FormAI DATASET v1.0 Category: Error handling ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>

int main()
{
    int num1, num2, result;
    printf("Enter two numbers: ");
    if (scanf("%d %d", &num1, &num2) != 2) // Error Handling in Input
    {
        printf("Invalid input, please enter integers only.");
        exit(1); // Exit with error code 1
    }

    if (num2 == 0) // Handling Division by Zero Error
    {
        printf("Error! Cannot divide by zero.");
        exit(2); // Exit with error code 2
    }

    result = num1 / num2; // Calculate the result

    printf("%d / %d = %d", num1, num2, result);
    return 0; // Exit with success code 0
}