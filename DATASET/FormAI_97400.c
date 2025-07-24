//FormAI DATASET v1.0 Category: Binary Converter ; Style: Donald Knuth
// Program to convert decimal number to binary
// Written in a Donald Knuth style

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    // Check for correct number of arguments
    if (argc != 2) {
        printf("Usage: %s <decimal_number>\n", argv[0]);
        exit(1);
    }

    // Parse input argument as decimal number
    int decimal_number = atoi(argv[1]);

    // Check for non-negative input
    if (decimal_number < 0) {
        printf("Error: input number must be non-negative.\n");
        exit(1);
    }

    // Initialize variables
    int powerOfTwo = 1;
    int binary_number = 0;
    int remainder;

    // Convert decimal number to binary
    while (decimal_number > 0) {
        remainder = decimal_number % 2;
        decimal_number = decimal_number / 2;
        binary_number = binary_number + remainder * powerOfTwo;
        powerOfTwo = powerOfTwo * 10;
    }

    // Output the binary number
    printf("The binary representation of %d is: %d\n", atoi(argv[1]), binary_number);

    // Exit program
    return 0;
}