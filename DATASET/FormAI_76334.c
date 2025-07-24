//FormAI DATASET v1.0 Category: Bitwise operations ; Style: shocked
#include <stdio.h>

int main() {
    int a = 10, b = 7, c = 0;
    
    // Bitwise AND Operator
    c = a & b;
    printf("a & b = %d\n", c);
    
    // Bitwise OR Operator
    c = a | b;
    printf("a | b = %d\n", c);
    
    // Bitwise XOR Operator
    c = a ^ b;
    printf("a ^ b = %d\n", c);
    
    // Bitwise NOT Operator
    c = ~a;
    printf("~a = %d\n", c);
    
    // Bitwise Left Shift Operator
    c = a << 2;
    printf("a << 2 = %d\n", c);
    
    // Bitwise Right Shift Operator
    c = a >> 1;
    printf("a >> 1 = %d\n", c);
    
    // Bitwise AND Assign Operator
    a &= b;
    printf("a &= b, a = %d\n", a);
    
    // Bitwise OR Assign Operator
    a |= b;
    printf("a |= b, a = %d\n", a);
    
    // Bitwise XOR Assign Operator
    a ^= b;
    printf("a ^= b, a = %d\n", a);
    
    // Bitwise Complement Assign Operator
    a = 10;
    a = ~a;
    printf("~a, a = %d\n", a);
    
    // Bitwise Left Shift Assign Operator
    a = 10;
    a <<= 2;
    printf("a <<= 2, a = %d\n", a);
    
    // Bitwise Right Shift Assign Operator
    a = 10;
    a >>= 1;
    printf("a >>= 1, a = %d\n", a);
    
    return 0;
}