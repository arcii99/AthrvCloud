//FormAI DATASET v1.0 Category: Bitwise operations ; Style: synchronous
#include<stdio.h>
#include<stdint.h>

void binary(uint8_t x) //Function to convert decimal to binary
{
    if (x/2)
        binary(x/2);
    putchar(x%2 + '0');
}

int main()
{
    uint8_t a = 23, b = 56, c = 0;
    uint8_t d = ~a; //Bitwise NOT operation on a
    
    uint8_t e = a & b; //Bitwise AND operation between a and b
    uint8_t f = a | b; //Bitwise OR operation between a and b
    uint8_t g = a ^ b; //Bitwise XOR operation between a and b
    
    c = b << 2; //Left shift b by 2 bits
    
    printf("a = %d\n", a);
    printf("NOT a = %d (Binary of a : ", d);
    binary(d);
    printf(")\n");
    printf("b = %d\n", b);
    printf("a AND b = %d (Binary of result : ", e);
    binary(e);
    printf(")\n");
    printf("a OR b = %d (Binary of result : ", f);
    binary(f);
    printf(")\n");
    printf("a XOR b = %d (Binary of result : ", g);
    binary(g);
    printf(")\n");
    printf("Binary of b before left shift by 2 bits : ");
    binary(b);
    printf("\n");
    printf("b left shifted by 2 bits : %d (Binary of result : ", c);
    binary(c);
    printf(")\n");

    return 0;
}