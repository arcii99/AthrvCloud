//FormAI DATASET v1.0 Category: Bitwise operations ; Style: scalable
#include<stdio.h>

int main(){

    int a = 15;
    int b = 20;
    int c = 0;

    //Bitwise AND operation
    c = a & b;
    printf("a & b = %d\n", c);

    //Bitwise OR operation
    c = a | b;
    printf("a | b = %d\n", c);

    //Bitwise XOR operation
    c = a ^ b;
    printf("a ^ b = %d\n", c);

    //Bitwise NOT operation
    c = ~a;
    printf("~a = %d\n", c);

    //Bitwise left shift operation
    c = a << 2;
    printf("a << 2 = %d\n", c);

    //Bitwise right shift operation
    c = b >> 2;
    printf("b >> 2 = %d\n", c);

    return 0;
}