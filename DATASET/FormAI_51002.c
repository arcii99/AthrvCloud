//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: random
#include <stdio.h>

int main() {
    int decimal_number, quotient, remainder, i = 0;
    char hexadecimal_number[100];

    printf("Enter a decimal number: ");
    scanf("%d", &decimal_number);

    quotient = decimal_number;

    while (quotient != 0) {
        remainder = quotient % 16;

        if (remainder < 10)
            hexadecimal_number[i++] = 48 + remainder;
        else
            hexadecimal_number[i++] = 55 + remainder;

        quotient /= 16;
    }

    printf("\nHexadecimal number of %d is: \n", decimal_number);

    for (int j = i - 1; j >= 0; j--)
        printf("%c", hexadecimal_number[j]);

    printf("\n\n");

    return 0;
}