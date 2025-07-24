//FormAI DATASET v1.0 Category: Bitwise operations ; Style: shape shifting
#include<stdio.h>

// Shapeshifting program demonstrating bitwise operations in C

int main(){
    int a = 234; // decimal number
    int b = 55; // decimal number
    int c = 0xAA; // hexadecimal number
    int d = 0x55; // hexadecimal number
    int e = 0b10101010; // binary number
    int f = 0b01010101; // binary number
    
    // performing AND operation
    int result1 = a & b;
    int result2 = c & d;
    int result3 = e & f;
    
    // printing results in decimal, hexadecimal and binary format
    printf("AND operation results:\n");
    
    printf("%d & %d = %d\n", a, b, result1);
    printf("%X & %X = %X\n", c, d, result2);
    printf("%d & %d = %d\n\n", e, f, result3);
    
    // performing OR operation
    int result4 = a | b;
    int result5 = c | d;
    int result6 = e | f;
    
    // printing results in decimal, hexadecimal and binary format
    printf("OR operation results:\n");
    
    printf("%d | %d = %d\n", a, b, result4);
    printf("%X | %X = %X\n", c, d, result5);
    printf("%d | %d = %d\n\n", e, f, result6);
    
    // performing XOR operation
    int result7 = a ^ b;
    int result8 = c ^ d;
    int result9 = e ^ f;
    
    // printing results in decimal, hexadecimal and binary format
    printf("XOR operation results:\n");
    
    printf("%d ^ %d = %d\n", a, b, result7);
    printf("%X ^ %X = %X\n", c, d, result8);
    printf("%d ^ %d = %d\n\n", e, f, result9);
    
    // performing left shift operation
    int result10 = a << 2;
    int result11 = c << 3;
    int result12 = e << 4;
    
    // printing results in decimal, hexadecimal and binary format
    printf("Left shift operation results:\n");
    
    printf("%d << 2 = %d\n", a, result10);
    printf("%X << 3 = %X\n", c, result11);
    printf("%d << 4 = %d\n\n", e, result12);
    
    // performing right shift operation
    int result13 = a >> 2;
    int result14 = c >> 3;
    int result15 = e >> 4;
    
    // printing results in decimal, hexadecimal and binary format
    printf("Right shift operation results:\n");
    
    printf("%d >> 2 = %d\n", a, result13);
    printf("%X >> 3 = %X\n", c, result14);
    printf("%d >> 4 = %d\n\n", e, result15);
    
    return 0; // shape shifting complete
}