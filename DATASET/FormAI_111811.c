//FormAI DATASET v1.0 Category: Bitwise operations ; Style: puzzling
#include <stdio.h>

int main() {

    int a = 163; //10100011
    int b = 71;  //01000111
    
    int xored = a ^ b; //xor operation
    int inverted = ~xored; //bitwise NOT operation

    int and1 = ~a & b; //bitwise AND and NOT operations
    int and2 = a & ~b;

    int or1 = a | b; //bitwise OR operation
    int or2 = a | xored;

    int leftshift = a << 2; //left shift operation
    int rightshift = b >> 3; //right shift operation

    printf("The result of a XOR b is %d\n", xored);
    printf("The result of the bitwise NOT of the XOR of a and b is %d\n", inverted);
    printf("The result of the bitwise AND NOT operation between ~a and b is %d\n", and1);
    printf("The result of the bitwise AND NOT operation between a and ~b is %d\n", and2);
    printf("The result of the bitwise OR operation between a and b is %d\n", or1);
    printf("The result of the bitwise OR operation between a and the XOR of a and b is %d\n", or2);
    printf("The result of a left shift by 2 positions is %d\n", leftshift);
    printf("The result of b right shift by 3 positions is %d\n", rightshift);

    return 0;
}