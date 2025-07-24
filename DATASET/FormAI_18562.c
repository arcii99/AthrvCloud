//FormAI DATASET v1.0 Category: Bitwise operations ; Style: energetic
#include<stdio.h>

int main() {
    int a, b;
    printf("Enter the value of a and b: ");
    scanf("%d %d", &a, &b);

    printf("\nBitwise AND: %d", a & b);
    printf("\nBitwise OR: %d", a | b);
    printf("\nBitwise XOR: %d", a ^ b);
    printf("\nBitwise NOT of a: %d", ~a);
    printf("\nBitwise NOT of b: %d", ~b);
    printf("\nLeft shift of a by 1 bit: %d", a << 1);
    printf("\nRight shift of a by 1 bit: %d", a >> 1);
    printf("\nLeft shift of b by 1 bit: %d", b << 1);
    printf("\nRight shift of b by 1 bit: %d", b >> 1);

    return 0;
}