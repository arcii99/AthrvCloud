//FormAI DATASET v1.0 Category: Math exercise ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    // Variable declaration
    int num1, num2, num3, num4; 
    float result;

    // Prompt user to input four different numbers
    printf("Enter four different numbers: ");
    scanf("%d %d %d %d", &num1, &num2, &num3, &num4);

    // Calculate the result
    result = (float) (num1 * num2 * num3 * num4) / (float) pow(num4, 2);

    // Round the result to two decimal places
    result = roundf(result * 100) / 100;

    printf("The result is: %0.2f\n", result);

    return 0;
}