//FormAI DATASET v1.0 Category: Bitwise operations ; Style: cheerful
#include <stdio.h>

int main() {

    printf("Let's play with some C bitwise!\n");

    int a = 5; //  binary representation of 5 is 0101
    int b = 7; //  binary representation of 7 is 0111
    
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    int or_operation = a | b; // binary OR operation
    printf("a | b = %d\n", or_operation); // The output is 0111 (equals to decimal 7)

    int xor_operation = a ^ b; // binary XOR operation
    printf("a ^ b = %d\n", xor_operation); // The output is 0010 (equals to decimal 2)

    int and_operation = a & b; // binary AND operation
    printf("a & b = %d\n", and_operation); // The output 0101 (equals to decimal 5)

    int shift_left = a << 2; // binary left shift by two bits
    printf("a << 2 = %d\n", shift_left); // The output is 10100, which is 20 in decimal.

    int shift_right = b >> 1; // binary right shift by one bit
    printf("b >> 1 = %d\n", shift_right); // The output is 011, which is 3 in decimal.

    int complement = ~a; // binary complement
    printf("~a = %d\n", complement); // The output is 111...1010, which is -6 in decimal.

    return 0;
}