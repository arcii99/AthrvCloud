//FormAI DATASET v1.0 Category: Bitwise operations ; Style: curious
#include <stdio.h>

int main() {
    int a = 9;    //binary representation is 1001
    int b = 5;    //binary representation is 0101
    int result;

    printf("The value of a is %d (binary: %d)\n", a, a);
    printf("The value of b is %d (binary: %d)\n", b, b);

    //bitwise AND operation (&)
    result = a & b;     //result: 0001 (1 in decimal)
    printf("\nBitwise AND operation:\n");
    printf("a & b = %d (binary: %d)\n", result, result);

    //bitwise OR operation (|)
    result = a | b;     //result: 1101 (13 in decimal)
    printf("\nBitwise OR operation:\n");
    printf("a | b = %d (binary: %d)\n", result, result);

    //bitwise XOR operation (^)
    result = a ^ b;     //result: 1100 (12 in decimal)
    printf("\nBitwise XOR operation:\n");
    printf("a ^ b = %d (binary: %d)\n", result, result);

    //bitwise complement operation (~)
    result = ~a;        //result: 11111111111111111111111111110110 (-10 in decimal)
    printf("\nBitwise complement operation:\n");
    printf("~a = %d (binary: %d)\n", result, result);

    //bitwise left shift operation (<<)
    result = a << 2;    //result: 36 (100100 in binary)
    printf("\nBitwise left shift operation:\n");
    printf("a << 2 = %d (binary: %d)\n", result, result);

    //bitwise right shift operation (>>)
    result = b >> 1;    //result: 2 (10 in binary)
    printf("\nBitwise right shift operation:\n");
    printf("b >> 1 = %d (binary: %d)\n", result, result);

    printf("\nHello human, this is just a small demonstration of how bitwise operations work in C programming language. Hope you found this curious!");
    return 0;
}