//FormAI DATASET v1.0 Category: Educational ; Style: sophisticated
#include <stdio.h>

/* This program will prompt the user to enter two integers and it will perform various arithmetic operations on them. */

int main()
{
    int a, b;

    printf("Enter the first integer: ");
    scanf("%d", &a);
    printf("Enter the second integer: ");
    scanf("%d", &b);

    printf("\n%d + %d = %d\n", a, b, a + b);
    printf("%d - %d = %d\n", a, b, a - b);
    printf("%d * %d = %d\n", a, b, a * b);
    printf("%d / %d = %.2f\n", a, b, (float)a / (float)b);

    if (a % b == 0)
        printf("%d is divisible by %d\n", a, b);
    else
        printf("%d is not divisible by %d\n", a, b);

    if (a > b)
        printf("%d is larger than %d\n", a, b);
    else if (a < b)
        printf("%d is larger than %d\n", b, a);
    else
        printf("The numbers are equal\n");

    printf("The sum of the first %d integers is %d\n", a, (a*(a+1))/2);

    return 0;
}