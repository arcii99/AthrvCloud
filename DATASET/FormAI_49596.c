//FormAI DATASET v1.0 Category: Binary Converter ; Style: beginner-friendly
#include <stdio.h>

// function to convert decimal to binary using recursion
void decimalToBinary(int decimal) {
    if (decimal == 0) {
        return;
    } else {
        decimalToBinary(decimal / 2);
        printf("%d", decimal % 2);
    }
}

int main() {
    int decimal;

    // user input
    printf("Enter a decimal number: ");
    scanf("%d", &decimal);

    // check if decimal is negative
    if (decimal < 0) {
        printf("Invalid input! Decimal cannot be negative.");
    }
    else {
        printf("%d in binary is: ", decimal);
        decimalToBinary(decimal);
    }

    return 0;
}