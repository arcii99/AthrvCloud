//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Linus Torvalds
/* Linus Torvalds style bit manipulation program */
#include <stdio.h>

/* define some bit manipulation macros for readability */
#define SET_BIT(n, pos) ((n) |= (1 << (pos)))
#define CLEAR_BIT(n, pos) ((n) &= ~(1 << (pos)))
#define TOGGLE_BIT(n, pos) ((n) ^= (1 << (pos)))
#define GET_BIT(n, pos) ((n >> pos) & 1)

int main() {
    int num = 42; /* decimal representation of the number 101010 */
    
    printf("The original number is: %d\n", num);
    
    /* Setting bit 3 of the number */
    SET_BIT(num, 3);
    printf("After setting bit 3, the number is: %d\n", num);
    
    /* Clearing bit 5 of the number */
    CLEAR_BIT(num, 5);
    printf("After clearing bit 5, the number is: %d\n", num);
    
    /* Toggling bit 2 of the number */
    TOGGLE_BIT(num, 2);
    printf("After toggling bit 2, the number is: %d\n", num);
    
    /* Getting bit 6 of the number */
    printf("Bit 6 of the number is: %d\n", GET_BIT(num, 6));
    
    int newNum = num & (num - 1); /* Clearing the least significant bit */
    printf("After clearing the least significant bit, the number is: %d\n", newNum);
    
    int rotatedNum = (num >> 3) | (num << (sizeof(int)*8 - 3)); /* Rotating the number by 3 bits */
    printf("After rotating the number by 3 bits, the number is: %d\n", rotatedNum);
    
    return 0;
}