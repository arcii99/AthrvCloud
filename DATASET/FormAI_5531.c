//FormAI DATASET v1.0 Category: Error handling ; Style: creative
#include <stdio.h>
#include <stdlib.h>

// Custom error handling function
void handle_error(char* msg, int err_num)
{
    fprintf(stderr, "Error: %s - Error Code: %d\n", msg, err_num);
    exit(EXIT_FAILURE);
}

int main()
{
    int num1, num2, result;
    printf("Enter two integers: ");
    if (scanf("%d %d", &num1, &num2) != 2)
    {
        handle_error("Invalid input format", 1); // If input format is invalid, exit with error code 1
    }
    if (num2 == 0)
    {
        handle_error("Division by zero", 2); // If second number is zero, exit with error code 2
    }
    result = num1 / num2;
    printf("Result: %d\n", result);
    return EXIT_SUCCESS; // Exit with success code 0
}