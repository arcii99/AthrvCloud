//FormAI DATASET v1.0 Category: Arithmetic ; Style: optimized
#include <stdio.h>

int main() {
    int a = 10, b = 20, c = 30;
    float d = 2.5, e = 3.5, f = 4.5;

    printf("Initial Values:\n a = %d, b = %d, c = %d, d = %f, e = %f, f = %f\n\n", a, b, c, d, e, f);

    // Increment operator demonstration
    printf("After Increment a, b, c by 1:\n a = %d, b = %d, c = %d\n", ++a, ++b, ++c);

    // Decrement operator demonstration
    printf("After Decrement a, b, c by 1:\n a = %d, b = %d, c = %d\n\n", --a, --b, --c);

    // Multiplication operatordemonstration
    printf("Multiplication of a and b:\n %d x %d = %d\n", a, b, a * b);

    // Division operator demonstration
    printf("Division of a by b:\n %d / %d = %.3f\n", a, b, (float)a/b);

    // Modulus operator demonstration
    printf("Modulus of b by c:\n %d %% %d = %d\n\n", b, c, b % c);

    // Relational operator demonstration
    printf("Is a greater than b?:\n %d > %d = %d\n", a, b, a > b);

    // Logical operator demonstration
    printf("Is e less than d and b less than c?:\n %f < %f && %d < %d = %d\n\n", e, d, b, c, (e < d && b < c));

    // Ternary operator demonstration
    int result = (a < c) ? 100 : 200;
    printf("If a is less than c, result is 100, else result is 200:\n Result = %d\n", result);

    // Bitwise operator demonstration
    int x = 5; // Binary equivalent of 5 is 0101
    int y = 6; // Binary equivalent of 6 is 0110

    printf("Bitwise AND of x and y:\n %d & %d = %d\n", x, y, x & y);

    printf("Bitwise OR of x and y:\n %d | %d = %d\n", x, y, x | y);

    printf("Bitwise XOR of x and y:\n %d ^ %d = %d\n", x, y, x ^ y);

    // Shift operator demonstration
    int z = 10; // Binary equivalent of 10 is 1010

    printf("Left shift of z by 2 bits:\n %d << 2 = %d\n", z, z << 2);

    printf("Right shift of z by 2 bits:\n %d >> 2 = %d\n", z, z >> 2);

    // Assignment operator demonstration
    int p = 10;
    p += 5; // Same as p = p + 5
    printf("If p is initially 10, after p += 5, p will be:\n p = %d\n", p);

    p *= 2; // Same as p = p * 2
    printf("After p *= 2:\n p = %d\n\n", p);

    // Size of operator demonstration
    printf("Size of int is %d bytes\n", sizeof(int));

    printf("Size of float is %d bytes\n", sizeof(float));

    printf("Size of char is %d bytes\n", sizeof(char));

    printf("Size of double is %d bytes\n\n", sizeof(double));

    return 0;
}