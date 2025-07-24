//FormAI DATASET v1.0 Category: Bitwise operations ; Style: surprised
#include <stdio.h>

int main() {
    int a = 7, b = 6, result;
    printf("Initial values: a = %d, b = %d\n", a, b);
    
    // Bitwise AND
    result = a & b;
    printf("Bitwise AND: %d & %d = %d\n", a, b, result);
    
    // Bitwise OR
    result = a | b;
    printf("Bitwise OR: %d | %d = %d\n", a, b, result);
    
    // Bitwise XOR
    result = a ^ b;
    printf("Bitwise XOR: %d ^ %d = %d\n", a, b, result);
    
    // Bitwise NOT
    result = ~a;
    printf("Bitwise NOT: ~%d = %d\n", a, result);
    
    // Bitwise left shift
    result = a << 2;
    printf("Bitwise Left Shift: %d << 2 = %d\n", a, result);
    
    // Bitwise right shift
    result = b >> 2;
    printf("Bitwise Right Shift: %d >> 2 = %d\n", b, result);

    printf("Wow, those are a lot of bitwise operations!\n");

    // Let's combine some operations
    a = 0b00001111;   // binary value of 15
    b = 0b10101010;   // binary value of 170
    result = (a | b) & ~(a & b);
    printf("Combining bitwise operations: (%d | %d) & ~(%d & %d) = %d\n", a, b, a, b, result);

    printf("This is just the tip of the iceberg when it comes to C bitwise operations!\n");
    
    return 0;
}