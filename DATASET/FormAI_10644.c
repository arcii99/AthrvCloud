//FormAI DATASET v1.0 Category: Bitwise operations ; Style: ultraprecise
#include<stdio.h>

int main()
{
    int x = 3; //011 in binary
    int y = 6; //110 in binary

    int and_result = x & y; //010
    int or_result = x | y; //111
    int xor_result = x ^ y; //101
    int lshift_result = x << 2; //1100
    int rshift_result = y >> 1; //011

    printf("x & y = %d\n", and_result);
    printf("x | y = %d\n", or_result);
    printf("x ^ y = %d\n", xor_result);
    printf("x << 2 = %d\n", lshift_result);
    printf("y >> 1 = %d\n", rshift_result);

    int not_x = ~x; //~011 = 100
    int not_y = ~y; //~110 = 001

    printf("~x = %d\n", not_x);
    printf("~y = %d\n", not_y);

    //using bitwise operations to swap two numbers
    int a = 10;
    int b = 20;

    printf("Before swapping: a = %d, b = %d\n", a, b);

    a = a ^ b; //a = 10 ^ 20 = 30
    b = a ^ b; //b = 30 ^ 20 = 10
    a = a ^ b; //a = 30 ^ 10 = 20

    printf("After swapping: a = %d, b = %d\n", a, b);

    return 0;
}