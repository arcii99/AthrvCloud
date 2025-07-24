//FormAI DATASET v1.0 Category: Binary Converter ; Style: Dennis Ritchie
#include <stdio.h> // Standard Input/Output library

/*
    This program converts any given decimal number to its binary representation.
    Written in Dennis Ritchie's programming style.
*/

int main() {
    int decimal_number, remainder, binary_number = 0, place = 1;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal_number);

    while (decimal_number != 0) {
        remainder = decimal_number % 2; // Get the remainder
        binary_number += remainder * place; // Multiply the remainder with its place and add it to the binary number
        decimal_number /= 2; // Divide the decimal number by 2
        place *= 10; // Increment the place by a factor of 10
    }

    printf("The binary representation of the given number is: %d\n", binary_number);

    return 0; // End the program
}