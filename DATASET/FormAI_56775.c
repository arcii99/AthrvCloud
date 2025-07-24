//FormAI DATASET v1.0 Category: Bitwise operations ; Style: complex
#include<stdio.h>
#include<stdlib.h>

//function to print binary representation of integer
void printBinary(int num){
    if(num>1)
        printBinary(num/2);
    printf("%d", num%2);
}

int main(){    
    int a = 12, b = 25, c = 0; //initialize variables

    //perform bitwise OR operation between a and b and store result in c
    c = a | b;

    printf("a = %d, ", a); 
    printf("in binary form = "); printBinary(a);
    printf("\nb = %d, ", b); 
    printf("in binary form = "); printBinary(b);
    printf("\nc = a | b = %d, ", c); 
    printf("in binary form = "); printBinary(c);

    //perform bitwise XOR operation between a and b and store result in c
    c = a ^ b;

    printf("\n\na = %d, ", a); 
    printf("in binary form = "); printBinary(a);
    printf("\nb = %d, ", b); 
    printf("in binary form = "); printBinary(b);
    printf("\nc = a ^ b = %d, ", c); 
    printf("in binary form = "); printBinary(c);

    //perform bitwise AND operation between a and b and store result in c
    c = a & b;

    printf("\n\na = %d, ", a); 
    printf("in binary form = "); printBinary(a);
    printf("\nb = %d, ", b); 
    printf("in binary form = "); printBinary(b);
    printf("\nc = a & b = %d, ", c); 
    printf("in binary form = "); printBinary(c);

    //perform bitwise NOT operation on a and store result in c
    c = ~a;

    printf("\n\na = %d, ", a); 
    printf("in binary form = "); printBinary(a);
    printf("\nc = ~a = %d, ", c); 
    printf("in binary form = "); printBinary(c);

    //left shift a by 2 bits and store result in c
    c = a << 2;

    printf("\n\na = %d, ", a); 
    printf("in binary form = "); printBinary(a);
    printf("\nc = a << 2 = %d, ", c); 
    printf("in binary form = "); printBinary(c);

    //right shift b by 2 bits and store result in c
    c = b >> 2;

    printf("\n\nb = %d, ", b); 
    printf("in binary form = "); printBinary(b);
    printf("\nc = b >> 2 = %d, ", c); 
    printf("in binary form = "); printBinary(c);

    return 0;
}