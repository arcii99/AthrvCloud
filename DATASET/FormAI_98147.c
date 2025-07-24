//FormAI DATASET v1.0 Category: Bitwise operations ; Style: single-threaded
#include <stdio.h>

int main() {
    int num1 = 10, num2 = 20;

    // Bitwise AND operator
    int bitwise_and = num1 & num2;
    printf("Bitwise AND: %d\n", bitwise_and);

    // Bitwise OR operator
    int bitwise_or = num1 | num2;
    printf("Bitwise OR: %d\n", bitwise_or);

    // Bitwise XOR operator
    int bitwise_xor = num1 ^ num2;
    printf("Bitwise XOR: %d\n", bitwise_xor);

    // Left shift operator
    int left_shift = num1 << 2;
    printf("Left Shift: %d\n", left_shift);

    // Right shift operator
    int right_shift = num2 >> 2;
    printf("Right Shift: %d\n", right_shift);

    // Ones' complement operator
    int ones_complement = ~num1;
    printf("Ones' Complement: %d\n", ones_complement);

    // Twos' complement operator
    int twos_complement = ~num1 + 1;
    printf("Twos' Complement: %d\n", twos_complement);

    // Checking if a number is even or odd using bitwise AND operator
    int num = 15;
    if (num & 1) {
        printf("%d is odd\n", num);
    } else {
        printf("%d is even\n", num);
    }

    // Checking if a number is a power of 2 using bitwise AND operator
    int power_of_2 = 16;
    if (power_of_2 & (power_of_2 - 1)) {
        printf("%d is not a power of 2\n", power_of_2);
    } else {
        printf("%d is a power of 2\n", power_of_2);
    }

    return 0;
}