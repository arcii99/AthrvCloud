//FormAI DATASET v1.0 Category: Bitwise operations ; Style: standalone
#include <stdio.h>

int main() {
    int a, b, c;

    printf("Enter value of a: ");
    scanf("%d", &a);
    printf("Enter value of b: ");
    scanf("%d", &b);

    // Bitwise AND operator
    c = a & b;
    printf("a & b = %d\n", c);

    // Bitwise OR operator
    c = a | b;
    printf("a | b = %d\n", c);

    // Bitwise XOR operator
    c = a ^ b;
    printf("a ^ b = %d\n", c);

    // Bitwise compliment operator
    c = ~a;
    printf("~a = %d\n", c);

    // Left shift operator
    c = a << 2;
    printf("a << 2 = %d\n", c);

    // Right shift operator
    c = b >> 1;
    printf("b >> 1 = %d\n", c);

    return 0;
}