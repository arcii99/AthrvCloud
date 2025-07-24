//FormAI DATASET v1.0 Category: Bitwise operations ; Style: mathematical
#include <stdio.h>

int main() {
    int a = 42;
    int b = 21;
    int c = (a & b); // bitwise AND
    int d = (a | b); // bitwise OR
    int e = (a ^ b); // bitwise XOR
    int f = (~a); // bitwise NOT (complement)
    int g = (a << 1); // left shift
    int h = (a >> 1); // right shift

    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("a & b = %d\n", c);
    printf("a | b = %d\n", d);
    printf("a ^ b = %d\n", e);
    printf("~a = %d\n", f);
    printf("a << 1 = %d\n", g);
    printf("a >> 1 = %d\n", h);

    return 0;
}