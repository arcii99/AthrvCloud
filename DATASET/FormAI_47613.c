//FormAI DATASET v1.0 Category: Bitwise operations ; Style: cheerful
#include <stdio.h>

int main() {
    unsigned char x = 0b01101111;
    unsigned char y = 0b10111011;

    printf("Let's play with bits!\n");
    printf("=======================\n");
    printf("x = %d (0x%02x)\n", x, x);
    printf("y = %d (0x%02x)\n", y, y);
    printf("x | y = %d (0x%02x)\n", x | y, x | y);
    printf("x & y = %d (0x%02x)\n", x & y, x & y);
    printf("~x = %d (0x%02x)\n", ~x, ~x);
    printf("~y = %d (0x%02x)\n", ~y, ~y);
    printf("x ^ y = %d (0x%02x)\n", x ^ y, x ^ y);
    printf("x << 2 = %d (0x%02x)\n", x << 2, x << 2);
    printf("y >> 3 = %d (0x%02x)\n", y >> 3, y >> 3);
    printf("=======================\n");

    return 0;
}