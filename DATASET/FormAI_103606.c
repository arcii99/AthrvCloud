//FormAI DATASET v1.0 Category: Bitwise operations ; Style: satisfied
#include <stdio.h>

int main() {
    int a = 5; // 101
    int b = 7; // 111

    int c = a & b; // Bitwise AND operation
    printf("Bitwise AND of a and b: %d\n", c);

    int d = a | b; // Bitwise OR operation
    printf("Bitwise OR of a and b: %d\n", d);

    int e = a ^ b; // Bitwise XOR operation
    printf("Bitwise XOR of a and b: %d\n", e);

    int f = ~a; // Bitwise NOT operation
    printf("Bitwise NOT of a: %d\n", f);

    int g = a << 2; // Bitwise left shift
    printf("Bitwise left shift of a by 2: %d\n", g);

    int h = b >> 1; // Bitwise right shift
    printf("Bitwise right shift of b by 1: %d\n", h);

    int i = (a & b) << 1; // Combination of operations
    printf("Bitwise AND of a and b, then left shift by 1: %d\n", i);

    return 0;
}