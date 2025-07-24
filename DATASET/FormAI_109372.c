//FormAI DATASET v1.0 Category: Bitwise operations ; Style: satisfied
#include <stdio.h>

int main() {
    int a = 5;
    int b = 10;
    
    // Bitwise AND
    int c = a & b;
    printf("Bitwise AND of %d and %d is: %d\n", a, b, c);

    // Bitwise OR
    int d = a | b;
    printf("Bitwise OR of %d and %d is: %d\n", a, b, d);

    // Bitwise XOR
    int e = a ^ b;
    printf("Bitwise XOR of %d and %d is: %d\n", a, b, e);
    
    // Left shift
    int f = a << 2;
    printf("Left shift of %d by 2 is: %d\n", a, f);

    // Right shift
    int g = b >> 1;
    printf("Right shift of %d by 1 is: %d\n", b, g);

    // Bitwise NOT
    int h = ~a;
    printf("Bitwise NOT of %d is: %d\n", a, h);
    
    return 0;
}