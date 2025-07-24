//FormAI DATASET v1.0 Category: Arithmetic ; Style: all-encompassing
#include<stdio.h>
int main()
{
    int a = 10, b = 20, c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r, s, t;

    // Add two numbers
    c = a + b;
    printf("Addition of %d and %d is %d\n", a, b, c);

    // Subtract two numbers
    d = b - a;
    printf("Subtraction of %d from %d is %d\n", a, b, d);

    // Multiply two numbers
    e = a * b;
    printf("Multiplication of %d and %d is %d\n", a, b, e);

    // Divide two numbers
    f = b / a;
    printf("Division of %d by %d is %d\n", b, a, f);

    // Modulo of two numbers
    g = b % a;
    printf("Modulo of %d by %d is %d\n", b, a, g);

    // Increment and Decrement
    h = a++;
    i = b--;
    printf("After Increment and Decrement, a is %d and b is %d\n", h, i);

    // Bitwise Operators
    j = a & b;
    k = a | b;
    l = a ^ b;
    m = ~a;
    n = b << 2;
    o = b >> 2;
    printf("Bitwise AND of %d and %d is %d\n", a, b, j);
    printf("Bitwise OR of %d and %d is %d\n", a, b, k);
    printf("Bitwise XOR of %d and %d is %d\n", a, b, l);
    printf("Bitwise NOT of %d is %d\n", a, m);
    printf("%d left shifted by 2 bits is %d\n", b, n);
    printf("%d right shifted by 2 bits is %d\n", b, o);

    // Logical Operators
    p = (a == b);
    q = (a != b);
    r = (a && b);
    s = (a || b);
    printf("%d is equal to %d is %d\n", a, b, p);
    printf("%d is not equal to %d is %d\n", a, b, q);
    printf("%d AND %d is %d\n", a, b, r);
    printf("%d OR %d is %d\n", a, b, s);

    // Ternary Operator
    t = (a > b) ? a : b;
    printf("Greater number between %d and %d is %d\n", a, b, t);

    return 0;
}