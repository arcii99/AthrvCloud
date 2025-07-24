//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: detailed
#include <stdio.h>

int main() {
    long decimalNumber, quotient;
    int i = 1, j, digit;
    char hexadecimalNumber[100];

    printf("Enter any decimal number: ");
    scanf("%ld", &decimalNumber);

    quotient = decimalNumber;

    while (quotient != 0) {
        digit = quotient % 16;

        if (digit < 10) {
            hexadecimalNumber[i++] = digit + 48;
        } else {
            hexadecimalNumber[i++] = digit + 55;
        }

        quotient /= 16;
    }

    printf("Hexadecimal equivalent of %ld is: ", decimalNumber);
    
    for (j = i - 1; j > 0; j--) {
        printf("%c", hexadecimalNumber[j]);
    }

    return 0;
}