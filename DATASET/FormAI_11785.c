//FormAI DATASET v1.0 Category: Bitwise operations ; Style: relaxed
#include <stdio.h>

// A function to convert a decimal number to binary
void decimalToBinary(int n) {
    int binaryNumber[32];
    int i = 0;
    while (n > 0) {
        binaryNumber[i] = n % 2;
        n = n / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--)
        printf("%d", binaryNumber[j]);
}

int main() {
    int a = 5; // decimal representation of 0101
    int b = 9; // decimal representation of 1001
    
    printf("a = %d\n", a);
    printf("b = %d\n", b);
    printf("\n");

    // Bitwise AND
    printf("a & b = "); 
    decimalToBinary(a & b); // prints 0001 (1 in decimal)
    printf("\n");

    // Bitwise OR
    printf("a | b = ");
    decimalToBinary(a | b); // prints 1101 (13 in decimal)
    printf("\n");

    // Bitwise XOR
    printf("a ^ b = ");
    decimalToBinary(a ^ b); // prints 1100 (12 in decimal)
    printf("\n");

    // Bitwise NOT
    printf("~a = ");
    decimalToBinary(~a); // prints 11111111111111111111111111111010 (-6 in decimal)
    printf("\n");

    // Bitwise LEFT SHIFT
    printf("a << 2 = ");
    decimalToBinary(a << 2); // prints 010100 (20 in decimal)
    printf("\n");

    // Bitwise RIGHT SHIFT
    printf("b >> 2 = ");
    decimalToBinary(b >> 2); // prints 0010 (2 in decimal)
    printf("\n");

    return 0;
}