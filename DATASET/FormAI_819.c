//FormAI DATASET v1.0 Category: Bitwise operations ; Style: relaxed
#include <stdio.h>

int main()
{
    int x = 10;
    int y = 3;
    int z;
    
    // Bitwise AND
    z = x & y;
    printf("The result of x & y is %d\n", z);
    
    // Bitwise OR
    z = x | y;
    printf("The result of x | y is %d\n", z);
    
    // Bitwise XOR
    z = x ^ y;
    printf("The result of x ^ y is %d\n", z);
    
    // Bitwise NOT
    z = ~x;
    printf("The result of ~x is %d\n", z);
    
    // Left shift
    z = x << 2;
    printf("The result of x << 2 is %d\n", z);
    
    // Right shift
    z = x >> 2;
    printf("The result of x >> 2 is %d\n", z);
    
    // Complement operator
    z = !x;
    printf("The result of !x is %d\n", z);
    
    return 0;
}