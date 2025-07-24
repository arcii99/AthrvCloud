//FormAI DATASET v1.0 Category: Arithmetic ; Style: optimized
#include <stdio.h>

int main() {
    int a = 10, b = 20, c = 30;
    float d = 1.5, e = 2.5, f = 5.0;
    double g = 3.1415927;

    // Arithmetic operations
    printf("a + b = %d\n", a + b);
    printf("a - b - c = %d\n", a - b - c);
    printf("d * e = %f\n", d * e);
    printf("f / d = %f\n", f / d);
    printf("g + b = %.8lf\n", g + b);

    // Increment and decrement
    printf("a++ = %d\n", a++);
    printf("++b = %d\n", ++b);
    printf("c-- = %d\n", c--);
    printf("--d = %.3f\n", --d);

    // Bitwise operations
    printf("a & b = %d\n", a & b);
    printf("a | c = %d\n", a | c);
    printf("b ^ c = %d\n", b ^ c);
    printf("~a = %d\n", ~a);

    // Shift operations
    printf("a << 2 = %d\n", a << 2);
    printf("b >> 1 = %d\n", b >> 1);

    // Assignment operators
    a += b;
    printf("a = %d\n", a);
    c -= a;
    printf("c = %d\n", c);
    f *= d;
    printf("f = %f\n", f);
    e /= g;
    printf("e = %f\n", e);

    // Conditional operators
    int x = a > b ? a : b;
    printf("x = %d\n", x);
    int y = c < b ? c : b;
    printf("y = %d\n", y);

    return 0;
}