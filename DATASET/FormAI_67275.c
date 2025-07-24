//FormAI DATASET v1.0 Category: Bitwise operations ; Style: safe
#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is even or odd
bool is_even(int num) {
    return !(num & 1);
}

// Function to get the bitwise AND of two numbers
int bitwise_and(int num1, int num2) {
    return num1 & num2;
}

// Function to get the bitwise OR of two numbers
int bitwise_or(int num1, int num2) {
    return num1 | num2;
}

// Function to get the bitwise XOR of two numbers
int bitwise_xor(int num1, int num2) {
    return num1 ^ num2;
}

// Function to get the bitwise complement of a number
int bitwise_complement(int num) {
    return ~num;
}

int main() {
    int num1 = 10, num2 = 5;

    printf("is_even(num1) = %s\n", is_even(num1) ? "True" : "False");
    printf("is_even(num2) = %s\n", is_even(num2) ? "True" : "False");

    printf("bitwise_and(num1, num2) = %d\n", bitwise_and(num1, num2));
    printf("bitwise_or(num1, num2) = %d\n", bitwise_or(num1, num2));
    printf("bitwise_xor(num1, num2) = %d\n", bitwise_xor(num1, num2));

    printf("bitwise_complement(num1) = %d\n", bitwise_complement(num1));
    printf("bitwise_complement(num2) = %d\n", bitwise_complement(num2));

    return 0;
}