//FormAI DATASET v1.0 Category: Bitwise operations ; Style: mathematical
#include <stdio.h>

int main() {
    // Example of bitwise operations in a mathematical-style program
    
    int a = 11;
    int b = 6;
    int result;
    
    // And Operation
    result = a & b;
    printf("%d AND %d gives %d\n", a, b, result);
    
    // Or Operation
    result = a | b;
    printf("%d OR %d gives %d\n", a, b, result);
    
    // Xor Operation
    result = a ^ b;
    printf("%d XOR %d gives %d\n", a, b, result);
    
    // Complement Operation
    result = ~a;
    printf("The complement of %d is %d\n", a, result);
    
    // Left Shift Operation
    result = a << 3;
    printf("%d shifted left by 3 gives %d\n", a, result);
    
    // Right Shift Operation
    result = a >> 2;
    printf("%d shifted right by 2 gives %d\n", a, result);
    
    return 0;
}