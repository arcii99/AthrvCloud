//FormAI DATASET v1.0 Category: Bitwise operations ; Style: unmistakable
#include<stdio.h>

int main(){
    int a=17, b=23, c;
    printf("Initial values: a = %d, b = %d\n", a, b);
    
    // Bitwise AND (&)
    c = a & b;
    printf("a & b = %d\n", c);
    
    // Bitwise OR (|)
    c = a | b;
    printf("a | b = %d\n", c);
    
    // Bitwise XOR (^)
    c = a ^ b;
    printf("a ^ b = %d\n", c);
    
    // Bitwise NOT (~)
    c = ~a;
    printf("~a = %d\n", c);
    
    // Left shift (<<)
    c = a << 2;
    printf("a << 2 = %d\n", c);
    
    // Right shift (>>)
    c = b >> 3;
    printf("b >> 3 = %d\n", c);
    
    return 0;
}