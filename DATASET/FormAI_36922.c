//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>

// Function to convert decimal to hexadecimal
void decToHex(int dec) {
    char hex[50];
    int i = 0;
    while (dec > 0) {
        int mod = dec % 16;
        if (mod < 10) {
            hex[i++] = mod + 48;
        } else {
            hex[i++] = mod + 55;
        }
        dec /= 16;
    }
    printf("\nHexadecimal value: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hex[j]);
    }
}

int main() {
    int dec;
    printf("Welcome to the Happy Hexadecimal Converter! \n");
    printf("\nPlease enter decimal number: ");
    scanf("%d", &dec);

    if (dec < 0) {
        printf("\nOops! Can't convert negative numbers to hex. Please try again with a positive number.");
        exit(0);
    } else if (dec == 0) {
        printf("\nHexadecimal value: 0");
        exit(0);
    }

    printf("\nConverting decimal number %d to hexadecimal...", dec);
    decToHex(dec);

    printf("\n\nThank you for using the Happy Hexadecimal Converter! Enjoy your day! :)");
    return 0;
}