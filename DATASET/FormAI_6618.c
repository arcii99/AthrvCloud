//FormAI DATASET v1.0 Category: Bitwise operations ; Style: synchronous
#include <stdio.h>

// Function to print a 32-bit binary number
void printBinary(int num) {
    for(int i=31; i>=0; i--)
        printf("%d", (num>>i)&1);
    printf("\n");
}

int main() {
    // Bitwise AND operation
    int a = 28, b = 39;
    int c = a & b;
    printf("Bitwise AND of %d and %d is %d\n", a, b, c);
    printBinary(a);
    printBinary(b);
    printBinary(c);
    
    // Bitwise OR operation
    a = 12, b = 7;
    c = a | b;
    printf("Bitwise OR of %d and %d is %d\n", a, b, c);
    printBinary(a);
    printBinary(b);
    printBinary(c);
    
    // Bitwise XOR operation
    a = 24, b = 13;
    c = a ^ b;
    printf("Bitwise XOR of %d and %d is %d\n", a, b, c);
    printBinary(a);
    printBinary(b);
    printBinary(c);
    
    // Bitwise NOT operation
    a = 255;
    c = ~a;
    printf("Bitwise NOT of %d is %d\n", a, c);
    printBinary(a);
    printBinary(c);
    
    // Bitwise left shift operation
    a = 9;
    c = a << 3;
    printf("%d left shifted by 3 is %d\n", a, c);
    printBinary(a);
    printBinary(c);
    
    // Bitwise right shift operation
    a = 37;
    c = a >> 2;
    printf("%d right shifted by 2 is %d\n", a, c);
    printBinary(a);
    printBinary(c);
    
    return 0;
}