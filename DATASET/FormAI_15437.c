//FormAI DATASET v1.0 Category: Bitwise operations ; Style: enthusiastic
#include <stdio.h>

int main() {
    printf("Let's do some bitwise operations!\n");
    
    // Using binary operators to check if a number is odd or even
    int num = 7;
    if (num & 1) {
        printf("%d is odd\n", num);
    } else {
        printf("%d is even\n", num);
    }
    
    // Shifting bits to multiply or divide by powers of 2
    int x = 5;
    int y = x << 2; // Multiply by 4
    printf("5 * 4 = %d\n", y);
    
    int z = y >> 1; // Divide by 2
    printf("%d / 2 = %d\n", y, z);
    
    // Rotating bits to the left or right
    unsigned int a = 0xdeadbeef;
    unsigned int b = (a << 8) | (a >> (32 - 8)); // Rotate 8 bits to the left
    printf("0x%x rotated by 8 bits to the left is 0x%x\n", a, b);
    
    unsigned int c = (b >> 4) | (b << (32 - 4)); // Rotate 4 bits to the right
    printf("0x%x rotated by 4 bits to the right is 0x%x\n", b, c);
    
    // Using bitwise operators to set and clear bits
    unsigned int flags = 0b00000000;
    flags |= (1 << 0); // Set the first flag
    flags |= (1 << 2); // Set the third flag
    printf("Flags are 0b%d%d%d%d\n", 
           (flags >> 3) & 1, 
           (flags >> 2) & 1, 
           (flags >> 1) & 1, 
           flags & 1);
           
    flags &= ~(1 << 0); // Clear the first flag
    printf("Flags after clearing first flag are 0b%d%d%d%d\n", 
           (flags >> 3) & 1, 
           (flags >> 2) & 1, 
           (flags >> 1) & 1, 
           flags & 1);
           
    printf("Wow, bitwise operations are so cool!\n");
    return 0;
}