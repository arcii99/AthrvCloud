//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: Claude Shannon
// This program converts decimal numbers to hexadecimal numbers
// using bitwise operators in a Claude Shannon style.

#include <stdio.h>
#include <stdlib.h>

#define MAX_DIGITS 20

int main(void) {
    int decimal, remainder, i = 0;
    char hex[MAX_DIGITS];

    printf("Please enter a decimal number:\n");
    scanf("%d", &decimal);

    while (decimal != 0) {
        remainder = decimal % 16;
        if (remainder < 10) {
            hex[i++] = remainder + '0';
        } else {
            hex[i++] = remainder - 10 + 'A';
        }
        decimal /= 16;
    }

    printf("The hexadecimal equivalent is:\n");
    for (int j = i - 1; j >= 0; j--) {
        putchar(hex[j]);
    }
    putchar('\n');

    return EXIT_SUCCESS;
}