//FormAI DATASET v1.0 Category: Bitwise operations ; Style: optimized
#include <stdio.h>

int main() {
    int x = 10, y = 20;
    printf("Before swapping: x = %d, y = %d\n", x, y);
    
    //performing swap operation using XOR bitwise operator
    x ^= y;
    y ^= x;
    x ^= y;
    
    printf("After swapping: x = %d, y = %d\n", x, y);
    
    //performing bitwise AND operations
    int a = 10, b = 20, c = 30;
    int result = a & b;
    printf("a & b = %d\n", result);
    
    result = b & c;
    printf("b & c = %d\n", result);
    
    //performing bitwise OR operations
    result = a | b;
    printf("a | b = %d\n", result);
    
    result = b | c;
    printf("b | c = %d\n", result);
    
    //performing bitwise XOR operations
    result = a ^ b;
    printf("a ^ b = %d\n", result);
    
    result = b ^ c;
    printf("b ^ c = %d\n", result);
    
    //performing left shift operation
    int num = 7; //binary representation 00000111
    printf("Before left shift: num = %d\n", num);
    num = num << 2; //binary representation 00011100
    printf("After left shift: num = %d\n", num);
    
    //performing right shift operation
    num = 28; //binary representation 00011100
    printf("Before right shift: num = %d\n", num);
    num = num >> 2; //binary representation 00000111
    printf("After right shift: num = %d\n", num);
    
    return 0;
}