//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: statistical
#include <stdio.h>

int main() {
    int decimal_number, remainder, quotient;
    char hexadecimal_number[100];
    int i, j, temp;

    printf("Enter a decimal number: ");
    scanf("%d", &decimal_number);

    quotient = decimal_number;
    i = 0;

    while (quotient != 0) {
        remainder = quotient % 16;

        if (remainder < 10)
            hexadecimal_number[i++] = remainder + 48;
        else
            hexadecimal_number[i++] = remainder + 55;

        quotient = quotient / 16;
    }

    printf("Hexadecimal number of %d is: ", decimal_number);

    for (j = i - 1; j >= 0; j--)
        printf("%c", hexadecimal_number[j]);

    return 0;
}