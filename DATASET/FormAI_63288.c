//FormAI DATASET v1.0 Category: Educational ; Style: retro
#include <stdio.h>

int main() {
    int x = 0x85;
    int y = 0x69;
    int a, b, carry, i;

    printf("     %02x\n", x);
    printf("    + %02x\n", y);
    printf("    ----\n");

    for(i=0; i<8; i++) {
        a = (x>>i) & 1;
        b = (y>>i) & 1;
        carry = (a & b) | (a & carry) | (b & carry);
        x = x ^ y;
        y = carry << i;
    }

    printf("     %02x\n", x);

    return 0;
}