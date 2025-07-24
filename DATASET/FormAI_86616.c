//FormAI DATASET v1.0 Category: Binary Converter ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

// This function converts a decimal number into binary.
void decimalToBinary(int decimal) {
    int binary[32];
    int i = 0;
    while (decimal > 0) {
        binary[i] = decimal % 2;
        decimal = decimal / 2;
        i++;
    }
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", binary[j]);
    }
}

// This function converts a binary number into decimal.
int binaryToDecimal(int binary) {
    int decimal = 0, power = 1;
    while (binary > 0) {
        if (binary % 10 == 1) {
            decimal += power;
        }
        binary = binary / 10;
        power = power * 2;
    }
    return decimal;
}

int main() {
    int choice, number;
    printf("Welcome to the Binary Converter Program! \n");
    printf("Choose an option: \n");
    printf("1. Decimal to Binary \n");
    printf("2. Binary to Decimal \n");
    printf("3. Exit \n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter a decimal number to convert to binary: ");
                scanf("%d", &number);
                printf("The binary equivalent of %d is: ", number);
                decimalToBinary(number);
                printf("\n");
                break;

            case 2:
                printf("Enter a binary number to convert to decimal: ");
                scanf("%d", &number);
                printf("The decimal equivalent of %d is: %d", number, binaryToDecimal(number));
                printf("\n");
                break;

            case 3:
                printf("Thank you for using the Binary Converter Program!");
                exit(0);

            default:
                printf("Invalid choice. Please choose 1, 2, or 3.");
                break;
        }
    }
    return 0;
}