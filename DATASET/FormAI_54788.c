//FormAI DATASET v1.0 Category: Bitwise operations ; Style: enthusiastic
#include <stdio.h>

int main() 
{
    int a = 101; 
    int b = 42; 
    int c = 0; 

    printf("Let's do some bitwise magic!\n");

    printf("a = %d, b = %d\n", a, b);

    // Bitwise AND
    c = a & b;
    printf("a & b = %d\n", c);

    // Bitwise OR
    c = a | b;
    printf("a | b = %d\n", c);

    // Bitwise XOR
    c = a ^ b;
    printf("a ^ b = %d\n", c);

    // Bitwise NOT
    c = ~a;
    printf("~a = %d\n", c);

    // Bitwise LEFT SHIFT
    c = a << 2;
    printf("a << 2 = %d\n", c);

    // Bitwise RIGHT SHIFT
    c = a >> 2;
    printf("a >> 2 = %d\n", c);

    printf("Let's try some bitmasking!\n");

    int x = 0b11010101;
    printf("x = %d\n", x);

    // Set bit 3 to 0
    x &= ~(1 << 3);
    printf("x with bit 3 set to 0: %d\n", x);

    // Set bit 4 to 1
    x |= (1 << 4);
    printf("x with bit 4 set to 1: %d\n", x);

    // Toggle bit 5
    x ^= (1 << 5);
    printf("x with bit 5 toggled: %d\n", x);

    printf("That's all folks!");
    return 0;
}