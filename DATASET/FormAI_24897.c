//FormAI DATASET v1.0 Category: Bitwise operations ; Style: genious
#include <stdio.h>

int main() {
    int num1 = 15;
    int num2 = 3;
    int result;

    printf("Starting with num1 = %d, and num2 = %d\n\n", num1, num2);

    // Bitwise OR operator |
    result = num1 | num2;
    printf("Using the Bitwise OR operator: num1 | num2 = %d\n", result);

    // Bitwise AND operator &
    result = num1 & num2;
    printf("Using the Bitwise AND operator: num1 & num2 = %d\n", result);

    // Bitwise XOR operator ^
    result = num1 ^ num2;
    printf("Using the Bitwise XOR operator: num1 ^ num2 = %d\n", result);

    // Bitwise complement operator ~
    result = ~num1;
    printf("Using Bitwise complement operator: ~num1 = %d\n", result);

    printf("\nChanging num1 from 15 to -15 and num2 from 3 to -3\n\n");

    // Converting num1 to its 2's complement
    num1 = ~(num1 - 1);

    // Converting num2 to its 2's complement
    num2 = ~(num2 - 1);

    printf("After conversion num1 = %d and num2 = %d\n\n", num1, num2);

    // Bitwise left shift operator <<
    printf("Using the Bitwise Left Shift operator: num1 << 2 = %d\n", num1 << 2);
    printf("Using the Bitwise Left Shift operator: num2 << 2 = %d\n\n", num2 << 2);

    // Bitwise right shift operator >>
    printf("Using the Bitwise Right Shift operator: num1 >> 2 = %d\n", num1 >> 2);
    printf("Using the Bitwise Right Shift operator: num2 >> 2 = %d\n", num2 >> 2);

    return 0;
}