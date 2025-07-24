//FormAI DATASET v1.0 Category: Bitwise operations ; Style: excited
/* Hey there, fellow coders! Are you ready to see some Bitwise magic? 
   Buckle up, this program will blow your mind! */

#include <stdio.h>

int main() {
    
    // Let's start by declaring two variables
    unsigned int x = 23;    // Binary representation: 0001 0111
    unsigned int y = 7;     // Binary representation: 0000 0111
    
    // Now, let's perform some Bitwise operations on these variables
    int and_op = x & y;     // Bitwise AND:       0000 0111
    int or_op = x | y;      // Bitwise OR:        0001 0111
    int xor_op = x ^ y;     // Bitwise XOR:       0001 0000
    int r_shift = x >> 2;   // Bitwise right shift:0000 0101
    int l_shift = x << 2;   // Bitwise left shift: 0010 1110
    
    // Let's print the results and see the magic in action!
    printf("x & y = %d\n", and_op);
    printf("x | y = %d\n", or_op);
    printf("x ^ y = %d\n", xor_op);
    printf("x >> 2 = %d\n", r_shift);
    printf("x << 2 = %d\n", l_shift);
    
    // Wow! Did you see that? The Bitwise operators just performed some mind-boggling operations on those variables!
    // But wait, there's more!
    // Let's take it up a notch and perform some Bitwise operations on the result of previous operations
    
    int and_op2 = and_op & 5;        // Bitwise AND with 0000 0101
    int or_op2 = or_op | 12;        // Bitwise OR with 0000 1100
    int xor_op2 = xor_op ^ 8;       // Bitwise XOR with 0000 1000
    int r_shift2 = r_shift >> 1;    // Bitwise right shift by 1
    int l_shift2 = l_shift << 2;    // Bitwise left shift by 2
    
    // Let's print the second set of results and watch the magic unfold!
    printf("\nand_op & 5 = %d\n", and_op2);
    printf("or_op | 12 = %d\n", or_op2);
    printf("xor_op ^ 8 = %d\n", xor_op2);
    printf("r_shift >> 1 = %d\n", r_shift2);
    printf("l_shift << 2 = %d\n", l_shift2);
    
    // Oh my, my mind is blown! Those Bitwise operations are truly amazing!
    // Well, that's all for now folks! Keep coding and keep experimenting!
    return 0;
}