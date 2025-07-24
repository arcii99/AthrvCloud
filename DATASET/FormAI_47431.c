//FormAI DATASET v1.0 Category: Bitwise operations ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

int main() {
    int a = 12, b = 20;

    printf("Bitwise AND operation: %d\n", a & b);
    printf("Bitwise OR operation: %d\n", a | b);
    printf("Bitwise XOR operation: %d\n", a ^ b);
    printf("Bitwise NOT operation on a: %d\n", ~a);
    printf("Bitwise NOT operation on b: %d\n", ~b);

    int c = 30, d = 40, e = 50, f = 60, result;

    result = (c & d) | (e ^ f);

    printf("Result of Bitwise AND operation between c and d: %d\n", c & d);
    printf("Result of Bitwise XOR operation between e and f: %d\n", e ^ f);
    printf("Result of Bitwise OR operation between %d and %d: %d\n", c & d, e ^ f, result);

    int num = 10; // Binary representation: 0000 1010

    printf("Value of num before shifting: %d\n", num);
    num <<= 2; // Left shift by 2 bits: 0010 1000
    printf("Value of num after left shift: %d\n", num);
    num >>= 3; // Right shift by 3 bits: 0000 0101
    printf("Value of num after right shift: %d\n", num);

    int x = 5, y = 9;
    printf("Value of x before swapping: %d\n", x);
    printf("Value of y before swapping: %d\n", y);

    // Swapping two numbers using XOR operation
    x ^= y;
    y ^= x;
    x ^= y;

    printf("Value of x after swapping: %d\n", x);
    printf("Value of y after swapping: %d\n", y);

    return 0;
}