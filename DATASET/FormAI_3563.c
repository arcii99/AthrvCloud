//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: rigorous
#include <stdio.h>

int main() {
    unsigned long int decimal_num, quotient, remainder;
    int i, j = 0;
    char hexadecimal_num[100];

    printf("Enter a decimal number: ");
    scanf("%lu", &decimal_num);

    quotient = decimal_num;

    while (quotient != 0) {
        remainder = quotient % 16;
        if (remainder < 10)
            hexadecimal_num[j++] = 48 + remainder;
        else
            hexadecimal_num[j++] = 55 + remainder;
        quotient = quotient / 16;
    }

    printf("Hexadecimal number of %lu is: ", decimal_num);

    for (i = j; i >= 0; i--)
        printf("%c", hexadecimal_num[i]);

    printf("\n");
    return 0;
}