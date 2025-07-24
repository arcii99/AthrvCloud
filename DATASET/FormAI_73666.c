//FormAI DATASET v1.0 Category: Bitwise operations ; Style: surprised
#include <stdio.h>

int main() {
    int a = 42;
    int b = 28;
    printf("Surprise! Let's see the magic of Bitwise Operation\n\n");

    printf("a = %d\n", a);
    printf("b = %d\n", b);

    printf("\nBitwise AND Operator(&) between a and b: %d\n", a & b);
    printf("Bitwise OR Operator(|) between a and b: %d\n", a | b);
    printf("Bitwise XOR Operator(^) between a and b: %d\n", a ^ b);

    printf("\nBitwise NOT Operator(~) on a: %d\n", ~a);

    printf("\nLeft Shift Operator(<<) on a by 2 bits: %d\n", a << 2);
    printf("Right Shift Operator(>>) on b by 2 bits: %d\n", b >> 2);

    printf("\nLet's combine all the bitwise operators on a and b\n");
    printf("((a & b) | (a ^ b)) << 2: %d\n", ((a & b) | (a ^ b)) << 2);

    printf("\nSurprised? See the magic of Bitwise Operation in Decimal, Hexadecimal and Binary Format\n");
    printf("a in decimal: %d, in hexadecimal: %x, in binary: %d\n", a, a, a);
    printf("b in decimal: %d, in hexadecimal: %x, in binary: %d\n", b, b, b);

    return 0;
}