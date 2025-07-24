//FormAI DATASET v1.0 Category: Arithmetic ; Style: scientific
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int a = 5;
    int b = 3;
    int c = 7;
    int sum = a + b + c;
    float avg = (float)sum / 3.0;
    float variance = ((a - avg) * (a - avg) + (b - avg) * (b - avg) + (c - avg) * (c - avg)) / 3.0;
    float standard_deviation = sqrt(variance);

    printf("\nArithmetic operations with scientific significance:\n");
    printf("--------------------------------------------------\n\n");
    printf("The sum of a, b and c is: %d\n", sum);
    printf("The average of a, b and c is: %f\n", avg);
    printf("The variance of a, b and c is: %f\n", variance);
    printf("The standard deviation of a, b and c is: %f\n", standard_deviation);

    return 0;
}