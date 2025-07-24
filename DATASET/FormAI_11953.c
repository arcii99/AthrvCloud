//FormAI DATASET v1.0 Category: Bitwise operations ; Style: creative
#include <stdio.h>

int main() {
    int num1 = 27, num2 = 19;
    printf("The bitwise AND of %d and %d is %d\n", num1, num2, num1 & num2);
    printf("The bitwise OR of %d and %d is %d\n", num1, num2, num1 | num2);
    printf("The bitwise XOR of %d and %d is %d\n", num1, num2, num1 ^ num2);
    printf("The bitwise NOT of %d is %d\n", num1, ~num1);
    printf("The left shift of %d by 2 bits is %d\n", num1, num1 << 2);
    printf("The right shift of %d by 2 bits is %d\n", num1, num1 >> 2);

    // Let's get creative and use bitwise operations for some interesting tasks

    // Finding if a number is even or odd using bitwise AND
    int num = 15;
    if (num & 1) {
        printf("%d is odd\n", num);
    } else {
        printf("%d is even\n", num);
    }

    // Inverting the case of a character using bitwise XOR
    char ch = 'h'; // ASCII code of 'h' is 104
    ch = ch ^ 32; // 32 is the difference between ASCII codes of uppercase and lowercase letters
    printf("Inverted case of 'h' is %c\n", ch); // Output: 'H'

    // Converting a decimal number to binary using bitwise operations
    int dec = 123;
    int bin = 0, base = 1;
    while (dec > 0) {
        bin += (dec % 2) * base;
        dec /= 2;
        base *= 10;
    }
    printf("Binary representation of 123 is %d\n", bin); // Output: 1111011

    // Reversing the bits of a number using bitwise operations
    unsigned int x = 0xAAAAAAAA; // 10101010101010101010101010101010 in binary
    printf("Original value: %u\n", x);
    x = ((x >> 1) & 0x55555555) | ((x << 1) & 0xAAAAAAAA);
    x = ((x >> 2) & 0x33333333) | ((x << 2) & 0xCCCCCCCC);
    x = ((x >> 4) & 0x0F0F0F0F) | ((x << 4) & 0xF0F0F0F0);
    x = ((x >> 8) & 0x00FF00FF) | ((x << 8) & 0xFF00FF00);
    x = ((x >> 16) & 0x0000FFFF) | ((x << 16) & 0xFFFF0000);
    printf("Reversed value: %u\n", x);

    return 0;
}