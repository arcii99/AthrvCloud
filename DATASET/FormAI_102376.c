//FormAI DATASET v1.0 Category: Bitwise operations ; Style: introspective
#include <stdio.h>

int main() {
    int a = 23;
    int b = 13;

    // C Bitwise OR operator
    int c = a | b;
    printf("Bitwise OR: %d | %d = %d\n", a, b, c);

    // C Bitwise AND operator
    c = a & b;
    printf("Bitwise AND: %d & %d = %d\n", a, b, c);

    // C Bitwise XOR operator
    c = a ^ b;
    printf("Bitwise XOR: %d ^ %d = %d\n", a, b, c);

    // C Bitwise left shift operator
    c = a << 2;
    printf("Bitwise left shift: %d << 2 = %d\n", a, c);

    // C Bitwise right shift operator
    c = a >> 2;
    printf("Bitwise right shift: %d >> 2 = %d\n", a, c);

    // C Bitwise NOT operator
    c = ~a;
    printf("Bitwise NOT: ~%d = %d\n", a, c);

    return 0;
}