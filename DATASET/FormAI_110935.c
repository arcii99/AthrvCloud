//FormAI DATASET v1.0 Category: Bitwise operations ; Style: minimalist
#include <stdio.h>

// Function to print binary representation of an integer
void printBinary(unsigned int num) {
    int binary[32], i, digit;
    for (i = 0; i < 32; i++) {
        binary[i] = num % 2;
        num = num / 2;
    }
    for (i = 31; i >= 0; i--) {
        digit = binary[i];
        printf("%d", digit);
    }
    printf("\n");
}

int main() {
    // Example of bitwise OR
    unsigned int num1 = 12, num2 = 25;
    unsigned int result = num1 | num2;
    printf("Bitwise OR between %d and %d: \n", num1, num2);
    printBinary(num1);
    printBinary(num2);
    printBinary(result);

    // Example of bitwise AND
    num1 = 15, num2 = 35;
    result = num1 & num2;
    printf("Bitwise AND between %d and %d: \n", num1, num2);
    printBinary(num1);
    printBinary(num2);
    printBinary(result);

    // Example of bitwise NOT
    num1 = 10;
    result = ~num1;
    printf("Bitwise NOT of %d: \n", num1);
    printBinary(num1);
    printBinary(result);

    // Example of bitwise XOR
    num1 = 40, num2 = 23;
    result = num1 ^ num2;
    printf("Bitwise XOR between %d and %d: \n", num1, num2);
    printBinary(num1);
    printBinary(num2);
    printBinary(result);

    // Example of left shift
    num1 = 7;
    result = num1 << 2;
    printf("Left shift of %d by 2: \n", num1);
    printBinary(num1);
    printBinary(result);

    // Example of right shift
    num1 = 44;
    result = num1 >> 2;
    printf("Right shift of %d by 2: \n", num1);
    printBinary(num1);
    printBinary(result);

    return 0;
}