//FormAI DATASET v1.0 Category: Hexadecimal Converter ; Style: minimalist
#include <stdio.h>

int main() {
    unsigned long decimal, quotient, remainder;
    int i, j;
    char hexadecimal[100];

    printf("Enter a decimal number: ");
    scanf("%lu", &decimal);

    quotient = decimal;
    i = 0;

    while (quotient != 0) {
        remainder = quotient % 16;
        if (remainder < 10)
            hexadecimal[i++] = 48 + remainder;
        else
            hexadecimal[i++] = 55 + remainder;
        quotient = quotient / 16;
    }

    printf("Equivalent hexadecimal number is: ");
    for (j = i - 1; j >= 0; j--)
        printf("%c", hexadecimal[j]);

    return 0;
}