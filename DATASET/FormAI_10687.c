//FormAI DATASET v1.0 Category: Bitwise operations ; Style: sophisticated
#include <stdio.h>

int main() {

    unsigned int x = 10;
    unsigned int y = 20;
    
    printf("Bitwise AND operation result of %d & %d is %d.\n", x, y, x & y);
    printf("Bitwise OR operation result of %d | %d is %d.\n", x, y, x | y);
    printf("Bitwise XOR operation result of %d ^ %d is %d.\n", x, y, x ^ y);
    printf("Bitwise NOT operation result of ~%d is %d.\n", x, ~x);

    printf("Left shift operation of %d by 2 bit positions is %d.\n", x, x << 2);
    printf("Right shift operation of %d by 2 bit positions is %d.\n", y, y >> 2);
    
    // Clearing bit 0 and bit 1 of x
    x = x & (~3); 
    printf("After clearing bit 0 and bit 1 of %d, the result is %d.\n", 10, x);

    // Setting bit 3 of y
    y = y | (1 << 3); 
    printf("After setting bit 3 of %d, the result is %d.\n", 20, y); 
    
    // Toggling bit 2 of x
    x = x ^ (1 << 2);
    printf("After toggling bit 2 of %d, the result is %d.\n", 10, x); 
    
    return 0;

}