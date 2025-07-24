//FormAI DATASET v1.0 Category: Bitwise operations ; Style: real-life
#include <stdio.h>

// Define function to convert decimal to binary
unsigned int dec2bin(int n) {
    // Initialize variables
    int remainder;
    unsigned int binary = 0, digit = 1;

    // Loop through digits of decimal and convert to binary
    while(n != 0) {
        remainder = n % 2;
        n = n / 2;
        binary = binary + remainder * digit;
        digit = digit * 10;
    }

    return binary;
}

int main() {

    // Initialize variables
    unsigned int a = 12, b = 25, result;

    // Print initial values
    printf("Initial values: a = %d, b = %d\n", a, b);

    // Performing bitwise operations to demonstrate usage
    result = a & b;
    printf("a & b = %d\n", result);
    result = a | b;
    printf("a | b = %d\n", result);
    result = a ^ b;
    printf("a ^ b = %d\n", result);
    result = ~a;
    printf("~a = %d\n", result);
    result = a << 2;
    printf("a << 2 = %d\n", result);
    result = b >> 3;
    printf("b >> 3 = %d\n", result);

    // Convert values to binary for more clarity
    printf("a in binary: %u\n", dec2bin(a));
    printf("b in binary: %u\n", dec2bin(b));
    printf("result in binary: %u\n", dec2bin(result));

    // Return success
    return 0;
}