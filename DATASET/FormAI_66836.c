//FormAI DATASET v1.0 Category: Bitwise operations ; Style: imaginative
// Imagine a world in which robots dominate the earth
// They communicate with each other using a series of 1s and 0s
// They've created a Bitwise Operations program to communicate more efficiently
// Here's an example of their code:

#include <stdio.h>

int main() {
    int robot1 = 0b01010101; // equivalent to decimal 85
    int robot2 = 0b11110000; // equivalent to decimal 240
    
    printf("Robot 1: %d\n", robot1);
    printf("Robot 2: %d\n", robot2);

    int and_result = robot1 & robot2;
    printf("AND Result: %d\n", and_result);

    int or_result = robot1 | robot2;
    printf("OR Result: %d\n", or_result);

    int xor_result = robot1 ^ robot2;
    printf("XOR Result: %d\n", xor_result);

    int shift_left_result = robot1 << 2;
    printf("Shift Left Result: %d\n", shift_left_result);

    int shift_right_result = robot1 >> 2;
    printf("Shift Right Result: %d\n", shift_right_result);

    int complement_result = ~robot1;
    printf("Complement Result: %d\n", complement_result);

    return 0;
}