//FormAI DATASET v1.0 Category: Bitwise operations ; Style: surprised
#include <stdio.h>

int main()
{
    int x = 10, y = 7;
    
    printf("Initial values: x = %d, y = %d\n\n", x, y);
    
    // Bitwise AND
    printf("Bitwise AND of %d and %d = %d\n", x, y, x & y);
    
    // Bitwise OR
    printf("Bitwise OR of %d and %d = %d\n", x, y, x | y);
    
    // Bitwise XOR
    printf("Bitwise XOR of %d and %d = %d\n", x, y, x ^ y);
    
    // Bitwise NOT
    printf("Bitwise NOT of %d = %d\n\n", x, ~x);
    
    // Bitwise left shift
    printf("Bitwise left shift of %d by 2 = %d\n", y, y << 2);
    
    // Bitwise right shift
    printf("Bitwise right shift of %d by 2 = %d\n\n", y, y >> 2);
    
    // Surprise bitwise operation
    int a = 0b11001100;
    int b = 0b10101010;
    
    printf("a = %d (binary = %d%d%d%d%d%d%d%d)\n", a, (a >> 7) & 1, (a >> 6) & 1, (a >> 5) & 1, (a >> 4) & 1, (a >> 3) & 1, (a >> 2) & 1, (a >> 1) & 1, a & 1);
    printf("b = %d (binary = %d%d%d%d%d%d%d%d)\n", b, (b >> 7) & 1, (b >> 6) & 1, (b >> 5) & 1, (b >> 4) & 1, (b >> 3) & 1, (b >> 2) & 1, (b >> 1) & 1, b & 1);
    
    int c = (a & 0b11110000) | (b & 0b00001111);
    
    printf("\nc (surprise!) = %d (binary = %d%d%d%d%d%d%d%d)\n", c, (c >> 7) & 1, (c >> 6) & 1, (c >> 5) & 1, (c >> 4) & 1, (c >> 3) & 1, (c >> 2) & 1, (c >> 1) & 1, c & 1);
    
    return 0;
}