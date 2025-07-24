//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    char hex_num[20];
    int decimal_num = 0, base = 1, i = 0, remainder;

    printf("Enter a hexadecimal number: ");
    scanf("%s", hex_num);

    // Converting hexadecimal to decimal
    for (i = strlen(hex_num) - 1; i >= 0; i--) {
        if (isdigit(hex_num[i])) {
            decimal_num += (hex_num[i] - 48) * base;
            base *= 16;
        }
        else if (isalpha(hex_num[i])) {
            decimal_num += (toupper(hex_num[i]) - 55) * base;
            base *= 16;
        }
    }

    printf("\nThe decimal equivalent of %s is %d.\n", hex_num, decimal_num);

    // Converting decimal to hexadecimal
    int quotient = decimal_num;
    i = 0;
    char hex_num2[20];

    while (quotient != 0) {
        remainder = quotient % 16;
        if (remainder < 10)
            hex_num2[i++] = 48 + remainder;
        else
            hex_num2[i++] = 55 + remainder;
        quotient = quotient / 16;
    }

    printf("The hexadecimal equivalent of %d is ", decimal_num);
    for (int j = i - 1; j >= 0; j--)
        printf("%c", hex_num2[j]);

    printf(".\n");

    return 0;
}