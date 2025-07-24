//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Ada Lovelace
#include <stdio.h>

int main()
{
    int a = 35;     // Binary representation: 00100011
    int b = 53;     // Binary representation: 00110101
    
    // Bitwise AND operator
    int c = a & b;  // Binary representation of c: 00100001
    printf("%d & %d = %d\n", a, b, c);

    // Bitwise OR operator
    int d = a | b;  // Binary representation of d: 00110111
    printf("%d | %d = %d\n", a, b, d);

    // Bitwise XOR operator
    int e = a ^ b;  // Binary representation of e: 00010110
    printf("%d ^ %d = %d\n", a, b, e);

    // Left shift operator
    int f = a << 2; // Binary representation of f: 10001100
    printf("%d << 2 = %d\n", a, f);

    // Right shift operator
    int g = b >> 3; // Binary representation of g: 00000110
    printf("%d >> 3 = %d\n", b, g);
    
    return 0;
}