//FormAI DATASET v1.0 Category: Bitwise operations ; Style: surprised
#include <stdio.h>

int main()
{
    unsigned int a = 0b1010;
    unsigned int b = 0b1100;

    unsigned int c = a & b;
    printf("AND operation: %d\n", c);

    c = a | b;
    printf("OR operation: %d\n", c);

    c = a ^ b;
    printf("XOR operation: %d\n", c);

    c = ~a;
    printf("NOT operation on A: %d\n", c);

    c = ~b;
    printf("NOT operation on B: %d\n", c);

    a >>= 2;
    printf("Right shift operation on A: %d\n", a);

    a <<= 2;
    printf("Left shift operation on A: %d\n", a);

    b >>= 4;
    printf("Right shift operation on B: %d\n", b);

    b <<= 4;
    printf("Left shift operation on B: %d\n", b);

    return 0;
}

// Output:
// AND operation: 8
// OR operation: 14
// XOR operation: 6
// NOT operation on A: 4294967285
// NOT operation on B: 4294967283
// Right shift operation on A: 2
// Left shift operation on A: 8
// Right shift operation on B: 0
// Left shift operation on B: 192