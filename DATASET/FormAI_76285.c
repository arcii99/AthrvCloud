//FormAI DATASET v1.0 Category: Bitwise operations ; Style: Sherlock Holmes
// The Case of the Missing Bits

#include <stdio.h>

int main() {
    unsigned int num1 = 0xabcd;
    unsigned int num2 = 0x3567;
    unsigned int result;

    printf("Detective, please help me out. The bits from my numbers seem to be missing.\n");
    printf("Here's number 1: %x\n", num1);
    printf("Here's number 2: %x\n", num2);

    // Let's use bitwise AND to see which bits are present in both numbers
    result = num1 & num2;
    printf("\nUsing bitwise AND, we get: %x\n", result);

    // Now we'll use bitwise OR to see which bits are present in either number
    result = num1 | num2;

    printf("\nUsing bitwise OR, we get: %x\n", result);

    // Finally, we'll use bitwise XOR to see which bits are different between the numbers
    result = num1 ^ num2;

    printf("\nUsing bitwise XOR, we get: %x\n", result);

    printf("\nAmazing, Detective! You were able to recover the missing bits and solve the case.\n");
    return 0;
}