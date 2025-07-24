//FormAI DATASET v1.0 Category: Bitwise operations ; Style: automated
#include <stdio.h>

int main() {
    // Bitwise AND
    int a = 10;     // 1010 in binary
    int b = 7;      // 0111 in binary
    int result = a & b;
    printf("%d & %d = %d\n", a, b, result);   // Output: 2

    // Bitwise OR
    result = a | b;
    printf("%d | %d = %d\n", a, b, result);   // Output: 15

    // Bitwise NOT
    result = ~a;
    printf("~%d = %d\n", a, result);          // Output: -11

    // Bitwise XOR
    result = a ^ b;
    printf("%d ^ %d = %d\n", a, b, result);   // Output: 13

    // Left shift
    result = a << 2;
    printf("%d << 2 = %d\n", a, result);      // Output: 40

    // Right shift
    result = a >> 2;
    printf("%d >> 2 = %d\n", a, result);      // Output: 2

    return 0;
}