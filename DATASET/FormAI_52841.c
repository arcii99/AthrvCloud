//FormAI DATASET v1.0 Category: Binary Converter ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_BITS 32

int main() {
    printf("Welcome to the Binary Converter program!");
    printf("\n\n");

    // Ask user for input number
    int number;
    printf("Enter a positive number: ");
    scanf("%d", &number);

    // Initialize binary array
    int binary[MAX_BITS];
    for (int i = 0; i < MAX_BITS; i++) {
        binary[i] = 0;
    }

    // Convert to binary
    int index = 0;
    while (number > 0 && index < MAX_BITS) {
        binary[index++] = number % 2;
        number = number / 2;
    }

    // Output binary number
    printf("The binary representation of the input number is: ");
    for (int i = MAX_BITS - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }

    printf("\n\n");
    printf("Thank you for using the Binary Converter program!");
    printf("\n");

    return EXIT_SUCCESS;
}