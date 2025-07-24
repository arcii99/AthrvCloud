//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <stdbool.h>

#define BUFFER_SIZE 100

void convertDecimalToHexadecimal(int decimalNumber, char *hexadecimalNumber) {
    int remainder, quotient, i = 1, j;

    char hexadecimal[BUFFER_SIZE];

    quotient = decimalNumber;

    while (quotient != 0) {
        remainder = quotient % 16;

        if (remainder < 10) {
            hexadecimal[i++] = 48 + remainder;
        } else {
            hexadecimal[i++] = 55 + remainder;
        }

        quotient = quotient / 16;
    }

    for (j = i - 1; j > 0; j--) {
        sprintf(hexadecimalNumber, "%s%c", hexadecimalNumber, hexadecimal[j]);
    }
}

int main() {
    int decimalNumber;
    char hexadecimalNumber[BUFFER_SIZE];

    memset(hexadecimalNumber, 0, sizeof(hexadecimalNumber));

    printf("Enter a decimal number: ");
    scanf("%d", &decimalNumber);

    convertDecimalToHexadecimal(decimalNumber, hexadecimalNumber);

    printf("Hexadecimal equivalent of decimal number %d is '%s'\n", decimalNumber, hexadecimalNumber);

    return 0;
}