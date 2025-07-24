//FormAI DATASET v1.0 Category: Bitwise operations ; Style: brave
#include<stdio.h>
#include<stdlib.h>

int main(){

    int x = 10, y = 5;
    printf("Original values of x and y: x=%d, y=%d\n\n", x, y);
    
    //Bitwise AND operator
    int result = x & y;
    printf("Bitwise AND operation (x & y): %d & %d = %d\n\n", x, y, result);
    
    //Bitwise OR operator
    result = x | y;
    printf("Bitwise OR operation (x | y): %d | %d = %d\n\n", x, y, result);
    
    //Bitwise XOR operator
    result = x ^ y;
    printf("Bitwise XOR operation (x ^ y): %d ^ %d = %d\n\n", x, y, result);
   
    //Bitwise right shift operator
    result = x >> 2;     //shift right by 2 bits
    printf("Bitwise right shift operation (x >> 2): %d >> 2 = %d\n\n", x, result);
    
    //Bitwise left shift operator
    result = y << 2;     //shift left by 2 bits
    printf("Bitwise left shift operation (y << 2): %d << 2 = %d\n\n", y, result);
    
    //Bitwise NOT operator
    result = ~x;         //complement of x
    printf("Bitwise NOT operation (~x): ~%d = %d\n\n", x, result);
    
    //Bitwise AND assignment operator
    x &= y;
    printf("Bitwise AND assignment operation (x &= y): x &= %d = %d\n\n", y, x);
    
    //Bitwise OR assignment operator
    x |= y;
    printf("Bitwise OR assignment operation (x |= y): x |= %d = %d\n\n", y, x);
    
    //Bitwise XOR assignment operator
    x ^= y;
    printf("Bitwise XOR assignment operation (x ^= y): x ^= %d = %d\n\n", y, x);
   
    //Bitwise right shift assignment operator
    x >>= 2;     //shift right by 2 bits
    printf("Bitwise right shift assignment operation (x >>= 2): x >>= 2 = %d\n\n", x);
    
    //Bitwise left shift assignment operator
    y <<= 2;     //shift left by 2 bits
    printf("Bitwise left shift assignment operation (y <<= 2): y <<= 2 = %d\n\n", y);
    
    return 0;
}