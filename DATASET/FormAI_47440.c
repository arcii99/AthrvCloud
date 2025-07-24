//FormAI DATASET v1.0 Category: Bitwise operations ; Style: cheerful
#include <stdio.h>

int main() {
    printf("Hey there! Let's play with bitwise operations!\n");
    int a = 6; // binary 0110
    int b = 9; // binary 1001
    int result;

    // AND Operator
    result = a & b;
    printf("Binary AND of %d and %d = %d\n", a, b, result);

    // OR Operator
    result = a | b;
    printf("Binary OR of %d and %d = %d\n", a, b, result);

    // XOR Operator
    result = a ^ b;
    printf("Binary XOR of %d and %d = %d\n", a, b, result);

    // Left-shift Operator
    result = a << 2; // Shift a two bits to the left
    printf("After left shifting %d by 2 bits, it becomes %d\n", a, result);

    // Right-shift Operator
    result = b >> 2; // Shift b two bits to the right
    printf("After right shifting %d by 2 bits, it becomes %d\n", b, result);

    // NOT Operator
    result = ~a;
    printf("The ones-complement of %d is %d\n", a, result);

    printf("Cool, right? But let's take it up a notch!\n");

    int num = 13; // binary 1101
    int mask = 7; // binary 0111

    // Using bitwise AND to get the last 3 bits
    int last_three_bits = num & mask;
    printf("The last three bits of %d are %d\n", num, last_three_bits);

    // Using bitwise OR to set the first 3 bits to 1
    int first_three_bits = num | (mask << 1);
    printf("After setting the first three bits of %d to 1, it becomes %d\n", num, first_three_bits);

    // Using bitwise XOR to toggle the middle 2 bits
    int middle_two_bits = num ^ 6; // binary value of 6 is 0110
    printf("After toggling the middle two bits of %d, it becomes %d\n", num, middle_two_bits);

    printf("This was so much fun! Let's do it again!\n");
    return 0;
}