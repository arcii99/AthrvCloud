//FormAI DATASET v1.0 Category: Bitwise operations ; Style: ephemeral
#include <stdio.h>

int main() {
    // Welcome to my bitwise operations program!
    printf("Let's use bitwise operators to do some cool stuff!\n");
    
    // First, let's create some variables to work with
    int a = 27; // binary: 0001 1011
    int b = 15; // binary: 0000 1111
    int c;
    
    // Now, let's use the bitwise AND operator to compare each bit of a and b
    c = a & b; // binary: 0000 1011 = 11 in decimal
    printf("a AND b is %d\n", c);
    
    // Next up, the bitwise OR operator. This sets each bit to 1 if either bit is 1
    c = a | b; // binary: 0001 1111 = 31 in decimal
    printf("a OR b is %d\n", c);
    
    // The bitwise XOR operator is next. This sets each bit to 1 if only one of the bits is 1
    c = a ^ b; // binary: 0001 0100 = 20 in decimal
    printf("a XOR b is %d\n", c);
    
    // Now let's move onto the bitwise complement operator, which inverts all bits
    c = ~a; // binary: 1110 0100 = -28 in decimal (signed int)
    printf("The complement of a is %d\n", c);
    
    // The left shift operator is up next. This shifts all bits to the left by a specified number of positions
    c = a << 1; // binary (after shift): 0011 0110 = 54 in decimal
    printf("a shifted left by 1 is %d\n", c);
    
    // Finally, the right shift operator. This shifts all bits to the right by a specified number of positions
    c = a >> 1; // binary (after shift): 0000 1101 = 13 in decimal
    printf("a shifted right by 1 is %d\n", c);
    
    printf("Thanks for using my bitwise operations program!\n");
    return 0;
}