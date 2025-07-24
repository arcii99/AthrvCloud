//FormAI DATASET v1.0 Category: Error handling ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Define a custom error handling function
void error_check(int code, char* error_message)
{
    if (code < 0)
    {
        fprintf(stderr, "Error: %s\n", error_message);
        exit(EXIT_FAILURE);
    }
}

int main()
{
    // Declarations
    int x = 2;
    int y = 0;
    double z;
    int result;

    // Attempting to divide by zero
    result = x / y;
    error_check(result, "Division by zero");

    // Attempting to calculate the square root of a negative number
    z = sqrt(-1);
    if (isnan(z))
    {
        error_check(-1, "Square root of a negative number");
    }

    // Attempting to open a non-existent file
    FILE *f;
    f = fopen("nonexistentfile.txt", "r");
    error_check(f == NULL, "File not found");

    // All successful executions
    printf("No errors detected\n");
    return 0;
}