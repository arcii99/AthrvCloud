//FormAI DATASET v1.0 Category: Bitwise operations ; Style: recursive
#include <stdio.h>

// Recursive function to perform bitwise AND operation
int bitwise_and(int num1, int num2) {
    if (num1 == 0 || num2 == 0) {
        return 0;
    }
    int bit = ((num1 & num2) & 1);
    return (bit + (bitwise_and(num1/2, num2/2) * 2));
}

// Recursive function to perform bitwise OR operation
int bitwise_or(int num1, int num2) {
    if (num1 == 0 && num2 == 0) {
        return 0;
    }
    int bit = ((num1 | num2) & 1);
    return (bit + (bitwise_or(num1/2, num2/2) * 2));
}

// Recursive function to perform bitwise XOR operation
int bitwise_xor(int num1, int num2) {
    if (num1 == 0 && num2 == 0) {
        return 0;
    }
    int bit = ((num1 ^ num2) & 1);
    return (bit + (bitwise_xor(num1/2, num2/2) * 2));
}

// Recursive function to perform bitwise NOT operation
int bitwise_not(int num) {
    if (num == 0) {
        return 1;
    }
    int bit = !(num & 1);
    return (bit + (bitwise_not(num/2) * 2));
}

int main() {
    int num1 = 15;
    int num2 = 7;

    // Perform Bitwise AND operation
    int bitwise_and_result = bitwise_and(num1, num2);
    printf("Bitwise AND Result: %d\n", bitwise_and_result);

    // Perform Bitwise OR operation
    int bitwise_or_result = bitwise_or(num1, num2);
    printf("Bitwise OR Result: %d\n", bitwise_or_result);

    // Perform Bitwise XOR operation
    int bitwise_xor_result = bitwise_xor(num1, num2);
    printf("Bitwise XOR Result: %d\n", bitwise_xor_result);

    // Perform Bitwise NOT operation
    int bitwise_not_result = bitwise_not(num1);
    printf("Bitwise NOT Result of %d: %d\n", num1, bitwise_not_result);

    return 0;
}