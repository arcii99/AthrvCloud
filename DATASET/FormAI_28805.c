//FormAI DATASET v1.0 Category: Math exercise ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int n;
    printf("Enter the range (n) of the numbers to be generated: ");
    scanf("%d", &n);

    int num1 = rand() % n + 1;
    int num2 = rand() % n + 1;

    printf("Sum of %d and %d is: %d\n", num1, num2, num1 + num2);

    int num3 = rand() % n + 1;
    int num4 = rand() % n + 1;

    printf("Difference between %d and %d is: %d\n", num3, num4, abs(num3 - num4));

    int num5 = rand() % n + 1;
    int num6 = rand() % n + 1;

    printf("Product of %d and %d is: %d\n", num5, num6, num5 * num6);

    int num7 = rand() % n + 1;
    int num8 = rand() % n + 1;

    printf("Quotient of %d divided by %d is: %d\n", num7, num8, num7 / num8);

    int num9 = rand() % n + 1;
    int num10 = rand() % n + 1;

    printf("Remainder of %d divided by %d is: %d\n", num9, num10, num9 % num10);

    return 0;
}