//FormAI DATASET v1.0 Category: Bitwise operations ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

int main() {
    // Let's start with a simple decimal number
    int num = 42;
    printf("The decimal number is %d\n", num);

    // Let's convert it to binary using bitwise operators
    int mask;
    for (mask = 1 << 30; mask > 0; mask >>= 1) {
        printf("%d", (num & mask) ? 1 : 0);
    }
    printf("\n");

    // Now let's try some bitwise operations
    int a = 13;
    int b = 7;
    int c;

    // Bitwise AND
    c = a & b;
    printf("%d & %d = %d\n", a, b, c);

    // Bitwise OR
    c = a | b;
    printf("%d | %d = %d\n", a, b, c);

    // Bitwise XOR
    c = a ^ b;
    printf("%d ^ %d = %d\n", a, b, c);

    // Bitwise NOT
    c = ~a;
    printf("~%d = %d\n", a, c);

    // Bitwise left shift
    c = a << 2;
    printf("%d << 2 = %d\n", a, c);

    // Bitwise right shift
    c = a >> 1;
    printf("%d >> 1 = %d\n", a, c);

    return 0;
}