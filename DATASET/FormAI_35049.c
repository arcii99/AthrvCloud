//FormAI DATASET v1.0 Category: Bitwise operations ; Style: shocked
#include<stdio.h>

int main(){
    int a = 7, b = 18;
    printf("Initial values of a: %d and b: %d\n", a, b);

    // Bitwise OR operator example
    int c = a | b;
    printf("The result of Bitwise OR operator on a and b is : %d\n", c);

    // Bitwise AND operator example
    c = a & b;
    printf("The result of Bitwise AND operator on a and b is : %d\n", c);

    // Bitwise XOR operator example
    c = a ^ b;
    printf("The result of Bitwise XOR operator on a and b is : %d\n", c);

    // Bitwise complement operator example
    c = ~a;
    printf("The result of Bitwise complement operator on a is : %d\n", c);

    // Left shift operator example
    c = a << 2;
    printf("The result of Left shift operator on a by 2 is : %d\n", c);

    // Right shift operator example
    c = b >> 2;
    printf("The result of Right shift operator on b by 2 is : %d\n", c);

    // Bitwise AND assignment operator example
    a &= b;
    printf("The value of a after Bitwise AND assignment with b is : %d\n", a);

    // Bitwise OR assignment operator example
    a |= b;
    printf("The value of a after Bitwise OR assignment with b is : %d\n", a);

    // Bitwise XOR assignment operator example
    a ^= b;
    printf("The value of a after Bitwise XOR assignment with b is : %d\n", a);

    // Left shift assignment operator example
    a <<= 2;
    printf("The value of a after Left shift assignment by 2 is : %d\n", a);

    // Right shift assignment operator example
    b >>= 2;
    printf("The value of b after Right shift assignment by 2 is : %d\n", b);

    return 0;
}