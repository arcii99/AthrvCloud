//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: inquisitive
#include <stdio.h>

int main() {
    int decimalNumber, quotient, remainder;
    int i, j = 0;
    char hexadecimalNumber[100];

    printf("Enter an integer in decimal number system: ");
    scanf("%d", &decimalNumber);

    quotient = decimalNumber;

    while (quotient != 0) {
        remainder = quotient % 16;
        if (remainder < 10)
            hexadecimalNumber[j++] = 48 + remainder;
        else
            hexadecimalNumber[j++] = 55 + remainder;
        quotient = quotient / 16;
    }

    printf("Equivalent hexadecimal number is: ");
    for (i = j; i >= 0; i--)
        printf("%c", hexadecimalNumber[i]);

    return 0;
}