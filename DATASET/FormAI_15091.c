//FormAI DATASET v1.0 Category: Error handling ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void error_handling(double x, double y);

int main()
{
    double x = 5, y = 2, result;
    result = pow(x, y);
    error_handling(x, y);
    printf("The result of %lf raised to the power of %lf is: %lf\n", x, y, result);
    return 0;
}

void error_handling(double x, double y)
{
    if (x <= 0)
    {
        printf("Error: The base %lf should be a positive non zero number.\n", x);
        exit(0);
    }

    if (y < 0)
    {
        printf("Error: The exponent %lf should be a positive number.\n", y);
        exit(0);
    }
}