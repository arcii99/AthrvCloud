//FormAI DATASET v1.0 Category: Arithmetic ; Style: visionary
#include <stdio.h>

int gcd(int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

int main() {
    int num1, num2, greatest_common_divisor;

    printf("Please enter two numbers separated by a space: ");
    scanf("%d %d", &num1, &num2);

    greatest_common_divisor = gcd(num1, num2);

    printf("The greatest common divisor of %d and %d is %d.\n", num1, num2, greatest_common_divisor);

    return 0;
}