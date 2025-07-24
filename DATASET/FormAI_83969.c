//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: complete
#include <stdio.h>

void convertToHexadecimal(int decimalNumber);

int main() {
    int decimalNumber;
    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);
    convertToHexadecimal(decimalNumber);
    return 0;
}

void convertToHexadecimal(int decimalNumber) {
    int hexadecimalNumber[100];
    int i = 0, j;

    while (decimalNumber != 0) {
        int remainder = decimalNumber % 16;
        if (remainder < 10) {
            hexadecimalNumber[i] = 48 + remainder;
        } else {
            hexadecimalNumber[i] = 55 + remainder;
        }
        i++;
        decimalNumber = decimalNumber / 16;
    }

    printf("Hexadecimal number is: ");
    for (j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimalNumber[j]);
    }
}