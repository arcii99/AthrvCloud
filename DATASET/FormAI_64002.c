//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Claude Shannon
#include <stdio.h>

int main() {
    unsigned int a = 15; // 00001111
    unsigned int b = 7; // 00000111
    unsigned int c, d, e, f;

    c = a & b; // bitwise AND
    d = a | b; // bitwise OR
    e = a ^ b; // bitwise XOR
    f = ~a; // bitwise NOT

    printf("a & b = %u\n", c);
    printf("a | b = %u\n", d);
    printf("a ^ b = %u\n", e);
    printf("~a = %u\n", f);

    return 0;
}