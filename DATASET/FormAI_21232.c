//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Cryptic
#include <stdio.h>

int main() {
    int a = 9, b = 3;
    int c = b ^ a; // Bitwise XOR
    int d = c << 2; // Bitwise left shift
    int e = ~d; // Bitwise NOT

    printf("a: %d, b: %d\n", a, b);
    printf("c: %d\n", c);
    printf("d: %d\n", d);
    printf("e: %d\n", e);

    int x = 0b0110; // Binary representation of 6
    int y = 0b1001; // Binary representation of 9

    int z = x | y; // Bitwise OR
    printf("z: %d\n", z);

    int i = x & y; // Bitwise AND
    printf("i: %d\n", i);

    int j = x ^ y; // Bitwise XOR
    printf("j: %d\n", j);

    int k = ~x; // Bitwise NOT
    printf("k: %d\n", k);

    int l = y >> 2; // Bitwise right shift
    printf("l: %d\n", l);

    int m = x << 2; // Bitwise left shift
    printf("m: %d\n", m);

    return 0;
}