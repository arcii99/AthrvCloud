//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: multivariable
#include <stdio.h>
#include <math.h>

int main(void) {
    unsigned long decimal_number;
    char hexadecimal_number[20];
    int remainder, quotient, i = 0;

    printf("Enter a decimal number: ");
    scanf("%lu", &decimal_number);

    quotient = decimal_number;

    while (quotient != 0) {
        remainder = quotient % 16;

        if (remainder < 10) {
            hexadecimal_number[i] = 48 + remainder;
        }
        else {
            hexadecimal_number[i] = 55 + remainder;
        }

        i++;
        quotient = quotient / 16;
    }

    printf("Hexadecimal number: ");

    for (int j = i - 1; j >= 0; j--) {
        printf("%c", hexadecimal_number[j]);
    }

    printf("\n");

    return 0;
}