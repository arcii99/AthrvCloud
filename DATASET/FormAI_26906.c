//FormAI DATASET v1.0 Category: Binary Converter ; Style: safe
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

// This function converts a decimal number to binary
long decToBinary(long decimal) {
    long binary = 0;
    int remainder, i = 1;

    while (decimal != 0) {
        remainder = decimal % 2;
        decimal /= 2;
        binary += remainder * i;
        i *= 10;
    }

    return binary;
}

// This function converts a binary number to decimal
long binaryToDec(long binary) {
    long decimal = 0, tempBinary = binary;
    int count = 0, remainder;

    while (tempBinary != 0) {
        remainder = tempBinary % 10;
        tempBinary /= 10;
        decimal += remainder * pow(2, count);
        count++;
    }

    return decimal;
}

// This function checks if the input is a valid binary number
bool isValidBinary(long binary) {
    long tempBinary = binary;
    int count = 0;

    while (tempBinary != 0) {
        if (tempBinary % 10 != 0 && tempBinary % 10 != 1) {
            return false;
        }

        tempBinary /= 10;
        count++;
    }

    if (count == 0) {
        return false;
    }

    return true;
}

int main() {
    int choice;

    do {
        printf("\n\n***** BINARY CONVERTER *****\n");
        printf("1. Decimal to binary\n");
        printf("2. Binary to decimal\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                // Convert decimal to binary
                long decimal;
                printf("\nEnter decimal to convert: ");
                scanf("%ld", &decimal);

                // Call decToBinary() function to convert
                long binary = decToBinary(decimal);

                // Print the binary number
                printf("\nBinary: %ld\n", binary);

                break;

            case 2:
                // Convert binary to decimal
                printf("\nEnter binary to convert: ");
                long binaryToConvert;
                scanf("%ld", &binaryToConvert);

                // Check if the input is a valid binary number
                if (!isValidBinary(binaryToConvert)) {
                    printf("\nInvalid input! Please enter a valid binary number\n");
                    break;
                }

                // Call binaryToDec() function to convert
                long decimalNumber = binaryToDec(binaryToConvert);

                // Print the decimal number
                printf("\nDecimal: %ld\n", decimalNumber);

                break;

            case 0:
                printf("\nExiting... Thanks for using our Binary Converter!\n");
                break;

            default:
                printf("\nInvalid choice! Please choose from the menu\n");
                break;
        }
    } while (choice != 0);

    return 0;
}