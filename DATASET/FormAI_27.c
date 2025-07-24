//FormAI DATASET v1.0 Category: Bitwise operations ; Style: relaxed
#include <stdio.h>

/*This program is meant to demonstrate the use of bitwise operations in C.*/

int main(){
    int a = 12; //1100 in binary
    int b = 7; //0111 in binary
    
    //Bitwise AND
    int c = a & b; //0100 in binary
    printf("Result of bitwise AND between %d and %d is: %d\n", a, b, c);
    
    //Bitwise OR
    int d = a | b; //1111 in binary
    printf("Result of bitwise OR between %d and %d is: %d\n", a, b, d);
    
    //Bitwise XOR
    int e = a ^ b; //1011 in binary
    printf("Result of bitwise XOR between %d and %d is: %d\n", a, b, e);
    
    //Bitwise NOT
    int f = ~a; //0011 in binary
    printf("Result of bitwise NOT of %d is: %d\n", a, f);
    
    //Bitwise left shift
    int g = a << 2; //110000 in binary
    printf("Result of bitwise left shift of %d by 2 is: %d\n", a, g);
    
    //Bitwise right shift
    int h = a >> 2; //000011 in binary
    printf("Result of bitwise right shift of %d by 2 is: %d\n", a, h);
    
    return 0;
}