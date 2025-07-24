//FormAI DATASET v1.0 Category: Bitwise operations ; Style: future-proof
#include <stdio.h>

// Function to print binary representation of a number
void printBinary(unsigned int num) {
    for (int i = sizeof(num) * 8 - 1; i >= 0; i--) {
        (num & (1u << i)) ? putchar('1') : putchar('0');
    }
    printf("\n");
}

// Bitwise operations example program
int main() {
    unsigned int a = 0xAAAA5555, b = 0x5555AAAA;
    unsigned int c, d, e, f, g, h, i, j, k, l, m, n, o, p, q, r;
    
    // Bitwise NOT
    c = ~a;
    printf("Bitwise NOT:\n");
    printf("a    = "); printBinary(a);
    printf("NOT a= "); printBinary(c);
    
    // Bitwise AND
    d = a & b;
    printf("\nBitwise AND:\n");
    printf("a    = "); printBinary(a);
    printf("b    = "); printBinary(b);
    printf("a AND b = "); printBinary(d);
    
    // Bitwise OR
    e = a | b;
    printf("\nBitwise OR:\n");
    printf("a    = "); printBinary(a);
    printf("b    = "); printBinary(b);
    printf("a OR b  = "); printBinary(e);
    
    // Bitwise XOR
    f = a ^ b;
    printf("\nBitwise XOR:\n");
    printf("a    = "); printBinary(a);
    printf("b    = "); printBinary(b);
    printf("a XOR b= "); printBinary(f);
    
    // Bitwise Left Shift
    g = a << 4;
    printf("\nBitwise Left Shift:\n");
    printf("a    = "); printBinary(a);
    printf("a << 4 = "); printBinary(g);
    
    // Bitwise Right Shift
    h = a >> 4;
    printf("\nBitwise Right Shift:\n");
    printf("a    = "); printBinary(a);
    printf("a >> 4 = "); printBinary(h);
    
    // Bitwise Left Rotate
    i = (a << 4) | (a >> 28);
    printf("\nBitwise Left Rotate:\n");
    printf("a      = "); printBinary(a);
    printf("a << 4 = "); printBinary(a << 4);
    printf("a >> 28= "); printBinary(a >> 28);
    printf("a Rotate Left by 4 = "); printBinary(i);
    
    // Bitwise Right Rotate
    j = (a >> 4) | (a << 28);
    printf("\nBitwise Right Rotate:\n");
    printf("a      = "); printBinary(a);
    printf("a >> 4 = "); printBinary(a >> 4);
    printf("a << 28= "); printBinary(a << 28);
    printf("a Rotate Right by 4 = "); printBinary(j);
    
    // Bitwise AND Assignment
    k = a;
    k &= b;
    printf("\nBitwise AND Assignment:\n");
    printf("a      = "); printBinary(a);
    printf("b      = "); printBinary(b);
    printf("a AND b= "); printBinary(k);
    
    // Bitwise OR Assignment
    l = a;
    l |= b;
    printf("\nBitwise OR Assignment:\n");
    printf("a      = "); printBinary(a);
    printf("b      = "); printBinary(b);
    printf("a OR b = "); printBinary(l);
    
    // Bitwise XOR Assignment
    m = a;
    m ^= b;
    printf("\nBitwise XOR Assignment:\n");
    printf("a        = "); printBinary(a);
    printf("b        = "); printBinary(b);
    printf("a XOR b  = "); printBinary(m);
    
    // Bitwise Left Shift Assignment
    n = a;
    n <<= 4;
    printf("\nBitwise Left Shift Assignment:\n");
    printf("a        = "); printBinary(a);
    printf("a << 4   = "); printBinary(a << 4);
    printf("a <<= 4  = "); printBinary(n);
    
    // Bitwise Right Shift Assignment
    o = a;
    o >>= 4;
    printf("\nBitwise Right Shift Assignment:\n");
    printf("a        = "); printBinary(a);
    printf("a >> 4   = "); printBinary(a >> 4);
    printf("a >>= 4  = "); printBinary(o);
    
    // Bitwise Left Rotate Assignment
    p = a;
    p = (p << 4) | (p >> 28);
    printf("\nBitwise Left Rotate Assignment:\n");
    printf("a              = "); printBinary(a);
    printf("a << 4         = "); printBinary(a << 4);
    printf("a >> 28        = "); printBinary(a >> 28);
    printf("a Rotate Left  = "); printBinary(p);
    
    // Bitwise Right Rotate Assignment
    q = a;
    q = (q >> 4) | (q << 28);
    printf("\nBitwise Right Rotate Assignment:\n");
    printf("a              = "); printBinary(a);
    printf("a >> 4         = "); printBinary(a >> 4);
    printf("a << 28        = "); printBinary(a << 28);
    printf("a Rotate Right = "); printBinary(q);
    
    // Bitwise Conditional Operator
    r = (a == b) ? 0xFFFFFFFF : 0x00000000;
    printf("\nBitwise Conditional Operator:\n");
    printf("a     = "); printBinary(a);
    printf("b     = "); printBinary(b);
    printf("a == b= "); printBinary(a == b);
    printf("(a == b) ? 0xFFFFFFFF : 0x00000000 = "); printBinary(r);
    
    return 0;
}