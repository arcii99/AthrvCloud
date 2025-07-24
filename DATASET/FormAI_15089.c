//FormAI DATASET v1.0 Category: Arithmetic ; Style: complex
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, num3;
    float result;

    printf("Enter the first number: ");
    scanf("%d", &num1);

    printf("Enter the second number: ");
    scanf("%d", &num2);

    printf("Enter the third number: ");
    scanf("%d", &num3);

    result = (num1 + num2 + num3) / 3.0;

    printf("The average of %d, %d, and %d is %.2f", num1, num2, num3, result);

    return 0;
}