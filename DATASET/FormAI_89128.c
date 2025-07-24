//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Claude Shannon
#include <stdio.h>

int main() {
    // define two variables with binary representation
    int a = 0b00000110;
    int b = 0b00001101;
    
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    
    // bitwise AND operation
    int c = a & b;
    printf("a & b = %d\n", c);
    
    // bitwise OR operation
    int d = a | b;
    printf("a | b = %d\n", d);
    
    // bitwise XOR operation
    int e = a ^ b;
    printf("a ^ b = %d\n", e);
    
    // bitwise NOT operation
    int f = ~a;
    printf("~a = %d\n", f);
    
    // bitwise left shift operation
    int g = a << 2;
    printf("a << 2 = %d\n", g);
    
    // bitwise right shift operation
    int h = b >> 1;
    printf("b >> 1 = %d\n", h);
    
    return 0;
}