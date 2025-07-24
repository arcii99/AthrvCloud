//FormAI DATASET v1.0 Category: Bitwise operations ; Style: ultraprecise
#include <stdio.h> 

int main() 
{ 
    unsigned int x = 100, y = 50; 

    // Bitwise AND 
    printf("x & y = %d\n", x & y); 

    // Bitwise OR 
    printf("x | y = %d\n", x | y); 

    // Bitwise XOR 
    printf("x ^ y = %d\n", x ^ y); 

    // Bitwise NOT 
    printf("~x = %d\n", ~x); 

    // Left Shift 
    printf("x << 1 = %d\n", x << 1); 

    // Right Shift 
    printf("x >> 1 = %d\n", x >> 1); 

    // Logical AND 
    if (x & y) 
        printf("Both x and y are TRUE.\n"); 
    else
        printf("Either x or y is FALSE.\n"); 

    // Logical OR 
    if (x || y) 
        printf("At least one of x and y is TRUE.\n"); 
    else
        printf("Neither x nor y is TRUE.\n"); 

    // Bitwise AND assignment operator 
    x &= y; 
    printf("x = %d, y = %d\n", x, y); 

    // Bitwise OR assignment operator 
    x |= y; 
    printf("x = %d, y = %d\n", x, y); 

    // Bitwise XOR assignment operator 
    x ^= y; 
    printf("x = %d, y = %d\n", x, y);

    return 0; 
}