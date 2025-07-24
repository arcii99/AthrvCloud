//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Linus Torvalds
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("\nWelcome to the Bitwise Operations Program!\n");
    
    // Bitwise AND operator example
    unsigned int a = 0x15;
    unsigned int b = 0x23;
    unsigned int c = a & b;
    
    printf("\nBitwise AND operator example:\n");
    printf("a = 0x%x\n", a);
    printf("b = 0x%x\n", b);
    printf("c = a & b = 0x%x\n", c);
    
    // Bitwise OR operator example
    unsigned int x = 0xAF;
    unsigned int y = 0x0F;
    unsigned int z = x | y;
    
    printf("\nBitwise OR operator example:\n");
    printf("x = 0x%x\n", x);
    printf("y = 0x%x\n", y);
    printf("z = x | y = 0x%x\n", z);
    
    // Bitwise XOR operator example
    unsigned int p = 0x0A;
    unsigned int q = 0x0F;
    unsigned int r = p ^ q;
    
    printf("\nBitwise XOR operator example:\n");
    printf("p = 0x%x\n", p);
    printf("q = 0x%x\n", q);
    printf("r = p ^ q = 0x%x\n", r);
    
    // Bitwise complement operator example
    unsigned int n = 0x7F;
    unsigned int m = ~n;
    
    printf("\nBitwise complement operator example:\n");
    printf("n = 0x%x\n", n);
    printf("m = ~n = 0x%x\n", m);

    return 0;
}