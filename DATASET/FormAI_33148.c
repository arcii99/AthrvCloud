//FormAI DATASET v1.0 Category: Bitwise operations ; Style: peaceful
#include <stdio.h>

int main() {

    int a = 8; // 1000 in binary
    int b = 7; // 0111 in binary

    printf("The bitwise AND operation of %d and %d is %d\n", a, b, a & b);

    printf("The bitwise OR operation of %d and %d is %d\n", a, b, a | b);

    printf("The bitwise XOR operation of %d and %d is %d\n", a, b, a ^ b);

    printf("The bitwise NOT operation of %d is %d\n", a, ~a);

    printf("The left shift operation of %d by 2 is %d\n", a, a << 2);

    printf("The right shift operation of %d by 2 is %d\n", a, a >> 2);

    return 0;
}