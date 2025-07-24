//FormAI DATASET v1.0 Category: Bitwise operations ; Style: standalone
#include <stdio.h>

int main() {
    // Bitwise AND
    int a = 5; // 00000101 in binary
    int b = 3; // 00000011 in binary
    int and_result = a & b; // 00000001 in binary
    printf("Bitwise AND: %d & %d = %d\n", a, b, and_result);

    // Bitwise OR
    int c = 5; // 00000101 in binary
    int d = 3; // 00000011 in binary
    int or_result = c | d; // 00000111 in binary
    printf("Bitwise OR: %d | %d = %d\n", c, d, or_result);

    // Bitwise XOR
    int e = 5; // 00000101 in binary
    int f = 3; // 00000011 in binary
    int xor_result = e ^ f; // 00000110 in binary
    printf("Bitwise XOR: %d ^ %d = %d\n", e, f, xor_result);

    // Bitwise NOT
    int g = 5; // 00000101 in binary
    int not_result = ~g; // 11111010 in binary (two's complement representation)
    printf("Bitwise NOT: ~%d = %d\n", g, not_result);

    // Left shift
    int h = 5; // 00000101 in binary
    int left_shift_result = h << 2; // 00010100 in binary (20 in decimal)
    printf("Left shift: %d << 2 = %d\n", h, left_shift_result);

    // Right shift
    int i = 20; // 00010100 in binary
    int right_shift_result = i >> 2; // 00000101 in binary (5 in decimal)
    printf("Right shift: %d >> 2 = %d\n", i, right_shift_result);

    return 0;
}