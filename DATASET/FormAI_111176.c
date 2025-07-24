//FormAI DATASET v1.0 Category: Bitwise operations ; Style: excited
#include<stdio.h>

int main(){
    int a = 10;
    int b = 5;
    printf("Let's do some bitwise magic!\n");
    printf("Initial value of a = %d and b = %d\n", a, b);

    // Bitwise AND operator
    int c = a & b;
    printf("Value after AND operation on a and b = %d\n", c);

    // Bitwise OR operator
    c = a | b;
    printf("Value after OR operation on a and b = %d\n", c);

    // Bitwise XOR operator
    c = a ^ b;
    printf("Value after XOR operation on a and b = %d\n", c);

    // Bitwise NOT operator
    c = ~a;
    printf("Value after NOT operation on a = %d\n", c);

    // Bitwise left shift operator
    c = a << 2;
    printf("Value after left shift operation on a = %d\n", c);

    // Bitwise right shift operator
    c = a >> 2;
    printf("Value after right shift operation on a = %d\n", c);

    printf("Isn't it amazing how we can manipulate bits and control the universe?!\n");

    return 0;
}