//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: ultraprecise
#include<stdio.h>

int main() {
    long int decimal_number, quotient, remainder;
    int i, j = 0;
    char hexadecimal_number[100];

    printf("Enter decimal number: ");
    scanf("%ld", &decimal_number);

    quotient = decimal_number;

    while (quotient != 0) {
        remainder = quotient % 16;

        if (remainder < 10)
            hexadecimal_number[j++] = 48 + remainder;
        else
            hexadecimal_number[j++] = 55 + remainder;

        quotient /= 16;
    }

    printf("Hexadecimal number is: ");

    for (i = j; i >= 0; i--)
        printf("%c", hexadecimal_number[i]);

    return 0;
}