//FormAI DATASET v1.0 Category: Bitwise operations ; Style: shocked
#include<stdio.h>

int main() {

    int a = 7; // 0111
    int b = 10; // 1010

    printf("Bitwise AND Operator (&)\n");
    printf("%d & %d = %d\n", a, b, a & b); // 0111 & 1010 = 0010

    printf("\nBitwise OR Operator (|)\n");
    printf("%d | %d = %d\n", a, b, a | b); // 0111 | 1010 = 1111

    printf("\nBitwise XOR Operator (^)\n");
    printf("%d ^ %d = %d\n", a, b, a ^ b); // 0111 ^ 1010 = 1101

    printf("\nBitwise Complement Operator (~)\n");
    printf("~%d = %d\n", a, ~a); // ~0111 = 1000

    printf("\nLeft Shift Operator (<<)\n");
    printf("%d << 2 = %d\n", a, a << 2); // 0111 << 2 = 11100

    printf("\nRight Shift Operator (>>)\n");
    printf("%d >> 2 = %d\n", b, b >> 2); // 1010 >> 2 = 0010

    return 0;
}