//FormAI DATASET v1.0 Category: Binary Converter ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

int main() {
    int decimal, remainder, binary[100], quotient, i;

    // Prompt user for decimal number
    printf("Please enter a decimal number to convert to binary: ");
    scanf("%d", &decimal);

    // Convert decimal to binary
    quotient = decimal;
    i = 0;
    while (quotient != 0) {
        remainder = quotient % 2;
        quotient = quotient / 2;
        binary[i] = remainder;
        i++;
    }

    // Print binary result
    printf("The binary equivalent of %d is ", decimal);
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
    printf("\n");

    return 0;
}