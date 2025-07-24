//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Function to convert decimal number to hexadecimal number
void decimalToHexadecimal(int num) {
    char hex[100];
    int i = 0, rem;
    while (num != 0) {
        rem = num % 16;
        if (rem < 10) {
            hex[i++] = rem + 48;
        } else {
            hex[i++] = rem + 55;
        }
        num /= 16;
    }

    printf("Hexadecimal number is: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
}

// Function to convert hexadecimal number to decimal number
int hexadecimalToDecimal(char *hex) {
    int decimal = 0, len = strlen(hex), base = 1;

    for (int i = len - 1; i >= 0; i--) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            decimal += (hex[i] - 48) * base;
            base *= 16;
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            decimal += (hex[i] - 55) * base;
            base *= 16;
        }
    }

    return decimal;
}

int main() {
    int choice;

    do {
        printf("1. Decimal to Hexadecimal Conversion\n");
        printf("2. Hexadecimal to Decimal Conversion\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                int decimal;
                printf("\nEnter decimal number: ");
                scanf("%d", &decimal);
                decimalToHexadecimal(decimal);
                printf("\n\n");
                break;
            case 2:
                char hex[100];
                printf("\nEnter hexadecimal number: ");
                scanf("%s", hex);
                printf("Decimal number is: %d\n\n", hexadecimalToDecimal(hex));
                break;
            case 3:
                printf("Thank you for using Hexadecimal Converter!\n\n");
                exit(0);
            default:
                printf("Invalid choice!\n\n");
        }
    } while (choice != 3);

    return 0;
}