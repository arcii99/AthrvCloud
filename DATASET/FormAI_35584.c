//FormAI DATASET v1.0 Category: Bitwise operations ; Style: surprised
#include <stdio.h>

int main() {
    printf("Surprise! Let's play with some bitwise magic today!\n");
    int a = 5, b = 9, c, d, e, f;

    // Bitwise AND operator
    c = a & b;
    printf("%d & %d = %d\n", a, b, c);

    // Bitwise OR operator
    d = a | b;
    printf("%d | %d = %d\n", a, b, d);

    // Bitwise XOR operator
    e = a ^ b;
    printf("%d ^ %d = %d\n", a, b, e);

    // Bitwise complement operator
    f = ~a;
    printf("~%d = %d\n", a, f);

    // Left shift operator
    c = a << 2;
    printf("%d << 2 = %d\n", a, c);

    // Right shift operator
    d = b >> 1;
    printf("%d >> 1 = %d\n", b, d);

    // Conditional operator
    printf("%d && %d is %d\n", a, b, a && b);

    // Bitwise AND assignment operator
    a &= b;
    printf("%d &= %d, a = %d\n", a, b, a);

    // Bitwise XOR assignment operator
    a ^= b;
    printf("%d ^= %d, a = %d\n", a, b, a);

    // Bitwise OR assignment operator
    a |= b;
    printf("%d |= %d, a = %d\n", a, b, a);

    return 0;
}