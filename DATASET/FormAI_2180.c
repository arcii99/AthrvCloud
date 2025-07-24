//FormAI DATASET v1.0 Category: Bitwise operations ; Style: satisfied
#include <stdio.h>

int main() {
    int a = 5; // binary 101
    int b = 3; // binary 011
    int c;

    // bitwise AND
    c = a & b; // binary result is 001 -> decimal 1;
    printf("Bitwise AND of %d and %d is: %d\n", a, b, c);
    
    // bitwise OR
    c = a | b; // binary result is 111 -> decimal 7;
    printf("Bitwise OR of %d and %d is: %d\n", a, b, c);
    
    // bitwise XOR
    c = a ^ b; // binary result is 110 -> decimal 6;
    printf("Bitwise XOR of %d and %d is: %d\n", a, b, c);
    
    // bitwise NOT
    c = ~a; // binary result is 11111111111111111111111111111010 -> decimal -6;
    printf("Bitwise NOT of %d is: %d\n", a, c);
    
    // left shift
    c = a << 2; // binary result is 10100 -> decimal 20;
    printf("Left shift of %d by 2 is: %d\n", a, c);
    
    // right shift
    c = a >> 1; // binary result is 10 -> decimal 2;
    printf("Right shift of %d by 1 is: %d\n", a, c);

    return 0;
}