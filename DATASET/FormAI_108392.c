//FormAI DATASET v1.0 Category: Bitwise operations ; Style: complex
#include <stdio.h>

// operator macros
#define OR |
#define AND &
#define XOR ^
#define NOT ~
#define LEFT_SHIFT <<
#define RIGHT_SHIFT >>

// function prototypes
unsigned int bitwise_AND(unsigned int, unsigned int);
unsigned int bitwise_OR(unsigned int, unsigned int);
unsigned int bitwise_XOR(unsigned int, unsigned int);
unsigned int bitwise_NOT(unsigned int);
unsigned int bitwise_LEFT_SHIFT(unsigned int, int);
unsigned int bitwise_RIGHT_SHIFT(unsigned int, int);

// main function
int main() {
    unsigned int num1 = 0x19A2;
    unsigned int num2 = 0x0FC5;
    unsigned int result;

    // bitwise AND operation
    result = bitwise_AND(num1, num2);
    printf("AND operation: %u\n", result);

    // bitwise OR operation
    result = bitwise_OR(num1, num2);
    printf("OR operation: %u\n", result);

    // bitwise XOR operation
    result = bitwise_XOR(num1, num2);
    printf("XOR operation: %u\n", result);

    // bitwise NOT operation
    result = bitwise_NOT(num1);
    printf("NOT operation: %u\n", result);

    // bitwise LEFT SHIFT operation
    result = bitwise_LEFT_SHIFT(num1, 2);
    printf("LEFT SHIFT operation: %u\n", result);

    // bitwise RIGHT SHIFT operation
    result = bitwise_RIGHT_SHIFT(num1, 2);
    printf("RIGHT SHIFT operation: %u\n", result);

    return 0;
}

// function definitions
unsigned int bitwise_AND(unsigned int num1, unsigned int num2) {
    return num1 AND num2;
}

unsigned int bitwise_OR(unsigned int num1, unsigned int num2) {
    return num1 OR num2;
}

unsigned int bitwise_XOR(unsigned int num1, unsigned int num2) {
    return num1 XOR num2;
}

unsigned int bitwise_NOT(unsigned int num) {
    return NOT num;
}

unsigned int bitwise_LEFT_SHIFT(unsigned int num, int shift) {
    return num LEFT_SHIFT shift;
}

unsigned int bitwise_RIGHT_SHIFT(unsigned int num, int shift) {
    return num RIGHT_SHIFT shift;
}