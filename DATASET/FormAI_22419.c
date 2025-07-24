//FormAI DATASET v1.0 Category: Bitwise operations ; Style: interoperable
#include <stdio.h>

int main() {
    int a = 13; //   Binary equivalent is 1101
    int b = 10; //   Binary equivalent is 1010

    int c = a & b; //   Binary equivalent of a & b is 1000. Therefore c will be 8.
    int d = a | b; //   Binary equivalent of a | b is 1111. Therefore d will be 15.
    int e = a ^ b; //   Binary equivalent of a ^ b is 0111. Therefore e will be 7.
    int f = ~a; //   Binary equivalent of ~a is 0010. Therefore f will be -14.
    int g = a << 2; //   Left shift operation of a by 2 is equivalent to multiplying a by 2^2. So g will be 52.
    int h = a >> 2; //   Right shift operation of a by 2 is equivalent to integer division of a by 2^2. So h will be 3.

    printf("a & b = %d\n", c);
    printf("a | b = %d\n", d);
    printf("a ^ b = %d\n", e);
    printf("~a = %d\n", f);
    printf("a << 2 = %d\n", g);
    printf("a >> 2 = %d\n", h);

    return 0;
}