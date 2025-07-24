//FormAI DATASET v1.0 Category: Bitwise operations ; Style: configurable
#include <stdio.h>

#define BITS 8 // number of bits to use in the operation

void printBits(unsigned int num) {
    for(int i = BITS - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1); // shift num by i bits and check if it's a 1 or 0
        if(i % 4 == 0) {
            printf(" "); // add space every 4 bits for readability
        }
    }
    printf("\n");
}

int main() {
    unsigned int num1 = 110; // binary: 01101110
    unsigned int num2 = 47;  // binary: 00101111
    
    // Bitwise AND
    printf("Bitwise AND: num1 & num2 = ");
    printBits(num1 & num2); // binary: 00101110
    
    // Bitwise OR
    printf("Bitwise OR: num1 | num2 = ");
    printBits(num1 | num2); // binary: 01101111
    
    // Bitwise XOR
    printf("Bitwise XOR: num1 ^ num2 = ");
    printBits(num1 ^ num2); // binary: 01000001
    
    // Bitwise NOT
    printf("Bitwise NOT: ~num1 = ");
    printBits(~num1); // binary: 10010001
    
    // Bitwise LEFT SHIFT
    int shiftBy = 3;
    printf("Bitwise Left Shift: num1 << %d = ", shiftBy);
    printBits(num1 << shiftBy); // binary: 01110000
    
    // Bitwise RIGHT SHIFT (unsigned)
    printf("Bitwise Right Shift (unsigned): num1 >> %d = ", shiftBy);
    printBits(num1 >> shiftBy); // binary: 00001101
    
    // Bitwise RIGHT SHIFT (signed)
    int negativeNum1 = -110; // binary: 10010010
    printf("Bitwise Right Shift (signed): negativeNum1 >> %d = ", shiftBy);
    printBits(negativeNum1 >> shiftBy); // binary: 11110010
    
    return 0;
}