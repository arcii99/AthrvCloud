//FormAI DATASET v1.0 Category: Bitwise operations ; Style: statistical
#include<stdio.h>

int main(){

    int a = 5;  // a is represented in binary as 101
    int b = 2;  // b is represented in binary as 010

    // Bitwise AND Operator (&)

    int c = a & b;   // performs a bitwise AND operation on a and b
    // binary representation of c will be 
    // 101   (a)
    // 010   (b)
    // ---
    // 000   (c)
    printf("Bitwise AND:\n");
    printf("%d & %d = %d\n\n", a, b, c);

    // Bitwise OR Operator (|)

    int d = a | b;   // performs a bitwise OR operation on a and b
    // binary representation of d will be 
    // 101   (a)
    // 010   (b)
    // ---
    // 111   (d)
    printf("Bitwise OR:\n");
    printf("%d | %d = %d\n\n", a, b, d);

    // Bitwise XOR Operator (^)

    int e = a ^ b;   // performs a bitwise XOR operation on a and b
    // binary representation of e will be 
    // 101   (a)
    // 010   (b)
    // ---
    // 111   (e)

    printf("Bitwise XOR:\n");
    printf("%d ^ %d = %d\n\n", a, b, e);

    // Bitwise NOT Operator (~)

    int f = ~a;   // performs a bitwise NOT operation on a
    // binary representation of f will be 
    // 101   (a)
    // ---
    // 010   (f)
    printf("Bitwise NOT:\n");
    printf("~%d = %d\n\n", a, f);

    // Bitwise LEFT SHIFT Operator (<<)

    int g = a << 2;   // performs a bitwise LEFT SHIFT operation on a by 2 bits
    // binary representation of g will be 
    // 101   (a)
    // --
    //10100  (g)
    printf("Bitwise LEFT SHIFT:\n");
    printf("%d << 2 = %d\n\n", a, g);

    // Bitwise RIGHT SHIFT Operator (>>)

    int h = a >> 2;   // performs a bitwise RIGHT SHIFT operation on a by 2 bits
    // binary representation of h will be 
    // 101   (a)
    // --
    // 001   (h)
    printf("Bitwise RIGHT SHIFT:\n");
    printf("%d >> 2 = %d\n\n", a, h);

    return 0;
}