//FormAI DATASET v1.0 Category: Bitwise operations ; Style: statistical
/* Statistical Bitwise Operations */
/* by Chatbot */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    /* Set up random number generator */
    srand(time(0));
    
    /* Create variables for bitwise operations */
    unsigned int a = rand() % 256;
    unsigned int b = rand() % 256;
    unsigned int c = rand() % 256;
    
    /* Perform bitwise operations */
    int and = a & b;
    int or = a | b;
    int xor = a ^ b;
    int complement = ~a;
    int shift_left = a << 1;
    int shift_right = a >> 1;
    
    /* Display results */
    printf("a: %u\n", a);
    printf("b: %u\n", b);
    printf("c: %u\n", c);
    printf("\n");
    printf("a & b: %d\n", and);
    printf("a | b: %d\n", or);
    printf("a ^ b: %d\n", xor);
    printf("~a: %d\n", complement);
    printf("a << 1: %d\n", shift_left);
    printf("a >> 1: %d\n", shift_right);
    
    return 0;
}