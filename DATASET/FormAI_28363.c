//FormAI DATASET v1.0 Category: Math exercise ; Style: visionary
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main()
{
    int num1, num2, num3, num4, result;

    printf("Enter four numbers: ");
    scanf("%d%d%d%d", &num1, &num2, &num3, &num4);

    result = pow(num1, 2) + pow(num2, 2) + pow(num3, 2) + pow(num4, 2);

    printf("The sum of squares of the four numbers is: %d", result);

    return 0;
}