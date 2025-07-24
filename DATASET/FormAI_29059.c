//FormAI DATASET v1.0 Category: Bitwise operations ; Style: shape shifting
#include <stdio.h>

int main() {
    int x = 10, y = 3;

    printf("Let's start with x = %d and y = %d\n\n", x, y);

    printf("Shapeshift: x & y = %d\n", x & y); // Bitwise AND
    printf("Shapeshift: x | y = %d\n", x | y); // Bitwise OR
    printf("Shapeshift: x ^ y = %d\n", x ^ y); // Bitwise XOR
    printf("Shapeshift: ~x = %d\n", ~x); // Bitwise NOT (one's complement)
    printf("Shapeshift: x << y = %d\n", x << y); // Bitwise left shift
    printf("Shapeshift: x >> y = %d\n", x >> y); // Bitwise right shift

    printf("\nNow let's combine some bitwise operations\n");

    int a = 7, b = 12, c = 3;

    printf("Shapeshift: a & b = %d\n", a & b); // Bitwise AND
    printf("Shapeshift: a & c = %d\n", a & c); // Bitwise AND
    printf("Shapeshift: b | c = %d\n", b | c); // Bitwise OR
    printf("Shapeshift: ~a = %d\n", ~a); // Bitwise NOT (one's complement)
    printf("Shapeshift: b << c = %d\n", b << c); // Bitwise left shift
    printf("Shapeshift: b >> c = %d\n", b >> c); // Bitwise right shift

    printf("\nNow let's get a little crazy...\n");

    int d = 23, e = 9, f = 16, g = 2;

    printf("Shapeshift: ((d | e) & (f & ~g)) ^ (e << g) = %d\n", ((d | e) & (f & ~g)) ^ (e << g)); // Combination of bitwise operations

    return 0;
}