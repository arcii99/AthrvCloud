//FormAI DATASET v1.0 Category: Binary Converter ; Style: configurable
#include <stdio.h>

// Function to convert decimal to binary
void decimalToBinary(int decimal) {
    int binary[32], i = 0;
    while (decimal > 0) {
        binary[i++] = decimal % 2;
        decimal /= 2;
    }
    // Printing binary in reverse order
    printf("Binary number: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
}

// Function to convert binary to decimal
void binaryToDecimal(int binary) {
    int decimal = 0, multiplier = 1;
    while (binary > 0) {
        decimal += (binary % 10) * multiplier;
        binary /= 10;
        multiplier *= 2;
    }
    printf("Decimal number: %d", decimal);
}

int main() {
    int choice, decimal, binary;

    printf("1. Decimal to binary conversion\n");
    printf("2. Binary to decimal conversion\n");
    printf("Enter your choice (1/2): ");
    scanf("%d", &choice);

    if (choice == 1) {
        printf("Enter decimal number: ");
        scanf("%d", &decimal);
        decimalToBinary(decimal);
    } else if (choice == 2) {
        printf("Enter binary number: ");
        scanf("%d", &binary);
        binaryToDecimal(binary);
    } else {
        printf("Invalid choice!");
    }
    return 0;
}