//FormAI DATASET v1.0 Category: Math exercise ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

int gcd(int a, int b);

int main()
{
    int num1, num2;
    printf("Enter two numbers: ");
    scanf("%d %d", &num1, &num2);

    int result = gcd(num1, num2);
    printf("The GCD of %d and %d is %d", num1, num2, result);

    return 0;
}

int gcd(int a, int b)
{
    if (a == 0)
        return b;
    if (b == 0)
        return a;
    if (a == b)
        return a;

    if (a > b)
        return gcd(a-b, b);
    return gcd(a, b-a);
}