//FormAI DATASET v1.0 Category: Bitwise operations ; Style: mathematical
#include <stdio.h>

int main() {
    int x = 18;   // Binary: 0001 0010
    int y = 10;   // Binary: 0000 1010
    
    // Left-shift operation
    int leftShiftResult = x << 2;  // Binary: 0100 1000 (Decimal: 72)
    printf("Result of left-shift operation on x (%d): %d\n", x, leftShiftResult);
    
    // Right-shift operation
    int rightShiftResult = y >> 1;  // Binary: 0000 0101 (Decimal: 5)
    printf("Result of right-shift operation on y (%d): %d\n", y, rightShiftResult);
    
    // Bitwise AND operation
    int andResult = x & y;  // Binary: 0000 0010 (Decimal: 2)
    printf("Result of bitwise AND operation on x (%d) and y (%d): %d\n", x, y, andResult);
    
    // Bitwise OR operation
    int orResult = x | y;  // Binary: 0001 1010 (Decimal: 26)
    printf("Result of bitwise OR operation on x (%d) and y (%d): %d\n", x, y, orResult);
    
    // Bitwise XOR operation
    int xorResult = x ^ y;  // Binary: 0001 1000 (Decimal: 24)
    printf("Result of bitwise XOR operation on x (%d) and y (%d): %d\n", x, y, xorResult);
    
    // Ones' complement operation
    int onesComplementResult = ~x;  // Binary: 1110 1101 (Decimal: -19)
    printf("Result of ones' complement operation on x (%d): %d\n", x, onesComplementResult);
    
    return 0;
}