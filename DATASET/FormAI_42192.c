//FormAI DATASET v1.0 Category: Arithmetic ; Style: mathematical
#include <stdio.h>

int main()
{
    printf("Welcome to Arithmetics!\n");

    int a, b;
    printf("Enter two numbers: ");
    scanf("%d%d", &a, &b);

    printf("The sum of %d and %d is %d\n", a, b, a + b);
    printf("The difference between %d and %d is %d\n", a, b, a - b);
    printf("The product of %d and %d is %d\n", a, b, a * b);

    if (b != 0)
    {
        printf("The quotient of %d and %d is %d\n", a, b, a / b);
        printf("The remainder after dividing %d by %d is %d\n", a, b, a % b);
    }
    else
    {
        printf("Division by zero is not possible\n");
    }

    printf("The square of %d is %d\n", a, a * a);
    printf("The square root of %d is %f\n", a, sqrt(a));
    printf("The cube of %d is %d\n", a, a * a * a);
    printf("The cube root of %d is %f\n", a, cbrt(a));

    printf("The minimum between %d and %d is %d\n", a, b, (a < b) ? a : b);
    printf("The maximum between %d and %d is %d\n", a, b, (a > b) ? a : b);

    return 0;
}