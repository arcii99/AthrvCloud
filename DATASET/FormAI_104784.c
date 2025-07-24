//FormAI DATASET v1.0 Category: Error handling ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Custom error handler function */
void error_handler(int error_code, const char* error_msg)
{
    // print out error message to console
    fprintf(stderr, "Error Code %d: %s\n", error_code, error_msg);
    
    // optional: write error message to file
    FILE *file = fopen("error_log.txt", "a");
    fprintf(file, "Error Code %d: %s\n", error_code, error_msg);
    fclose(file);
    
    // exit program with error code
    exit(error_code);
}

int main()
{
    int num1, num2, result;
    
    printf("Enter two numbers to divide: ");
    scanf("%d %d", &num1, &num2);
    
    // check for division by zero error
    if(num2 == 0)
        error_handler(1, "Division by zero is not allowed");
    
    // perform division operation
    result = num1 / num2;
    
    // check if result is positive or negative
    if(result < 0)
        error_handler(2, "Result is negative");
    
    printf("Result of division is: %d\n", result);
    
    return 0;
}