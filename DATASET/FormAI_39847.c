//FormAI DATASET v1.0 Category: Bitwise operations ; Style: introspective
/* This program demonstrates the usage and understanding of the Bitwise Operators in C */
#include<stdio.h>

int main(){

    int a = 3; // 011
    int b = 5; // 101
    
    printf("The value of a is %d\n", a);
    printf("The value of b is %d\n", b);

    int and_result = a & b;
    // Performing Bitwise And Operation of a and b
    // a & b == 001
    printf("Bitwise AND Result: %d\n", and_result);

    int or_result = a | b;
    // Performing Bitwise OR Operation of a and b
    // a | b == 111
    printf("Bitwise OR Result: %d\n", or_result);

    int xor_result = a ^ b;
    // Performing Bitwise XOR Operation of a and b
    // a ^ b == 110
    printf("Bitwise XOR Result: %d\n", xor_result);

    // Performing Bitwise Unary Complement (~) of a
    // ~a == 100
    printf("Bitwise Unary Complement of a: %d\n", ~a);

    // Performing Bitwise Unary Complement (~) of b
    // ~b == 010
    printf("Bitwise Unary Complement of b: %d\n", ~b);

    // Performing Left Shift << by 1 bit of a
    // a << 1 == 110
    printf("Left Shift of a by 1 bit: %d\n", a << 1);

    // Performing Right Shift >> by 1 bit of b
    // b >> 1 == 010
    printf("Right Shift of b by 1 bit: %d\n", b >> 1);

    // Performing Left Shift << by 2 bits of a
    // a << 2 == 1100
    printf("Left Shift of a by 2 bits: %d\n", a << 2);

    // Performing Right Shift >> by 2 bits of b
    // b >> 2 == 001
    printf("Right Shift of b by 2 bits: %d\n", b >> 2);

    return 0;
}