//FormAI DATASET v1.0 Category: Math exercise ; Style: Romeo and Juliet
#include <stdio.h>

int main()
{
    int a, b, c, d;
    float e, f;

    printf("Enter two integers: ");
    scanf("%d %d", &a, &b);

    c = a + b;
    d = a - b;

    printf("Sum of %d and %d is %d\n", a, b, c);
    printf("Difference between %d and %d is %d\n", a, b, d);

    printf("Enter two floating-point numbers: ");
    scanf("%f %f", &e, &f);

    printf("Product of %f and %f is %f\n", e, f, e * f);
    printf("Quotient of %f and %f is %f\n", e, f, e / f);

    return 0;
}