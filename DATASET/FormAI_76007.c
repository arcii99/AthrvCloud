//FormAI DATASET v1.0 Category: Arithmetic ; Style: Claude Shannon
// Claude Shannon Style Unique C Arithmetic Example Program
#include <stdio.h>

// Function to calculate the greatest common divisor of two integers
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main()
{
    int a, b;

    printf("Enter two integers to calculate their greatest common divisor:\n");
    scanf("%d %d", &a, &b);

    int gcdResult = gcd(a, b);

    printf("The greatest common divisor of %d and %d is %d.\n", a, b, gcdResult);

    // Bitwise operations challenge
    int leftShift = gcdResult << 2;
    int rightShift = gcdResult >> 1;

    printf("Left shift of %d by 2 bits is %d.\n", gcdResult, leftShift);
    printf("Right shift of %d by 1 bit is %d.\n", gcdResult, rightShift);

    // Mathematical challenge
    int c = 5;
    float d = 2.5;

    float result1 = a + b + c + d;
    float result2 = (a * b) / (c - d);

    printf("The result of the mathematical expression %d + %d + %d + %f is %f.\n", a, b, c, d, result1);
    printf("The result of the mathematical expression (%d * %d) / (%d - %f) is %f.\n", a, b, c, d, result2);

    return 0;
}