//FormAI DATASET v1.0 Category: Binary Converter ; Style: grateful
#include <stdio.h>

// function to convert decimal to binary
void decimalToBinary(int decimal) {
    int binary[32], i = 0;

    while (decimal > 0) {
        binary[i] = decimal % 2;
        decimal /= 2;
        i++;
    }

    printf("The binary equivalent is: ");

    // display the binary number in reverse order
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
}

int main() {
    int decimal;

    printf("Welcome! I am a Binary Converter.\n");
    printf("Please enter a decimal number: ");
    scanf("%d", &decimal);

    decimalToBinary(decimal);

    printf("\nThank you for using Binary Converter.");
    return 0;
}