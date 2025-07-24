//FormAI DATASET v1.0 Category: Bitwise operations ; Style: all-encompassing
#include <stdio.h>

int main() {
    int a = 12; // binary 1100
    int b = 25; // binary 11001
    int c = 0;
    
    // Bitwise AND (&) Operator
    c = a & b; // binary 1000 => decimal 8
    printf("a & b = %d\n", c);
    
    // Bitwise OR (|) Operator
    c = a | b; // binary 1101 => decimal 13
    printf("a | b = %d\n", c);
    
    // Bitwise XOR (^) Operator
    c = a ^ b; // binary 1001 => decimal 9
    printf("a ^ b = %d\n", c);
    
    // Bitwise Ones Complement (~) Operator
    c = ~a; // binary 1111111111111111111111111111011 => decimal -13
    printf("~a = %d\n", c);
    
    // Bitwise Shift Left (<<) Operator
    c = a << 2; // binary 110000 => decimal 48
    printf("a << 2 = %d\n", c);
    
    // Bitwise Shift Right (>>) Operator
    c = b >> 3; // binary 11 => decimal 3
    printf("b >> 3 = %d\n", c);
    
    // Bitwise AND (&) Operator with Boolean Expression
    int x = 7; // binary 111
    int y = 5; // binary 101
    if ((x & y) == 5) {
        printf("x & y equals 5\n");
    }
    
    // Bitwise XOR (^) Operator with Boolean Expression
    int p = 11; // binary 1011
    int q = 8; // binary 1000
    if ((p ^ q) == 3) {
        printf("p ^ q equals 3\n");
    }
    
    return 0;
}