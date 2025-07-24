//FormAI DATASET v1.0 Category: Arithmetic ; Style: curious
#include <stdio.h>

int main() {
    int number = 1;
    while (number < 10) {
        printf("I am curious to know the square of %d\n", number);
        int square = number * number;
        printf("The square of %d is %d\n", number, square);
        number++;
    }
    printf("\n");

    int a = 20;
    int b = 5;
    printf("Let's perform some arithmetic operations with a=%d and b=%d\n", a, b);

    printf("a + b = %d\n", a + b);
    printf("a - b = %d\n", a - b);
    printf("a * b = %d\n", a * b);
    printf("a / b = %d\n", a / b);

    float c = 25.5;
    float d = 6.5;
    printf("Let's perform some float arithmetic operations with c=%.2f and d=%.2f\n", c, d);

    printf("c + d = %.2f\n", c + d);
    printf("c - d = %.2f\n", c - d);
    printf("c * d = %.2f\n", c * d);
    printf("c / d = %.2f\n", c / d);

    printf("\n");

    int remainder = a % b;
    printf("The remainder when %d is divided by %d is %d\n", a, b, remainder);

    int bitwise_and = a & b;
    printf("The bitwise AND of %d and %d is %d\n", a, b, bitwise_and);

    int bitwise_or = a | b;
    printf("The bitwise OR of %d and %d is %d\n", a, b, bitwise_or);

    int bitwise_xor = a ^ b;
    printf("The bitwise XOR of %d and %d is %d\n", a, b, bitwise_xor);

    int left_shift = a << 2;
    printf("The value of %d after left shift by 2 is %d\n", a, left_shift);

    int right_shift = a >> 2;
    printf("The value of %d after right shift by 2 is %d\n", a, right_shift);

    printf("\n");

    int x = 10;
    int y = 20;
    int z = (++x, ++y, x + y);
    printf("The value of z is %d\n", z);

    return 0;
}